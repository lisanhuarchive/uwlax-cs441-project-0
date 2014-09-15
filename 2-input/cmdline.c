/*
 * Sanhu Li
 * Sep. 14, 2014
 *
 * Project 0.2 question 1
 */
#include <stdio.h>

int main(int argc, char **argv) {
    // TODO: Write your code here.
    const char *template;
    int i;

    template = "Arg\t%d = (%s)\n";

    for (i = 0; i < argc; i++) {
        printf(template, i, argv[i]);
    }

    return 0;
}
