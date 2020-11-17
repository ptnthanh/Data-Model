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
void join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]) {
	CDHLIST cdh;
	CRLIST cr;

	int index;

	for (int i = 0; i < TABLE_SIZE; i++) {
		cdh = cdh_table[i];

		if (cdh->course != NULL) {
			index = hashString(cdh->course);
			cr = cr_table[index];
			while (cr->next != NULL) {
				printf("%s\t%s\t%s\t%s\n", cr->course, cr->room, cdh->day, cdh->hour);
				cr = cr->next;
			}
			printf("%s\t%s\t%s\t%s\n", cr->course, cr->room, cdh->day, cdh->hour);
		}
	}
}

// 8.15: From CRDH
//		1.  Select Room = "Turing Aud.,"
//		2.  Project onto attributes Day & Hour
void join_select_project_CRDH(char* room, CDHLIST cdh_table[], CRLIST cr_table[]) {
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
