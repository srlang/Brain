# Author: Sean R. Lang
# Makefile to handle easy compilation
#

CC		= gcc
CFLAGS	= -Wall
OBJECTS	= obj/brain.o

brain: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f brain

test_all: run_test00

run_test00:
	@echo Hello, World!
