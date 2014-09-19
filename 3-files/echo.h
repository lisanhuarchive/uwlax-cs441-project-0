/*
 * Sanhu Li
 * Sep. 19, 2014
 *
 * Project 0.3
 */
#include <stdio.h>
#include <string.h> // For strlen

/*
 * Max length of the buffer for fgets
 */
#define LINELEN 256

/*
 * Process the file with the name provided
 *
 * Parameters:
 *   filename: Filename to process
 * 
 * Returns:
 *   -1 if cannot open the file
 *   0 on success
 */
int process_file(char *filename);
