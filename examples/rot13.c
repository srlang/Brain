/* Copyright (C) Sean R. Lang */

/*
 * This is a file automatically generated from the
 * input file you gave to create a brainf*** program.
 */

#include<stdio.h>
#define TAPE_SIZE 30000
char tape[TAPE_SIZE];
char * ptr = tape;
int main(void) {
	--*ptr;
	*ptr=getchar();
	++*ptr;
	while (*ptr) {
	--*ptr;
	while (*ptr) {
	++ptr;
	++ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	while (*ptr) {
	++ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	--ptr;
	--*ptr;
	}
	--ptr;
	++*ptr;
	--ptr;
	--*ptr;
	while (*ptr) {
	++ptr;
	++*ptr;
	++ptr;
	++*ptr;
	++ptr;
	--*ptr;
	while (*ptr) {
	++ptr;
	++ptr;
	++ptr;
	}
	--ptr;
	while (*ptr) {
	while (*ptr) {
	++ptr;
	++*ptr;
	--ptr;
	--*ptr;
	}
	++ptr;
	++ptr;
	++*ptr;
	++ptr;
	}
	--ptr;
	--ptr;
	--ptr;
	--ptr;
	--ptr;
	--*ptr;
	}
	}
	++ptr;
	++ptr;
	++ptr;
	while (*ptr) {
	--*ptr;
	}
	++*ptr;
	++ptr;
	--*ptr;
	--*ptr;
	while (*ptr) {
	--*ptr;
	while (*ptr) {
	--ptr;
	--*ptr;
	++ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	while (*ptr) {
	--*ptr;
	}
	}
	}
	--ptr;
	while (*ptr) {
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	--ptr;
	while (*ptr) {
	++ptr;
	--*ptr;
	while (*ptr) {
	++ptr;
	++*ptr;
	++ptr;
	++ptr;
	}
	++ptr;
	while (*ptr) {
	++*ptr;
	while (*ptr) {
	--ptr;
	++*ptr;
	++ptr;
	--*ptr;
	}
	++ptr;
	++*ptr;
	++ptr;
	++ptr;
	}
	--ptr;
	--ptr;
	--ptr;
	--ptr;
	--ptr;
	--*ptr;
	}
	++ptr;
	++ptr;
	while (*ptr) {
	--ptr;
	++*ptr;
	++ptr;
	--*ptr;
	}
	++ptr;
	while (*ptr) {
	--*ptr;
	while (*ptr) {
	--*ptr;
	--ptr;
	--ptr;
	while (*ptr) {
	--*ptr;
	}
	++ptr;
	++ptr;
	}
	--ptr;
	--ptr;
	while (*ptr) {
	--ptr;
	--ptr;
	--*ptr;
	++ptr;
	++ptr;
	--*ptr;
	}
	++ptr;
	++ptr;
	}
	--ptr;
	--ptr;
	while (*ptr) {
	--ptr;
	--ptr;
	++*ptr;
	++ptr;
	++ptr;
	--*ptr;
	}
	}
	--ptr;
	while (*ptr) {
	--*ptr;
	}
	--ptr;
	putchar(*ptr);
	while (*ptr) {
	--*ptr;
	}
	--ptr;
	--*ptr;
	*ptr=getchar();
	++*ptr;
	}
	return 0;
}
