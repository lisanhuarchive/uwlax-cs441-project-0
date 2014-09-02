/*
 * [YOUR NAME]
 * [DATE LAST MODIFIED]
 *
 * [DESCRIPTION OF THE PROGRAM]
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINELEN 128

int main(int argc, char **argv) {
    char buffer[LINELEN];
    char *fgets_rtn = NULL;
    
    fgets_rtn = fgets(buffer, LINELEN, stdin);
    
    printf("Echo: %s\n", buffer);
    
    return 0;
}
