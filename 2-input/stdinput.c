/*
 * Sanhu Li
 * Sep. 14, 2014
 *
 * Project 0.2 question 2
 */
#include <stdio.h>
#import <string.h>

#define MAX_LEN 128

int main(int argc, char **argv) {
    // TODO: Write your code here.
    char line[MAX_LEN + 1], *cur;
    const char *template;
    int len, i;

    template = "  %d) Echo: \"%s\"\n";
    i = 1;
    cur = NULL;

    do {
        cur = fgets(line, MAX_LEN, stdin);

        if (cur == NULL) {
            break;
        }

        len = strlen(line);
        line[len - 1] = '\0';

        printf(template, i++, line);
    }while (cur != NULL);

    return 0;
}
