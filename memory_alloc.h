/**
 * @file    memory_alloc.h
 * @date    January 27th, 2024
 *
 *
 * @copyright (c) 2024 Levent Kaya, Lukas R. Jackson
 * All rights reserved.
 */

#ifndef __memory_alloc_h_
#define __memory_alloc_h_

void *
memory_allocate(size_t size);

void 
memory_free(void *ptr);

#endif /* __memory_alloc_h_ */