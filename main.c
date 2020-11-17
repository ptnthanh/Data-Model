#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "relations.h"
#include "part2.h"
#include "algebra.h"

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

	printf("\nAll tuples in CSG:\n");
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

	printf("\nAll tuples in SNAP:\n");
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

	printf("\nAll tuples in CP: \n");
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

	printf("\nAll tuples in CDH: \n");
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

	printf("\nAll tuples in CR: \n");
	print_CR(CR_table);


	printf("\n\t *** Part 2 ***\n");
	printf("\nWhat grade did StudentName get in CourseName?\n");
	printf("Grade L. Van Pelt get in CS101 --> ");
	char* grade = getGrade("L. Van Pelt", "CS101", SNAP_table, CSG_table);
	printf("%s \n", grade);

	printf("Grade P. Patty get in EE200? --> ");
	grade = getGrade("P. Patty", "EE200", SNAP_table, CSG_table);
	printf("%s \n", grade);

	printf("Grade C. Brown get in EE200? --> ");
	grade = getGrade("C. Brown", "EE200", SNAP_table, CSG_table);
	printf("%s \n", grade);

	//REPL_getGrade(SNAP_table, CSG_table);

	printf("\nWhere is StudentName at Time on Day?\n");
	printf("C. Brown at 10AM on Tuesday --> ");
	char* room = getRoom("C. Brown", "10AM", "Tu", CSG_table, CR_table, SNAP_table, CDH_table);
	printf("%s\n", room);

	printf("C. Brown at 9AM on Monday --> ");
	room = getRoom("C. Brown", "9AM", "M", CSG_table, CR_table, SNAP_table, CDH_table);
	printf("%s\n", room);

	printf("L. Van Pelt at 9AM on Friday --> ");
		room = getRoom("C. Brown", "9AM", "F", CSG_table, CR_table, SNAP_table, CDH_table);
		printf("%s\n", room);

//	REPL_getGrade(SNAP_table, CSG_table);


	printf("\n\t *** Relational Algebra ***\n");

	printf("\nSelect tuples with Course component \"CS101\" from CSG: \n");
	CSGLIST* select = select_CSG("CS101", CSG_table);
	print_CSG(select);

	printf("\nProject Student ID of students taking CS101: \n");
	project_CSG("CS101", CSG_table);

	printf("\nJoin CDH and CR relations: \n");
	join_CDH_CR(CDH_table, CR_table);
	//print_CRDH(test);

	printf("\nProject Day and Hour of tuple with Room=\"Turing Aud.\" in CRDH: \n");
	join_select_project_CRDH("Turing Aud.",CDH_table, CR_table);

	//project_CRDH("Turing Aud.", test);

//	Operations in Example 8.2
	printf("\n\t *** Part 1 - Example 8.2 Operations ***\n");
	//lookup(("CS101", 12345, *), CSG)
	printf("lookup((\"CS101\", 12345, *), CSG) --> ");
	csg.course = "CS101";
	csg.studentId = 12345;
	csg.grade = "A";
	lookup_CSG(csg, CSG_table, true);

	//lookup((“CS205”, “CS120”), CP)
	printf("lookup((\"CS205\", \"CS120\"), CP) --> ");
	cp.course = "CS205";
	cp.prereq = "CS120";
	lookup_CP(cp, CP_table, true);

	//delete(("CS101", *), CR)
	printf("\ndelete((\"CS101\", *), CR) --> ");
	cr.course = "CS101";
	delete_CR(cr, CR_table, true);
	printf("CR Table after deletion: \n");
	print_CR(CR_table);

	//insert(("CS205", "CS120"), CP)
	printf("\ninsert((\"CS205\", \"CS120\"), CP) --> ");
	cp.course = "CS205";
	cp.prereq = "CS120";
	insert_CP(cp, CP_table, true);
	printf("CP Table after insertion: \n");
	print_CP(CP_table);

	//insert("CS205", "CS101"), CP)
	printf("\ninsert((\"CS205\", \"CS101\"), CP) --> ");
	cp.prereq = "CS101";
	insert_CP(cp, CP_table, true);
	printf("CP Table after insertion: \n");
	print_CP(CP_table);

	printf("\n\t ---------- END OF PROGARM ----------\n\n");
}
