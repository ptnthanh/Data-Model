#include "part2.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*	What grade did StudentName get in CourseName?
 *  for each tuple t in StudentId-Name-Address-Phone do
 *		if t has “C. Brown” in its Name component then begin
 *			let i be the StudentId component of tuple t;
 *			for each tuple s in Course-StudentId-Grade do
 *				if s has Course component “CS101” and StudentId component i then
 *					print the Grade component of tuple s;
 */

char* getGrade(char* name, char* course, SNAPLIST snap_table[], CSGLIST csg_table[]) {
	SNAPLIST curr;
	for (int i = 0; i < TABLE_SIZE; i++) {
		curr = snap_table[i];
		if (curr->name  == name) {
			int id = curr->studentId;
			for (int j = 0; j < TABLE_SIZE; j++) {
				CSGLIST csg = csg_table[j];
				if (csg->course == course && csg->studentId == id)
					return csg->grade;
			}
		}
	}
	return NULL;
}

void REPL_getGrade(SNAPLIST snap_table[], CSGLIST csg_table[]) {
	char name[30];
	char course[6];
	while (strcmp("quit", name) != 0 && strcmp("quit", name) != 0) {
		printf("Enter student name (\"quit\" to quit): ");
		//fgets(name, 30, stdin);
		scanf("%s[^\n]", name);
		if (strcmp("quit", name) == 0) {
			break;
		}
		printf("Enter course name (\"quit\" to quit): ");
		//fgets(course, 6, stdin);
		scanf("%s[^\n]", course);
		if (strcmp("quit", course) == 0) {
			break;
		}
		printf("%s)\n", name);
		printf("%s)\n", course);
		printf("%s\n", getGrade(name, course, snap_table, csg_table));
		if (getGrade(name, course, snap_table, csg_table) != NULL) {
			printf("What grade did %s get in %s? --> %s\n", name, course,
					getGrade(name, course, snap_table, csg_table));
		} else {
			printf("What grade did %s get in %s? --> No grade found.\n", name, course);
		}
	}
}

// Where is StudentName at Time on Day?
char* getRoom(char* name, char* time, char* day, CSGLIST csg_table[], CRLIST cr_table[], SNAPLIST snap_table[], CDHLIST cdh_table[]) {
	SNAPLIST snap;
	for (int i = 0; i < TABLE_SIZE; i++) {
		snap = snap_table[i];
		if (snap->name == name) {
			int id = snap->studentId;
			for (int j = 0; j < TABLE_SIZE; j++) {
				CSGLIST csg = csg_table[j];
				if (csg->studentId == id) {
					char* course =  csg->course;
					for (int k = 0; k < TABLE_SIZE; k++) {
						CDHLIST cdh = cdh_table[k];
						if (cdh->day == day && cdh->hour == time && cdh->course == course) {
							for (int l = 0; l < TABLE_SIZE; l++) {
								CRLIST cr = cr_table[l];
								if (cr->course == course)
									return cr->room;
							}
						}
					}
				}
			}
		}
	}
	return NULL;
}

void REPL_getRoom(CSGLIST csg_table[], CRLIST cr_table[], SNAPLIST snap_table[], CDHLIST cdh_table[]) {
	char name[30];
	char time[4];
	char day[2];
	while (strcmp("quit", name) != 0 && strcmp("quit", name) != 0) {
		printf("Enter student name (\"quit\" to quit): ");
		fgets(name, 30, stdin);
		if (strcmp("quit", name) == 0) {
			break;
		}
		printf("Enter the day (\"quit\" to quit): ");
		fgets(day, 2, stdin);
		if (strcmp("quit", day) == 0) {
			break;
		}
		printf("Enter the time (\"quit\" to quit): ");
		fgets(time, 4, stdin);
		if (strcmp("quit", time) == 0) {
			break;
		}
		if (getRoom(name, time, day, csg_table, cr_table, snap_table, cdh_table) != NULL) {
			printf("Where is %s at %s on %s? --> %s\n", name, time, day,
					getRoom(name, time, day, csg_table, cr_table, snap_table, cdh_table));
		} else {
			printf("Where is %s at %s on %s? --> No room found.", name, time, day);
		}
	}
}

