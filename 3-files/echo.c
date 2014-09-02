/*
 * [YOUR NAME]
 * [DATE LAST MODIFIED]
 *
 * [DESCRIPTION OF THE PROGRAM]
 */
#include "echo.h"

int main(int argc, char **argv) {
    int i;

    for( i = 1; i < argc; ++i ) {
        printf("Processing File: %s\n", argv[i]);
        process_file(argv[i]);
    }

    return 0;
}

int process_file(char *filename) {
    char buffer[LINELEN];
    char *fgets_rtn = NULL;

    // TODO: Open the file here


    // TODO: Change loop condition to check for the End-Of-File
    while( 1 ) {
        // TODO: Instead of reading from 'stdin' you should pass the file descriptor
        /* Read input from the user */
        fgets_rtn = fgets(buffer, LINELEN, stdin);
        if( NULL == fgets_rtn) {
            /* Ctrl-D */
            break;
        }

        /* Strip off the new line */
        if( '\n' == buffer[ strlen(buffer) - 1] ) {
            buffer[ strlen(buffer) - 1] = '\0';
        }

        /* Echo the input back the user */
        printf("Line: %s\n", buffer);
    }

    // TODO: Close the file

    return 0;
}
