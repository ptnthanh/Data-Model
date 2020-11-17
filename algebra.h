#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#include "relations.h"

extern CSGLIST* select_CSG(char* course, CSGLIST csg_table[]);
extern void project_CSG(char* course, CSGLIST csg_table[]);
extern void join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]);
extern void join_select_project_CRDH(char* room, CDHLIST cdh_table[], CRLIST cr_table[]);

#endif /* ALGEBRA_H_ */
