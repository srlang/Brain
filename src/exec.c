
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"

#ifndef CC
#define CC "gcc"
#endif

#ifndef CFLAGS
#define CFLAGS "-std=c99"
#endif

#define CC_FORMAT "%s %s -o %s %s\n"
#define FAIL_EXIT 1

#define NEW(t,s) (t) malloc(sizeof(t) * s)
#define USAGE_MESG "Usage: screw <brainprog.bf> [<output_executable>]\n"

char * output(char * const filename) {
    char * end, * str, * ending, * ret;
    str = filename;
    end = filename + strlen(filename) - 1;
    ending = NEW(char *, 15);
    ending = ending + 15;
    *ending = '\0';
    ending--;
    while (*end-- != '.') ; /*{
        *ending = *end;
        end--;
        ending--;
    }*/
    ret = NEW(char *, (end-str + 1));
    strncpy(str, ret, (end-str));
    return ret;
}


#define MALLOC_SIZE 200

int compile(char * filename, char * out) {
    char * cc;
    //char * out;
    int status;
    cc = NEW(char *, MALLOC_SIZE);
    //out = output(filename);
    snprintf(cc, MALLOC_SIZE, CC_FORMAT, CC, CFLAGS, out, filename);
    status = system(cc);
    if (out != NULL) {
        free(out);
        out = NULL;
    }
    if (cc != NULL) {
        free(cc);
        cc = NULL;
    }
    return !status;
}

#define TEMP_FILENAME "temp.c"

int execute(char * cmd) {
    return !system(cmd);
}

int main(int argc, char * argv[]) {
    char * cmd;
    FILE * in, * out;
    if (argc < 2 || argc > 3) {
        printf(USAGE_MESG);
        return FAIL_EXIT;
    }
    in = fopen(argv[1], "r+");
    out = fopen(TEMP_FILENAME, "w+");
    parse(in, out);
    cmd = argv[2];
    compile(argv[1], cmd);
    return system(cmd);
}
