/*
 * algebra.h
 *
 *  Created on: Nov 15, 2020
 *      Author: thanhpham
 */

#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#include "relations.h"

extern CSGLIST* select_CSG(char* course, CSGLIST csg_table[]);
extern void project_CSG(char* course, CSGLIST csg_table[]);
extern CRDHLIST* join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]);
extern CRDHLIST select_CRDH(char* room, CRDHLIST table);
extern void project_CRDH(char* room, CRDHLIST table);
extern void alternative(char* room, CDHLIST cdh_table[], CRLIST cr_table[]);

#endif /* ALGEBRA_H_ */
