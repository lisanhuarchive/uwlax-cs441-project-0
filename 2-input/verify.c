/*
 * Sanhu Li
 * Sep. 16, 2014
 *
 * Project 0.2 question 3
 */
#include "verify.h"

int main(int argc, char **argv) {
    int ret = 0;
	
    if( argc > 1 ) {
        ret = process_cmdline(argc, argv);
    } else {
        ret = process_stdin();
    }
	
	
    return ret;
}

int process_cmdline(int argc, char **argv) {
    // TODO Process strings from the command line
    double running_total;
    int i;
    char *cur;
    float tmp;
    const char *etemp, *rtemp, *ftemp;
	
    etemp = "Error: \"%s\" is not a valid number...\n";
    rtemp = "Running Total:\t%.2f\n";
    ftemp = "Final Total: \t%.2f\n";
	
    running_total = 0;
    cur = NULL;
	
    for (i = 1; i < argc; i++) {
        cur = argv[i];
		
        if (is_valid_int(cur)) {
            tmp = strtol(cur, NULL, 10);
            running_total += tmp;
            printf(rtemp, running_total);
        } else if (is_valid_float(cur)) {
            tmp = strtod(cur, NULL);
            running_total += tmp;
            printf(rtemp, running_total);
        } else {
            printf(etemp, cur);
        }
    }
	
    printf("\n");
    printf(ftemp, running_total);
	
    return 0;
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
        if (isspace(tmp[i]) && status == 0) {
            tmp[i] = '\0';
        } else {
            break;
        }
    }
	
    strcpy(result, tmp);
    free(tmp);
	
    return result;
}

int process_stdin() {
    // TODO Process strings from stdin
    // Start with code copied from the finished stdinput.c here
    char line[LINELEN + 1], *cur;
    double running_total, tmp;
    int len;
    const char *etemp, *rtemp, *ftemp;
	
    running_total = 0;
    etemp = "Error: \"%s\" is not a valid number...\n";
    rtemp = "Running Total:\t%.2f\n";
    ftemp = "Final Total: \t%.2f\n";
	
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
            running_total += tmp;
            printf(rtemp, running_total);
        } else if (is_valid_float(line)) {
            tmp = strtod(line, NULL);
            running_total += tmp;
            printf(rtemp, running_total);
        } else {
            printf(etemp, line);
        }
    }while (cur != NULL);
	
    printf("\n");
    printf(ftemp, running_total);
	
    return 0;
}

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
