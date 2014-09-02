/*
 * [YOUR NAME]
 * [DATE LAST MODIFIED]
 *
 * [DESCRIPTION OF THE PROGRAM]
 */
#include <stdio.h>
#include <string.h> // For strlen
#include <stdlib.h> // For strtol and strtod
#include <ctype.h>  // For isdigit

/*
 * Maximum line length
 */
#define LINELEN 128


/*
 * Process input from the command line arguments
 *
 * Parameters:
 *   argc : Count of command line arguments
 *   argv : Array of C-style strings
 *
 * Returns:
 *   0 on success
 *   -1 on error
 */
int process_cmdline(int argc, char **argv);

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
 * Takes as input a string to check if it is a syntacticly correct integer.
 *
 * Parameters:
 *   str : String to check
 *
 * Returns:
 *   0 if it is not a valid integer
 *   1 if it is a valid integer
 */
int is_valid_int(char *str);

/*
 * Takes as input a string to check if it is a syntacticly correct
 * floating point number.
 *
 * Parameters:
 *   str : String to check
 *
 * Returns:
 *   0 if it is not a valid float
 *   1 if it is a valid float
 */
int is_valid_float(char *str);
