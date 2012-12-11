# Author: Sean R. Lang
# Makefile to handle easy compilation
#

CC		= gcc
CFLAGS	= -Wall -std=c99 -O3
OBJECTS	= obj/brain.o obj/parser.o

brain: obj/brain.o
	-$(CC) $(CFLAGS) obj/brain.o -o brain

obj/brain.o: src/brain.c
	@mkdir -p obj
	-$(CC) $(CFLAGS) -c src/brain.c -o obj/brain.o

#obj/parser.o: src/parser.c
#	-$(CC) $(CFLAGS) -c src/parser.c -o obj/parser.o

clean:
	-rm -f $(OBJECTS)
	-rm -f brain

test_all: \
	run_test00\
	run_test01\
	run_test02

run_test00:
	@echo Hello, World!

run_test01:
	@./brain examples/helloworld.bf examples/out.c
	@$(CC) $(CFLAGS) -o out examples/out.c
	@./out

run_test02:
	@./brain examples/rot13.bf examples/rot13.c
	@$(CC) $(CFLAGS) -o out examples/rot13.c
	@./out
