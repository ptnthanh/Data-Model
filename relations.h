#ifndef RELATIONS_H_
#define RELATIONS_H_

#include <stdbool.h>

extern int TABLE_SIZE;

// Course - Student - Grade
typedef struct CSG* CSGLIST;
typedef struct CSG {
    char* course;
    int studentId;
    char* grade;
    CSGLIST next;
} CSG;
//typedef CSGLIST HASHTABLE_CSG[1009];
extern CSGLIST new_CSG(char* c, int s, char* g);
extern void print_CSG(CSGLIST table[]);
extern void insert_CSG(CSG csg, CSGLIST table[], bool print);
extern void delete_CSG(CSG csg, CSGLIST table[], bool print);
extern CSGLIST lookup_CSG(CSG csg, CSGLIST table[], bool print);


// Student - Name - Address - Phone
typedef struct SNAP* SNAPLIST;
typedef struct SNAP  {
    int studentId;
    char* name;
    char* address;
    char* phone;
    SNAPLIST next;
} SNAP;
//typedef SNAPLIST HASHTABLE_SNAP[1009];
extern void print_SNAP(SNAPLIST table[]);
extern void insert_SNAP(SNAP snap, SNAPLIST table[], bool print);
extern void delete_SNAP(SNAP snap, SNAPLIST table[], bool print);
extern SNAPLIST lookup_SNAP(SNAP snap, SNAPLIST table[], bool print);


// Course - Prerequisite
typedef struct CP* CPLIST;
typedef struct CP {
    char* course;
    char* prereq;
    CPLIST next;
} CP;
//typedef CPR_RELATION HASHTABLE_CPR[1009];
extern void print_CP(CPLIST table[]);
extern void insert_CP(CP cp, CPLIST table[], bool print);
extern void delete_CP(CP cp, CPLIST table[], bool print);;
extern CPLIST lookup_CP(CP cp, CPLIST table[], bool print);


// Course - Day - Hour
typedef struct CDH* CDHLIST;
typedef struct CDH {
    char* course;
    char* day;
    char* hour;
    CDHLIST next;
} CDH;
//typedef CDH_RELATION HASHTABLE_CDH[1009];
extern void print_CDH(CDHLIST table[]);
extern void insert_CDH(CDH cdh, CDHLIST table[], bool print);
extern void delete_CDH(CDH cdh, CDHLIST table[], bool print);
extern CDHLIST lookup_CDH(CDH cdh, CDHLIST table[], bool print);


// Course - Room
// Primary key: course
typedef struct CR* CRLIST;
typedef struct CR {
    char* course;
    char* room;
    CRLIST next;
} CR;
//typedef CR_RELATION HASHTABLE_CR[1009];
extern void print_CR(CRLIST table[]);
extern void insert_CR(CR cr, CRLIST table[], bool print);
extern void delete_CR(CR cr, CRLIST table[], bool print);
extern CRLIST lookup_CR(CR cr, CRLIST table[], bool print);


// Course - Room - Day - Hour
typedef struct CRDH* CRDHLIST;
typedef struct CRDH {
    char* course;
    char* room;
    char* day;
    char* hour;
    CRDHLIST next;
} CRDH;
extern void print_CRDH(CRDHLIST table[]);


// Hashing functions
extern int stringToInt(char* str);
extern int hashInt(int x);
extern int hashString(char* str);
extern int hashIntAndString(int id, char* course);
extern int hashTwoStrings(char* s1, char* s2);


#endif /* RELATIONS_H_ */
