/*
 * brain.c - Part of the Brain program 
 *      (a Brainf*** interpreter)
 * Copyright (C) 2012 - Sean R. Lang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"


//#define TAPE_SIZE 30000

/* Array of cells. */
//extern char tape[TAPE_SIZE];

/* Pointer to current cell location in array. */
//extern char * ptr = tape;

#define SUCCESS_EXIT    0
#define FAILURE_EXIT    1
#define READ_MODE       "r"
#define MAX_FILENAME_SIZE   500
//#define NEW(t,n) (t) malloc(sizeof(
int main(int argc, char * argv[]) {
    ptr = 0;
    FILE * f;
    if (argc > 1) {
        char * filename = (char *) malloc( MAX_FILENAME_SIZE * sizeof(char));
        filename = strncpy(filename, argv[1], MAX_FILENAME_SIZE);
        f = fopen(filename, READ_MODE);
    } else {
        f = stdin;
    }
    parse(f);
    return SUCCESS_EXIT;
}
