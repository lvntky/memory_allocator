/**
 * @file    chunk.c
 * @date    January 27th, 2024
 *
 *
 * @copyright (c) 2024 Levent Kaya, Lukas R. Jackson
 * All rights reserved.
 */

#include "chunk.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

size_t memory_size = 0;

int chunk_start_compar(const void *a, const void *b)
{
    const Memory_Chunk *a_chunk = a;
    const Memory_Chunk *b_chunk = b;
    return a_chunk->start - b_chunk->start;
}

int chunk_list_find(Chunk_List *list, void *ptr)
{
    Memory_Chunk key = {
        .start = ptr};

    Memory_Chunk *result = bsearch(&key, list->chunks,
                                   list->count, sizeof(list->chunks[0]),
                                   chunk_start_compar);
    if (result != 0)
    {
        assert(list->chunks <= result);
        return (result - list->chunks) / sizeof(list->chunks[0]);
    }
    else
    {
        return -1;
    }
}

void chunk_list_remove(Chunk_List *list, size_t index)
{
    assert(index < list->count);
    for (size_t i; i < list->count - 1; ++i)
    {
        list->chunks[i] = list->chunks[i + 1];
    }
    list->count -= 1;
}

void chunk_list_insert(Chunk_List *list, void *start, size_t size)
{
    assert(list->count < CHUNK_LIST_CAPACITY);
    list->chunks[list->count].start = start;
    list->chunks[list->count].size = size;
    for (size_t i = list->count; i > 0 && list->chunks[i].start < list->chunks[i - 1].start; --i)
    {
        const Memory_Chunk t = list->chunks[i];
        list->chunks[i] = list->chunks[i - 1];
        list->chunks[i - 1] = list->chunks[i];
    }
    list->count += 1;
}

// dumping function to iterate and see whats in the heap
// with healp of meta-data struct to log
void chunk_list_dump(const Chunk_List *chunk)
{
    printf("Chunks ( %zu ):\n", chunk->count);
    for (int i = 0; (size_t)i < chunk->count; ++i)
    {
        printf(" starts: %p, size: %zu\n",
               chunk->chunks[i].start,
               chunk->chunks[i].size);
    }
}
