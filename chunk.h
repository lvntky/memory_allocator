/**
 * @file    chunk.h
 * @date    January 27th, 2024
 *
 *
 * @copyright (c) 2024 Levent Kaya, Lukas R. Jackson
 * All rights reserved.
 */

#ifndef __chunk_h_
#define __chunk_h_

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// Cust kind of meta-data for 
// Allocated memory on the heap...

#define MEMORY_CAPACITY 640000
#define CHUNK_LIST_CAPACITY 1024

typedef struct {
	char* start;
	size_t size;
} Memory_Chunk;

typedef struct
{
	size_t count;
	Memory_Chunk chunks[CHUNK_LIST_CAPACITY];
} Chunk_List;

extern char memory[MEMORY_CAPACITY];

int
chunk_start_compar(const void *a, const void *b);

int 
chunk_list_find(Chunk_List *list, void *ptr);

void
chunk_list_remove(Chunk_List *list, size_t index);

void
chunk_list_insert(Chunk_List *list, void *start, size_t size);

void 
chunk_list_dump(const Chunk_List *chunk);

#endif /* __chunk_h_ */