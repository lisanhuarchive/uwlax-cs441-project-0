/*
 * Sanhu Li
 * Sep. 19, 2014
 *
 * Project 0.3
 */
#ifndef __SUPPORT_H__
#define __SUPPORT_H__
/* WARNING: Do not put any code above the #ifndef/#define statements, seen above */

#include <stdio.h>
#include <string.h> // For strlen
#include <stdlib.h> // For strtol and strtod
#include <ctype.h>  // For isdigit
#include <math.h>   // For fmod

/*
 * Max length of the buffer for fgets
 */
#define LINELEN 256

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

/*
 * Enumerated type for operator types
 * You can use these as constants in your program.
 */
enum op_type {
    OP_INVALID  = -1,
    OP_ADDITION = 1,
    OP_SUBTRACTION,
    OP_MULTIPLICATION,
    OP_DIVISION,
    OP_MODULUS
};
typedef enum op_type op_type_t;

/*
 * Takes as input a string to check if it is a syntacticly correct
 * operation command
 *
 * Parameters:
 *   str : String to check
 *
 * Returns:
 *   OP_INVALID if it is not a valid operation
 *   OP_* matching the associated operation from the enumerated type.
 */
op_type_t is_valid_op(char *str);

/*
 * Trim function to trim the strings
 *
 * Parameters:
 *   source : String to trim
 *   result : Destination to put the string
 *
 * Note:
 *   make sure the result has enough space to store the trimmed string.
 *
 * Returns:
 *   result pointer
 */
char * trim(const char * source, char *result);


#endif /* __SUPPORT_H__ */
/* WARNING: Do not put any code after the #endif statement, seen above */
