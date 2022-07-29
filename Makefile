CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

allocate:
	$(CC) $(CFLAGS) -o allocate.out main.c
