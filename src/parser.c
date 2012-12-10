/*
 * parser.c - part of the Brain program
 *      (a simple brainf*** interpreter)
 * Copyright (C) 2012 - Sean R. Lang
 */

#include <stdio.h>



#define INCREMENT_PTR   '>'
#define DECREMENT_PTR   '<'
#define INCREMENT_BYTE  '+'
#define DECREMENT_BYTE  '-'
#define OUTPUT_BYTE     '.'
#define ACCEPT_BYTE     ','
#define LOOP_BEGIN      '['
#define LOOP_END        ']'
int is_command(char c) {
    return (c == INCREMENT_PTR) 
        || (c == DECREMENT_PTR)
        || (c == INCREMENT_BYTE)
        || (c == DECREMENT_BYTE)
        || (c == OUTPUT_BYTE)
        || (c == ACCEPT_BYTE)
        || (c == LOOP_BEGIN)
        || (c == LOOP_END);
}

#define NUM_COMMANDS    8
char COMMANDS[] = {'>', '<', '+', '-', '.', ',', '[', ']'};

int which_command(char c) {
    if (!is_command(c)) {
        return 0;
    }
    for(int i = 0; i < NUM_COMMANDS; i++) {
        if (c == COMMANDS[i]) {
            return i+1;
        }
    }
}

void execute_command(char c) {

}





#define TAPE_SIZE   30000

/* Array of cells. */
extern char tape[TAPE_SIZE];

/* Pointer to current cell location in array. */
extern char * ptr;


void parse(FILE * f) {
    char c;
    ptr = tape;
    if (f == NULL) {
        /* print error message */
        return;
    }
    while ((c = fgetc(f)) != EOF) {
        if (is_command(c)) {
            /* write command to file */
        }
    }
}
