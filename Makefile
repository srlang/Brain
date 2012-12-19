# Author: Sean R. Lang
# Makefile to handle easy compilation
#

CC		= gcc
CFLAGS	= -Wall -std=c99 -O3
OBJECTS	= obj/brain.o obj/parser.o

screw: obj/exec.o
	-$(CC) $(CFLAGS) obj/exec.o -o screw

brain: obj/brain.o
	-$(CC) $(CFLAGS) obj/brain.o -o brain

obj/exec.o: src/exec.c src/parser.c
	-$(CC) $(CFLAGS) -c src/exec.c -o obj/exec.o

obj/brain.o: src/brain.c src/parser.c
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
	run_test02\
	run_test03

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

run_test03:
	@./brain examples/add.bf examples/add.c
	@$(CC) $(CFLAGS) -o out examples/add.c
	@./out
