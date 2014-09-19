/*
 * Sanhu Li
 * Sep. 19, 2014
 *
 * Project 0.3
 */
#include "support.h"

int is_valid_int(char *str) {
	// TODO
	int len, i, status;
	char cur;
	
	len = strlen(str);
	status = 0;
	
	for (i = 0; i < len; i++) {
		cur = str[i];
		if (status == 0 && (cur == '+' || cur == '-')) {
			status = 1;
			continue;
		}
		
		if ((status == 0 || status == 1) && isdigit(cur)) {
			status = 2;
			continue;
		}
		
		if (status == 2 && isdigit(cur)) continue;
		
		status = -1;
		break;
	}
	
	if (status == 2) {
		return 1;
	} else {
		return 0;
	}
}

int is_valid_float(char *str) {
	// TODO
	int status, len, i;
	char cur;
	
	len = strlen(str);
	status = 0;
	
	for (i = 0; i < len; i++) {
		cur = str[i];
		if (status == 0 && (cur == '+' || cur == '-')) {
			status = 1;
			continue;
		}
		
		if (status == 1 && isdigit(cur) || status == 0 && isdigit(cur)) {
			status = 2;
			continue;
		}
		
		if (status == 2 && isdigit(cur) || status == 3 && isdigit(cur)) continue;
		
		if ((status != 3) && cur == '.') {
			status = 3;
			continue;
		}
		
		status = -1;
		break;
	}
	
	if (status != 3) {
		return 0;
	} else {
		return 1;
	}
}


op_type_t is_valid_op(char *str) {
    // TODO write this function and return the correct op_type_t
    int status, i, len;
    char cur;

    len = strlen(str);
    status = 0;

    if (len < 4) {
        return OP_INVALID;
    }

    for (i = 0; i < len; i++) {
        cur = str[i];
        if (0 == status && 0 == i && 'o' == cur) {
            status = 1;
            continue;
        }

        if (1 == status && 1 == i && 'p' == cur) {
            status = 2;
            continue;
        }

        if (2 == status && 1 < i && isspace(cur)) {
            continue;
        }

        if (2 == status && 2 < i && !isspace(cur) && '\0' == str[i + 1]) {
            if ('+' == cur) {
                return OP_ADDITION;
            }

            if ('-' == cur) {
                return OP_SUBTRACTION;
            }

            if ('*' == cur) {
                return OP_MULTIPLICATION;
            }

            if ('/' == cur) {
                return OP_DIVISION;
            }

            if ('%' == cur) {
                return OP_MODULUS;
            }

            return OP_INVALID;
        }

        break;
    }
    return OP_INVALID;
}

char * trim(const char * source, char *result) {
    char *tmp;
    int len, i, j, status;

    len = strlen(source);
    tmp = malloc((len + 1) * sizeof(char));
    status = 0;

    for (i = 0, j = 0; i < len; i++) {
        if (status != 1 && isspace(source[i])) {
            continue;
        } else {
            status = 1;
        }

        tmp[j++] = source[i];
    }

    tmp[j] = '\0';

    status = 0;
    for (i = j - 1; i >= 0; i--) {
        if ((isspace(tmp[i])) && status == 0) {
            tmp[i] = '\0';
        } else {
            break;
        }
    }

    strcpy(result, tmp);
    free(tmp);

    return result;
}