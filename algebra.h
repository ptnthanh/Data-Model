/*
 * algebra.h
 *
 *  Created on: Nov 15, 2020
 *      Author: thanhpham
 */

#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#include "relations.h"

extern select_CSG(CSGLIST csg_table[]);
extern project_CSG(CSGLIST csg_table[]);
extern join_CDH_CR(CDHLIST cdh_table[], CRLIST cr_table[]);

#endif /* ALGEBRA_H_ */
