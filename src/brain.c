/*
 * brain.c - Part of the Brain program 
 *      (a Brainf*** translator)
 * Copyright (C) 2012 - Sean R. Lang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"



#define SUCCESS_EXIT    0
#define FAILURE_EXIT    1
#define READ_MODE       "r"
#define WRITE_MODE      "w"
#define MAX_FILENAME_SIZE   500
int main(int argc, char * argv[]) {
    FILE * in;
    FILE * out;
    if (argc > 2) {
        char * filename = (char *) 
            malloc( MAX_FILENAME_SIZE * sizeof(char));
        filename = strncpy(filename, argv[1], MAX_FILENAME_SIZE);
        in = fopen(filename, READ_MODE);
        filename = strncpy(filename, argv[2], MAX_FILENAME_SIZE);
        out = fopen(filename, WRITE_MODE);
    } else {
        in = stdin;
        out = stdout;
    }
    parse(in, out);
    return SUCCESS_EXIT;
}
