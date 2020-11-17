/*
 * csg.c
 *
 *  Created on: Nov 14, 2020
 *      Author: thanhpham
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "relations.h"

int TABLE_SIZE = 1009;

// Hashing

int stringToInt(char* str) {
	int step = sizeof(char);
	int returner = 0;

	for (int i = 0; i < strlen(str); i++) {
		int adder = (int) str[0];
		returner += adder;
		str += step;
	}
		return returner;
}

int hashInt(int x) {
	return (x % TABLE_SIZE);
}

int hashString(char* str) {
	char* start = &str[0];
	int string = stringToInt(start);
	return (string % TABLE_SIZE);
}

int hashIntAndString(int id, char* course) {
	char* start = &course[0];
	int str = stringToInt(start);
	return ((id + str) % TABLE_SIZE);
}

int hashTwoStrings(char* s1, char* s2) {
	char* start1 = &s1[0];
	int st1 = stringToInt(start1);

	char* start2 = &s2[0];
	int st2 = stringToInt(start2);

	return ((st1 + st2) % TABLE_SIZE);
}

// CSG

void print_CSG(CSGLIST table[]) {
	CSGLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->studentId != 0) {
			printf("(%s, %d, %s)\n", curr->course, curr->studentId, curr->grade);
			while (curr->next != NULL) {
				curr = curr->next;
				printf("(%s, %d, %s)\n", curr->course, curr->studentId, curr->grade);
			}
		}
	}
}

CSGLIST lookup_CSG(CSG csg, CSGLIST table[], bool print) {
	int code = hashIntAndString(csg.studentId, csg.course);
	CSGLIST this = table[code];

	while (this != NULL) {
		if (this->course == csg.course && this->studentId == csg.studentId) {
			if (print)
				printf("Tuple (%s, %d, %s) in CSG was found at index %d.\n", csg.course, csg.studentId, csg.grade, code);
			return this;
		}
		this = this->next;
	}

	if (print)
		printf("Tuple (%s, %d, %s) could not be found in CSG.\n", csg.course, csg.studentId, csg.grade);
	return NULL;

}

void insert_CSG(CSG csg, CSGLIST table[], bool print) {
	int code = hashIntAndString(csg.studentId, csg.course);

	if (lookup_CSG(csg, table, false) != NULL) {
		if (print)
			printf("Tuple (%s, %d, %s) already in the relation.\n", csg.course, csg.studentId, csg.grade);
		return;
	}
	else {
		CSGLIST this = table[code];
		while (this->next != NULL) {
			this = this->next;
		}

		CSGLIST new = (CSGLIST)malloc(sizeof(CSG));
		if (this->course != NULL) {
			this->next = new;
			this = new;
		}
		memcpy(this, &csg, sizeof(CSG));
		if (print)
			printf("Tuple (%s, %d, %s) has been inserted into CSG.\n", csg.course, csg.studentId, csg.grade);
		return;
	}

}

void delete_CSG(CSG csg, CSGLIST table[], bool print) {
	int code = hashIntAndString(csg.studentId, csg.course);
	CSGLIST this = table[code];

	while (this != NULL) {
		if (this->course == csg.course && this->studentId == csg.studentId && this->grade == csg.grade) {
			this->course = NULL;
			this->studentId = 0;
			this->grade = NULL;
			if (print)
				printf("Tuple (%s, %d, %s) was deleted from CSG.\n", csg.course, csg.studentId, csg.grade);
			return;
		}
		this = this->next;
	}

	if (print)
		printf("Tuple (%s, %d, %s) was not in CSG.\n", csg.course, csg.studentId, csg.grade);

}

// SNAP

void print_SNAP(SNAPLIST table[]) {
	SNAPLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->studentId != 0) {
			printf("(%d, %s, %s, %s)\n", curr->studentId, curr->name, curr->address, curr->phone);
			while (curr->next != NULL) {
				curr = curr->next;
				printf("(%d, %s, %s, %s)\n", curr->studentId, curr->name, curr->address, curr->phone);
			}
		}
	}
}

SNAPLIST lookup_SNAP(SNAP snap, SNAPLIST table[], bool print) {
	int code = hashInt(snap.studentId);
	SNAPLIST this = table[code];

	while (this != NULL) {
		if (this->studentId==snap.studentId && this->name==snap.name && this->address==snap.address && this->phone==snap.phone) {
			if (print)
				printf("Tuple (%d, %s, %s, %s) was found at index %d.\n", snap.studentId, snap.name, snap.address, snap.phone, code);
			return this;
		}
		this = this->next;
	}

	if (print)
		printf("Tuple (%d, %s, %s, %s) could not be found in SNAP.\n", snap.studentId, snap.name, snap.address, snap.phone);
	return NULL;
}

void insert_SNAP(SNAP snap, SNAPLIST table[], bool print) {
	int code = hashInt(snap.studentId);

	if (lookup_SNAP(snap, table, false) != NULL) {
		if (print)
			printf("Tuple (%d, %s, %s, %s) already in SNAP.\n", snap.studentId, snap.name, snap.address, snap.phone);
		return;
	} else {
		SNAPLIST this = table[code];
		while (this->next != NULL) {
			this = this->next;
		}

		SNAPLIST new = (SNAPLIST)malloc(sizeof(SNAP));
		if (this->studentId != 0) {
			this->next = new;
			this = new;
		}
		memcpy(this, &snap, sizeof(SNAP));

		if (print)
			printf("Tuple (%d, %s, %s, %s) has been inserted into SNAP.\n", snap.studentId, snap.name, snap.address, snap.phone);
		return;
	}

}

void delete_SNAP(SNAP snap, SNAPLIST table[], bool print) {
	int code = hashInt(snap.studentId);
	SNAPLIST this = table[code];

	while (this != NULL) {
		if (this->studentId == snap.studentId) {
			this->studentId = 0;
			this->name = NULL;
			this->address = NULL;
			this->phone = NULL;
			if (print)
				printf("Tuple (%d, %s, %s, %s) was deleted from SNAP.\n", snap.studentId, snap.name, snap.address, snap.phone);
			return;
		}
		this = this->next;
	}
	if (print)
		printf("Tuple (%d, %s, %s, %s) was not in SNAP.\n", snap.studentId, snap.name, snap.address, snap.phone);
}

// CP
void print_CP(CPLIST table[]) {
	CPLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->course != NULL) {
			printf("(%s, %s)\n", curr->course, curr->prereq);
			while (curr->next != NULL) {
				curr = curr->next;
				printf("(%s, %s)\n", curr->course, curr->prereq);
			}
		}
	}
}

void insert_CP(CP cp, CPLIST table[], bool print) {
	int code = hashTwoStrings(cp.course, cp.prereq);

	if (lookup_CP(cp, table, false) != NULL) {
		if (print)
			printf("Tuple (%s, %s) already in CP.\n", cp.course, cp.prereq);
		return;
	}
	else {
		CPLIST this = table[code];
		while (this->next != NULL) {
			this = this->next;
		}

		CPLIST new = (CPLIST)malloc(sizeof(CP));
		if (this->course != NULL) {
			this->next = new;
			this = new;
		}
		memcpy(this, &cp, sizeof(CP));

		if (print)
			printf("Tuple (%s, %s) has been inserted into CP.\n", cp.course, cp.prereq);
		return;
	}
}

void delete_CP(CP cp, CPLIST table[], bool print) {
	int code = hashTwoStrings(cp.course, cp.prereq);
	CPLIST this = table[code];

	while (this != NULL) {
		if (this->course == cp.course && this->prereq == cp.prereq) {
			this->course = NULL;
			this->prereq = NULL;
			if (print)
				printf("Tuple (%s, %s) has been deleted from CP.\n", cp.course, cp.prereq);
			return;
		}
		this = this->next;
	}

	if (print)
		printf("Tuple (%s, %s) was not in CP.\n", cp.course, cp.prereq);
	return;
}

CPLIST lookup_CP(CP cp, CPLIST table[], bool print) {
	int code = hashTwoStrings(cp.course, cp.prereq);
	CPLIST this = table[code];

	while (this != NULL) {
		if (this->course == cp.course && this->prereq == cp.prereq) {
			if (print)
				printf("Tuple (%s, %s) was found at index %d.\n", cp.course, cp.prereq, code);
			return this;
		}
		this = this->next;
	}

	if (print)
		printf("Tuple (%s, %s) could not be found in CP.\n", cp.course, cp.prereq);
	return NULL;
}

// CDH
void print_CDH(CDHLIST table[]) {
	CDHLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->course != NULL) {
			printf("(%s, %s, %s)\n", curr->course, curr->day, curr->hour);
			while (curr->next != NULL) {
				curr=curr->next;
				printf("(%s, %s, %s)\n", curr->course, curr->day, curr->hour);
			}
		}
	}
}

void insert_CDH(CDH cdh, CDHLIST table[], bool print) {
	int code = hashTwoStrings(cdh.course, cdh.day);
	if (lookup_CDH(cdh, table, false) != NULL) {
		if (print)
			printf("Tuple (%s, %s, %s) already in CDH.\n", cdh.course, cdh.day, cdh.hour);
		return;
	}
	else {
		CDHLIST this = table[code];
		while (this->next != NULL) {
			this = this->next;
		}
		CDHLIST new = (CDHLIST)malloc(sizeof(CDH));
		if (this->course != NULL) {
			this->next = new;
			this = new;
		}
		memcpy(this, &cdh, sizeof(CDH));
		if (print) {
			printf("Tuple (%s, %s, %s) has been inserted into CDH.\n", cdh.course, cdh.day, cdh.hour);
		}
	}
}

void delete_CDH(CDH cdh, CDHLIST table[], bool print) {
	int code = hashTwoStrings(cdh.course, cdh.day);
	CDHLIST this = table[code];

	while (this != NULL) {
		if (this->course == cdh.course && this->day == cdh.day) {
			this->course = NULL;
			this->hour = NULL;
			this->day = NULL;
			if (print)
				printf("Tuple (%s, %s, %s) has been deleted from CDH.\n", cdh.course, cdh.day, cdh.hour);
			return;
		}
		this = this->next;
	}
	if (print) {
		printf("Tuple (%s, %s, %s) was not in CDH.\n", cdh.course, cdh.day, cdh.hour);
	}
}

CDHLIST lookup_CDH(CDH cdh, CDHLIST table[], bool print) {
	int code = hashTwoStrings(cdh.course, cdh.day);
	CDHLIST this = table[code];

	while (this != NULL) {
		if (this->course == cdh.course && this->day == cdh.day) {
			if (print)
				printf("Tuple (%s, %s, %s) was found at index %d.\n", cdh.course, cdh.day, cdh.hour, code);
			return this;
		}
		this = this->next;
	}
	if (print)
		printf("Tuple (%s, %s, %s) could not be found in CDH.\n", cdh.course, cdh.day, cdh.hour);
	return NULL;
}

//CR
void print_CR(CRLIST table[]) {
	CRLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->course != NULL) {
			printf("(%s, %s)\n", curr->course, curr->room);
			while (curr->next != NULL) {
				curr = curr->next;
				printf("(%s, %s)\n", curr->course, curr->room);
			}
		}
	}
}

void insert_CR(CR cr, CRLIST table[], bool print) {
	int code = hashString(cr.course);
	if (lookup_CR(cr, table, false) != NULL) {
		if (print)
			printf("Tuple (%s, %s) is already in CR.\n", cr.course, cr.room);
		return;
	} else {
		CRLIST this = table[code];
		while (this->next != NULL) {
			this = this->next;
		}
		CRLIST new = (CRLIST)malloc(sizeof(CR));
		if (this->course != NULL) {
			this->next = new;
			this = new;
		}
		memcpy(this, &cr, sizeof(CR));
		if (print)
			printf("Tuple (%s, %s) has been inserted to CR.\n", cr.course, cr.room);
	}
}

void delete_CR(CR cr, CRLIST table[], bool print) {
	int code = hashString(cr.course);
	CRLIST this = table[code];

	while (this != NULL) {
		if (this->course == cr.course) {
			char* c = this->course;
			char* r = this->room;
			this->course = NULL;
			this->room = NULL;
			if (print) printf("Tuple (%s, %s) has been deleted from CR.\n", c, r);
			return;
		}
		this = this->next;
	}

	if (print) printf("Tuple (%s, %s) was not in CR.\n", cr.course, cr.room);

}

CRLIST lookup_CR(CR cr, CRLIST table[], bool print) {
	int code = hashString(cr.course);
	CRLIST this = table[code];
	while (this != NULL) {
		if (this->course == cr.course && this->room == cr.room) {
			if (print)
				printf("Tuple (%s, %s) was found at index %d.\n", cr.course, cr.room, code);
			return this;
		}
		this = this->next;
	}
	if (print)
		printf("Tuple (%s, %s) could not be found in CR.\n", cr.course, cr.room);
	return NULL;
}

// CRDH
//CRDH new_CRDH(char* c, char* r, char* d, char* h) {
//	CRDH crdh = (CRDH)malloc(sizeof(CRDH));
//	crdh.course = c;
//	crdh.room = r;
//	crdh.day = d;
//	crdh.hour = h;
//	crdh.next = NULL;
//	return crdh;
//}

void print_CRDH(CRDHLIST table[]) {
	CRDHLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = table[i];
		if (curr->course != NULL) {
			printf("(%s\t%s\t%s\t%s)\n", curr->course, curr->room, curr->day, curr->hour);
			while (curr->next != NULL) {
				curr = curr->next;
				printf("%s\t%s\t%s\t%s\n", curr->course, curr->room, curr->day, curr->hour);
			}
		}
	}
}

//void insert_CRDH(CRDHLIST crdh, CRDHLIST table[], bool print) {
//	int code = hashString(crdh->course);
//	if (lookup_CRDH(crdh, table, false) != NULL) {
//		if (print)
//			printf("Tuple (%s, %s, %s, %s) is already in CRDH.\n", crdh->course, crdh->room, crdh->day, crdh->hour);
//		return;
//	} else {
//		CRDHLIST this = table[code];
//		while (this->next != NULL) {
//			this = this->next;
//		}
//		CRDHLIST new = (CRDHLIST)malloc(sizeof(CRDH));
//		if (this->course != NULL) {
//			this->next = new;
//			this = new;
//		}
//	}
//}
//
//CRDHLIST lookup_CRDH(CRDHLIST crdh, CRDHLIST table[], bool print) {
//	int code = hashString(crdh->course);
//	CRDHLIST this = table[code];
//	while (this != NULL) {
//		if (this->course == crdh->course) {
//			if (print)
//				printf("Tuple (%s, %s, %s, %s) was found at index %d.\n", crdh->course, crdh->room, crdh->day, crdh->hour, code);
//			return this;
//		}
//		this = this->next;
//	}
//	if (print)
//		printf("Tuple (%s, %s, %s, %s) could not be found in CRDH.\n", crdh->course, crdh->room, crdh->day, crdh->hour);
//	return NULL;
//}
