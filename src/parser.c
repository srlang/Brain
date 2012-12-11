/*
 * parser.c - part of the Brain program
 *      (a simple brainf*** interpreter)
 * Copyright (C) 2012 - Sean R. Lang
 */

#include <stdio.h>
#include <stdlib.h>



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

char * C_COMMANDS[] = {
    "\t++ptr;\n",
    "\t--ptr;\n",
    "\t++*ptr;\n",
    "\t--*ptr;\n",
    "\tputchar(*ptr);\n",
    "\t*ptr=getchar();\n",
    "\twhile (*ptr) {\n",
    "\t}\n"
};

int which_command(char c) {
    if (!is_command(c)) {
        return 0;
    }
    for(int i = 0; i < NUM_COMMANDS; i++) {
        if (c == COMMANDS[i]) {
            return i+1;
        }
    }
    return 0;
}


//#define TAPE_SIZE   30000
/* Array of cells. */
//extern char tape[TAPE_SIZE];

/* Pointer to current cell location in array. */
//extern char * ptr;

#define HEADER_SIZE 11
char * HEADER[] = {
    "/* Copyright (C) Sean R. Lang */\n",
    "\n",
    "/*\n",
    " * This is a file automatically generated from the\n",
    " * input file you gave to create a brainf*** program.\n",
    " */\n",
    "\n",
    "#include<stdio.h>\n",
    "#define TAPE_SIZE 30000\n",
    "char tape[TAPE_SIZE];\n",
    "char * ptr = tape;\n"
};

#define FAIL_EXIT 1

void parse(FILE * infile, FILE * outfile) {
    char c;
    if (infile == NULL || outfile == NULL) {
        printf("At least one of the files given is not valid.\n");
        exit(FAIL_EXIT);
        //return;
    }

    for(int i = 0; i < HEADER_SIZE; i++) {
        fputs(HEADER[i], outfile);
    }

    //output entrance to main method
    fputs("int main(void) {\n", outfile);

    while ((c = fgetc(infile)) != EOF) {
        if (is_command(c)) {
            fputs(C_COMMANDS[which_command(c) - 1], outfile);
        }
    }

    //output exit from main method
    fputs("\treturn 0;\n}\n", outfile);
}
