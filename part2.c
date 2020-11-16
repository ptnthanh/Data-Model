/*
 * part2.c
 *
 *  Created on: Nov 15, 2020
 *      Author: thanhpham
 */

#include "part2.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
