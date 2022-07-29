#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MEMORY_CAPACITY 640000
#define MEMORY_ALLOC_CAPACITY 1024

// Cust kind of meta-data for 
// Allocated memory on the heap...
typedef struct {
	void* start;
	size_t size;
} Memory_Chunk;

char memory[MEMORY_CAPACITY];
size_t memory_size = 0;

Memory_Chunk memory_alloced[MEMORY_ALLOC_CAPACITY] = {0};
size_t memory_alloced_size = 0;

void *memory_allocate(size_t size)
{
	assert(size + memory_size <= MEMORY_CAPACITY);
	void *result = memory + memory_size;
	memory_size += size;
	Memory_Chunk chunk = {
		.start = result,
		.size = size,
	};
	assert(memory_alloced_size < MEMORY_ALLOC_CAPACITY);
	memory_alloced[memory_alloced_size++] = chunk;
	return result;	
}

// dumb function to see whats in the heap
// with healp of meta-data structer to log
void mem_dump_alloced_chunks(void)
{
	printf("Allocated Chunks in the heap: %zu\n", memory_alloced_size);
	for(int i = 0; i < memory_alloced_size; ++i) {
		printf(" starts: %p, size: %zu\n", 
				memory_alloced[i].start,
				memory_alloced[i].size);
	}
}

void memory_free(void *ptr)
{
	assert(false && "TODO: FREE WILL IMPLEMENTED.");
}

int main(int argc, char** argv)
{
	char* root = memory_allocate(26);
	for(int i = 0; i < 26; i++) {
		root[i] = i + 'A';
	}
	mem_dump_alloced_chunks();
	return 0;
}
