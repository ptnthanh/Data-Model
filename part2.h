#ifndef PART2_H_
#define PART2_H_

#include "relations.h"

extern char* getGrade(char* name, char* course, SNAPLIST snap_table[], CSGLIST csg_table[]);
extern void REPL_getGrade(SNAPLIST snap_table[], CSGLIST csg_table[]);
extern char* getRoom(char* name, char* time, char* day, CSGLIST csg_table[], CRLIST cr_table[], SNAPLIST snap_table[], CDHLIST cdh_table[]);
extern void REPL_getRoom(CSGLIST csg_table[], CRLIST cr_table[], SNAPLIST snap_table[], CDHLIST cdh_table[]);

#endif /* PART2_H_ */
