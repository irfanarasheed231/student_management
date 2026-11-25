#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

/* Add */
void addbegin(SLL **ptr);

/* Delete */
void deletenode(SLL **ptr);
void deleteall(SLL **ptr);

/* Display */
void printnode(SLL *ptr);
int countnode(SLL *ptr);

/* Modify */
void modify(SLL *ptr);

/* File handling */
void savefile(SLL *ptr);
void readfile(SLL **ptr);

/* Sorting */
void sortdata(SLL *ptr);

/* Reverse */
void reverseList(SLL **ptr);
void reverseprint(SLL *ptr);

/* Exit */
void exitprogram(SLL **ptr);

#endif
