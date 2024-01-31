/**
 * @file    memory_alloc.c
 * @date    January 27th, 2024
 *
 *
 * @copyright (c) 2024 Levent Kaya, Lukas R. Jackson
 * All rights reserved.
 */

#include "chunk.h"

extern size_t memory_size;

Chunk_List allocaded_chunks = {0};
Chunk_List freed_chunks = {0};
extern char memory[MEMORY_CAPACITY];

void *
memory_allocate(size_t size)
{
	if (size > 0)
	{
		assert(size + memory_size <= MEMORY_CAPACITY);
		void *result = memory + memory_size;
		memory_size += size;
		chunk_list_insert(&allocaded_chunks, result, size);
		return result;
	}
	// return null in case of user pass 0 size to allocate
	else
	{
		return NULL;
	}
}

// O(Alloceted)
void memory_free(void *ptr)
{
	if (ptr != NULL)
	{
		const int index = chunk_list_find(&allocaded_chunks, ptr);
		assert(index >= 0);
		chunk_list_insert(&freed_chunks, allocaded_chunks.chunks[index].start, allocaded_chunks.chunks[index].size);
		chunk_list_remove(&allocaded_chunks, (size_t)index);
	}
}