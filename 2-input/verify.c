/*
 * [YOUR NAME]
 * [DATE LAST MODIFIED]
 *
 * [DESCRIPTION OF THE PROGRAM]
 */
#include "verify.h"

int main(int argc, char **argv) {
    int ret = 0;

    if( argc > 1 ) {
        ret = process_cmdline(argc, argv);
    } else {
        ret = process_stdin();
    }

    return ret;
}

int process_cmdline(int argc, char **argv) {
    // TODO Process strings from the command line

    return 0;
}

int process_stdin() {
    // TODO Process strings from stdin
    // Start with code copied from the finished stdinput.c here

    return 0;
}

int is_valid_int(char *str) {
    // TODO
    return 0;
}

int is_valid_float(char *str) {
    // TODO
    return 0;
}
