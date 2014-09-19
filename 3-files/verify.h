/*
 * Sanhu Li
 * Sep. 19, 2014
 *
 * Project 0.3
 */
#include "support.h"


/*
 * Process input from the console via stdin
 *
 * Parameters:
 *   None
 *
 * Returns:
 *   0 on success
 *   -1 on error
 */
int process_stdin();

/*
 * Process all of the instructions in the filename specified.
 *
 * Parameters:
 *   filename: Filename to process
 *
 * Returns:
 *   0 on success
 *  -1 if we cannot open the file
 */
int process_file(char *filename);
