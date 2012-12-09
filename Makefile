# Author: Sean R. Lang
# Makefile to handle easy compilation
#

CC=gcc
CFLAGS=-Wall

brain: brain.c
	$(CC) $(CFLAGS) brain.c -o brain
