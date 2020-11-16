/*
 * main.c
 *
 *  Created on: Nov 14, 2020
 *      Author: thanhpham
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "relations.h"
#include "part2.h"

int main (int argc, char *argv[]) {

	printf("\n\t*** CSG: Course - Student ID - Grade ***\n");

	CSGLIST CSG_table[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++) {
		CSG_table[i] = (CSGLIST)malloc(sizeof(CSG));
		CSG_table[i]->next = NULL;
	}
	CSG csg;
	csg.next = NULL;
	csg.course = "CS101";
	csg.studentId = 12345;
	csg.grade = "A";
	insert_CSG(csg, CSG_table, true);

	csg.studentId = 67890;
	csg.grade = "B";
	insert_CSG(csg, CSG_table, true);

	csg.course = "EE200";
	csg.studentId = 12345;
	csg.grade = "C";
	insert_CSG(csg, CSG_table, true);

	csg.studentId = 22222;
	csg.grade = "B+";
	insert_CSG(csg, CSG_table, true);

	csg.course = "CS101";
	csg.studentId = 33333;
	csg.grade = "A-";
	insert_CSG(csg, CSG_table, true);

	csg.course = "PH100";
	csg.studentId = 67890;
	csg.grade = "C+";
	insert_CSG(csg, CSG_table, true);

	printf("All tuples in CSG:\n");
	print_CSG(CSG_table);

	printf("\n\t*** SNAP: Student ID - Name - Address - Phone ***\n");
	SNAPLIST SNAP_table[TABLE_SIZE];
	for (int j = 0; j < TABLE_SIZE; j++) {
		SNAP_table[j] = (SNAPLIST)malloc(sizeof(SNAP));
		SNAP_table[j]->next = NULL;
	}

	SNAP snap;
	snap.next = NULL;
	snap.studentId = 12345;
	snap.name = "C. Brown";
	snap.address = "12 Apple St.";
	snap.phone = "555-1234";
	insert_SNAP(snap, SNAP_table, true);

	snap.studentId = 67890;
	snap.name = "L. Van Pelt";
	snap.address = "34 Pear Ave.";
	snap.phone = "555-5678";
	insert_SNAP(snap, SNAP_table, true);

	snap.studentId = 22222;
	snap.name = "P. Patty";
	snap.address = "56 Grape Blvd.";
	snap.phone = "555-9999";
	insert_SNAP(snap, SNAP_table, true);

	printf("All tuples in SNAP relation:\n");
	print_SNAP(SNAP_table);

	printf("\n\t*** CP: Course - Prerequisite ***\n");
	CPLIST CP_table[TABLE_SIZE];
	for (int k = 0; k < TABLE_SIZE; k++) {
		CP_table[k] = (CPLIST)malloc(sizeof(CP));
		CP_table[k]->next = NULL;
	}

	CP cp;
	cp.next = NULL;
	cp.course = "CS101";
	cp.prereq = "CS100";
	insert_CP(cp, CP_table, true);

	cp.course = "EE200";
	cp.prereq = "EE005";
	insert_CP(cp, CP_table, true);

	cp.course = "EE200";
	cp.prereq = "CS100";
	insert_CP(cp, CP_table, true);

	cp.course = "CS120";
	cp.prereq = "CS101";
	insert_CP(cp, CP_table, true);

	cp.course = "CS121";
	cp.prereq = "CS120";
	insert_CP(cp, CP_table, true);

	cp.course = "CS205";
	cp.prereq = "CS101";
	insert_CP(cp, CP_table, true);

	cp.course = "CS206";
	cp.prereq = "CS121";
	insert_CP(cp, CP_table, true);

	cp.course = "CS206";
	cp.prereq = "CS205";
	insert_CP(cp, CP_table, true);

	printf("All tuples in CP: \n");
	print_CP(CP_table);

	printf("\n\t*** CDH: Course - Day - Hour ***\n");
	CDHLIST CDH_table[TABLE_SIZE];
	for (int x = 0; x < TABLE_SIZE; x++) {
		CDH_table[x] = (CDHLIST)malloc(sizeof(CDH));
		CDH_table[x]->next = NULL;
	}
	CDH cdh;
	cdh.next = NULL;
	cdh.course = "CS101";
	cdh.day = "M";
	cdh.hour = "9AM";
	insert_CDH(cdh, CDH_table, true);

	cdh.day = "W";
	insert_CDH(cdh, CDH_table, true);

	cdh.day = "F";
	insert_CDH(cdh, CDH_table, true);

	cdh.course = "EE200";
	cdh.day = "Tu";
	cdh.hour = "10AM";
	insert_CDH(cdh, CDH_table, true);

	cdh.day = "W";
	cdh.hour = "1PM";
	insert_CDH(cdh, CDH_table, true);

	cdh.day = "Th";
	cdh.hour = "10AM";
	insert_CDH(cdh, CDH_table, true);

	printf("All tuples in CDH: \n");
	print_CDH(CDH_table);

	printf("\n\t*** CR: Course - Room ***\n");
	CRLIST CR_table[TABLE_SIZE];
	for (int y = 0; y < TABLE_SIZE; y++) {
		CR_table[y] = (CRLIST)malloc(sizeof(CR));
		CR_table[y]->next = NULL;
	}
	CR cr;
	cr.next = NULL;
	cr.course = "CS101";
	cr.room = "Turing Aud.";
	insert_CR(cr, CR_table, true);

	cr.course = "EE200";
	cr.room = "25 Ohm Hall";
	insert_CR(cr, CR_table, true);

	cr.course = "PH100";
	cr.room = "Newton Lab";
	insert_CR(cr, CR_table, true);

	printf("All tuples in CR: \n");
	print_CR(CR_table);

	//Operations in Example 8.2

	printf("\n\t *** Part 2 ***\n");
	char* grade = getGrade("L. Van Pelt", "CS101", SNAP_table, CSG_table);
	printf("%s\n", grade);

	char* room = getRoom("C. Brown", "10AM", "Tu", CSG_table, CR_table, SNAP_table, CDH_table);
	printf("Room %s\n", room);
}
