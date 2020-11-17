/*
 * algebra.c
 *
 *  Created on: Nov 15, 2020
 *      Author: thanhpham
 */

#include "algebra.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 8.12: Select tuples with courseName from CSG
CSGLIST* select_CSG(char* course, CSGLIST csg_table[]) {
	CSGLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = csg_table[i];
		while (curr != NULL) {
			if (curr->course != course) {
				curr->course = NULL;
				curr->studentId  = 0;
				curr->grade = NULL;
			}
			curr = curr->next;
		}
	}
	return csg_table;
}

// 8.13: Project StudentID of students taking courseName from CSG

void project_CSG(char* course, CSGLIST csg_table[]) {
	CSGLIST* res = select_CSG(course, csg_table);
	CSGLIST curr;

	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = res[i];
		while (curr != NULL) {
			if (curr->studentId != 0)
				printf("%d\n", curr->studentId);
			curr = curr->next;
		}
	}
}

// 8.14: Join CDH and CR --> CRDH
CRDHLIST* join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]) {
	CRDHLIST* res = (CRDHLIST*)malloc(TABLE_SIZE * sizeof(CRDHLIST));
	CDHLIST cdh;
	CRLIST cr;
	CRDHLIST joined = (CRDHLIST)malloc(sizeof(CRDH));
	joined->course = (char*) malloc(7 * sizeof(char));
	joined->day = (char*) malloc(2 * sizeof(char));
	joined->hour = (char*) malloc(5 * sizeof(char));
	joined->room = (char*) malloc(30 * sizeof(char));

	int index;

	for (int i = 0; i < TABLE_SIZE; i++) {
		cdh = cdh_table[i];

		if (cdh->course != NULL) {
			char* course = cdh->course;
			index = hashString(course);
			cr = cr_table[index];

			while (cr != NULL) {
				//printf("%s, %s\n", cr->course, cr->room);
//				joined->course = course;
//				joined->room = cr->room;
//				joined->day = cdh->day;
//				joined->hour = cdh->hour;
				//CRDHLIST temp = res[index];

				//res[index] = joined;

				printf("%s\t%s\t%s\t%s\n", course, cr->room, cdh->day, cdh->hour);
				//printf("%s\t%s\t%s\t%s\n", res[index]->course, res[index]->room, res[index]->day, res[index]->hour);


				cr = cr->next;
			}
//			joined->course = course;
//			joined->room = cr->room;
//			joined->day = cdh->day;
//			joined->hour = cdh->hour;
//
//			res[index]->next = joined;
			printf("%s\t%s\t%s\t%s\n", course, cr->room, cdh->day, cdh->hour);
		}

	}
	return res;
}

//CRDHLIST join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]) {
//	CRDHLIST res = malloc(TABLE_SIZE * sizeof(CRDH));
//	for (int i = 0; i < 1009; i++) {
//		CRDHLIST joined = (CRDHLIST)malloc(sizeof(CRDH));
//		joined->course = (char*) malloc(7 * sizeof(char));
//		joined->day = (char*) malloc(2 * sizeof(char));
//		joined->hour = (char*) malloc(5 * sizeof(char));
//		joined->room = (char*) malloc(30 * sizeof(char));
//
//		CDHLIST cdh = cdh_table[i];
//
//		if (cdh->course != NULL) {
//			char* course = cdh->course;
//			CRLIST cr;
//
//			for (int j = 0; j < 1009; j++) {
//				if (cr_table[j] != NULL) {
//					if (cr_table[j]->course != NULL) {
//						if (cr_table[j]->course == course) {
//							cr = cr_table[j];
//						}
//					}
//				}
//			}
//
//			while (cr != NULL) {
//				joined->course = cdh->course;
//				joined->room = cr->room;
//				joined->day = cdh->day;
//				joined->hour = cdh->hour;
//				cr = cr->next;
//			}
//		}
//		if (joined->course != NULL) {
//			res[i] = *joined;
//		}
//
//	}
//	return res;
//}

// 8.15: From CRDH
//		1.  Select Room = "Turing Aud.,"
//		2.  Project onto attributes Day & Hour

void alternative(char* room, CDHLIST cdh_table[], CRLIST cr_table[]) {
	CDHLIST cdh;
	CRLIST cr;
	int index;

	for (int i = 0; i < TABLE_SIZE; i++) {
		cdh = cdh_table[i];
		if (cdh->course != NULL) {
			index = hashString(cdh->course);
			cr = cr_table[index];
			while(cr != NULL) {
				if (cr->room == room) {
					printf("%s\t%s\n", cdh->day, cdh->hour);
				}
				cr = cr->next;
			}
		}
	}
}

//CRDHLIST select_CRDH(char* room, CRDHLIST table) {
//	CRDH curr;
//	for (int i = 0; i < TABLE_SIZE; i++) {
//		curr = table[i];
//		while (curr.room != NULL) {
//			if (curr.room != room) {
//				curr.course = NULL;
//				curr.room = NULL;
//				curr.day = NULL;
//				curr.hour = NULL;
//			}
//			curr = *curr.next;
//		}
//	}
//	return table;
//}
//
//void project_CRDH(char* room, CRDHLIST table) {
//	CRDHLIST res = select_CRDH(room, table);
//	CRDH curr;
//	for (int i = 0; i < TABLE_SIZE; i++) {
//		curr = res[i];
//		while (curr.room != NULL) {
//			if (curr.room != NULL) {
//				printf("%s\t%s\n", curr.day, curr.hour);
//			}
//			curr = *curr.next;
//		}
//	}
//}
