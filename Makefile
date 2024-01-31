# Makefile for memory_allocator

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wunused-variable -Wextra -std=c11 -pedantic -ggdb

# Source files
SRCS = chunk.c memory_alloc.c main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executables
MEM_ALLOC_TARGET = mem_alloc.out

# Rule to build mem_alloc.out
interface:
	$(CC) $(CFLAGS) -o $(MEM_ALLOC_TARGET) $(SRCS)
