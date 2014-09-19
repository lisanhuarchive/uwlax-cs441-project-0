#
# Sanhu Li
# Sep. 19, 2014
#
CC=gcc
CFLAGS=-Wall -g -O0
LDFLAGS=-lm

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
PROGS=echo verify calc

#
# First target: all
# Compile all programs
#
all: $(PROGS)

#
# Compile Program 1
#
echo: echo.c echo.h
	$(CC) -o echo echo.c $(CFLAGS) 

#
# Compile the supoort library
#
support.o: support.c support.h
	$(CC) -o support.o -c support.c $(CFLAGS)

#
# Compile Program 2
#
verify: verify.c verify.h support.o
	$(CC) -o verify verify.c support.o $(CFLAGS) $(LDFLAGS)

#
# Compile Program 3
#
calc: calc.c calc.h support.o
	$(CC) -o calc calc.c support.o $(CFLAGS) $(LDFLAGS)

#
# Cleanup the files that we have created
#
clean:
	$(RM) $(PROGS)
	$(RM) -rf *.o *.dSYM

#
# Tests
#
include given-tests/Makefile
include tests/Makefile