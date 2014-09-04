CC=gcc
CFLAGS=-Wall -g -O0
PROGS=hello

all: $(PROGS)

hello: hello.c
	$(CC) -o $@ $? $(CFLAGS)

clean:
	$(RM) $(PROGS)
	$(RM) -rf *.o *.dSYM