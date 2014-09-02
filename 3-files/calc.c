/*
 * [YOUR NAME]
 * [DATE LAST MODIFIED]
 *
 * [DESCRIPTION OF THE PROGRAM]
 */
#include "calc.h"

int main(int argc, char **argv) {
    int ret = 0;
    int i;

    if( argc > 1 ) {
        for( i = 1; i < argc; ++i ) {
            printf("Processing File: %s\n", argv[i]);
            process_file(argv[i]);
        }
    } else {
        ret = process_stdin();
    }

    return ret;
}

int process_file(char *filename) {
    // TODO Add your code here
    return 0;
}

int process_stdin() {
    // TODO Process strings from stdin
    return 0;
}
