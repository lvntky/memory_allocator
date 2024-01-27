/**
 * @file    main.c
 * @date    January 27th, 2024
 *
 *
 * @copyright (c) 2024 Levent Kaya, Lukas R. Jackson
 * All rights reserved.
 */

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "chunk.h"
#include "memory_alloc.h"

extern Chunk_List allocaded_chunks;
// extern Chunk_List freed_chunks;
char memory[MEMORY_CAPACITY];

// Driver code.
int main(void)
{
	for (int i = 0; i < 100; ++i)
	{
		void *p = memory_allocate(i);
		if (i % 2 == 0)
		{
			memory_free(p);
		}
	}
	chunk_list_dump(&allocaded_chunks);

	return 0;
}
