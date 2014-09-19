/*
 * Sanhu Li
 * Sep. 19, 2014
 *
 * Project 0.3
 */
#include "verify.h"

double calculate(double v1, double v2, op_type_t op) {
    double result;

    switch (op) {
        case OP_ADDITION:
            result = v1 + v2;
            break;
        case OP_SUBTRACTION:
            result = v1 - v2;
            break;
        case OP_MULTIPLICATION:
            result = v1 * v2;
            break;
        case OP_DIVISION:
            result = v1 / v2;
            break;
        case OP_MODULUS:
            result = fmod(v1, v2);
            break;
    }

    return result;
}

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
    FILE *fd;
    char line[LINELEN + 1], *cur, *txt, *optxt;
    double running_total, tmp;
    int len;
    const char *etemp, *rtemp, *ftemp, *ctemp;
    op_type_t op;

    fd = fopen(filename, "r");
    if (NULL == fd) {
        printf("Error: Cannot open the file %s for reading!\n", filename);
        return -1;
    }

    running_total = 0;
    etemp = "Error: \"%s\" is not a valid number...\n";
    rtemp = "Running Total:\t%.2f\n";
    ftemp = "Final Total: \t%.2f\n";
    ctemp = "Operator changed from (%s) to (%s)\n";
    op = OP_ADDITION;
    optxt = "Addition";

    while (0 == feof(fd)) {
        cur = fgets(line, LINELEN, fd);

        if (cur == NULL) {
            break;
        }

        len = strlen(line);
        line[len - 1] = '\0';

        trim(line, line);

        if (!strcmp(line, "")) {
            strcpy(line, "0.0");
        }

        if (is_valid_int(line)) {
            tmp = strtol(line, NULL, 10);
            running_total = calculate(running_total, tmp, op);
            printf(rtemp, running_total);
        } else if (is_valid_float(line)) {
            tmp = strtod(line, NULL);
            running_total = calculate(running_total, tmp, op);
            printf(rtemp, running_total);
        } else if (is_valid_op(line) == OP_ADDITION) {
            op = OP_ADDITION;
            txt = "Addition";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_SUBTRACTION) {
            op = OP_SUBTRACTION;
            txt = "Subtraction";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_MULTIPLICATION) {
            op = OP_MULTIPLICATION;
            txt = "Multiplication";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_DIVISION) {
            op = OP_DIVISION;
            txt = "Division";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_MODULUS) {
            op = OP_MODULUS;
            txt = "Modulus";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else {
            printf(etemp, line);
        }
    }

    printf("\n");
    printf(ftemp, running_total);

    fclose(fd);

    return 0;
}

int process_stdin() {
	// TODO Process strings from stdin
	// Start with code copied from the finished stdinput.c here
	char line[LINELEN + 1], *cur, *txt, *optxt;
	double running_total, tmp;
	int len;
	const char *etemp, *rtemp, *ftemp, *ctemp;
    op_type_t op;
	
	running_total = 0;
	etemp = "Error: \"%s\" is not a valid number...\n";
	rtemp = "Running Total:\t%.2f\n";
	ftemp = "Final Total: \t%.2f\n";
	ctemp = "Operator changed from (%s) to (%s)\n";
    op = OP_ADDITION;
    optxt = "Addition";

	do {
		cur = fgets(line, LINELEN, stdin);
		
		if (cur == NULL) {
			break;
		}
		
		len = strlen(line);
		line[len - 1] = '\0';
		
		trim(line, line);
		
		if (!strcmp(line, "")) {
			strcpy(line, "0.0");
		}
		
		if (is_valid_int(line)) {
			tmp = strtol(line, NULL, 10);
			running_total = calculate(running_total, tmp, op);
			printf(rtemp, running_total);
		} else if (is_valid_float(line)) {
			tmp = strtod(line, NULL);
            running_total = calculate(running_total, tmp, op);
			printf(rtemp, running_total);
		} else if (is_valid_op(line) == OP_ADDITION) {
            op = OP_ADDITION;
            txt = "Addition";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_SUBTRACTION) {
            op = OP_SUBTRACTION;
            txt = "Subtraction";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_MULTIPLICATION) {
            op = OP_MULTIPLICATION;
            txt = "Multiplication";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_DIVISION) {
            op = OP_DIVISION;
            txt = "Division";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else if (is_valid_op(line) == OP_MODULUS) {
            op = OP_MODULUS;
            txt = "Modulus";
            printf(ctemp, optxt, txt);
            optxt = txt;
        } else {
			printf(etemp, line);
		}
	}while (cur != NULL);
	
	printf("\n");
	printf(ftemp, running_total);
	
	return 0;
}
