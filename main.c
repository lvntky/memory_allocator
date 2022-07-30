#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MEMORY_CAPACITY 640000
#define CHUNK_LIST_CAPACITY 1024


// Cust kind of meta-data for 
// Allocated memory on the heap...
typedef struct {
	void* start;
	size_t size;
} Memory_Chunk;

typedef struct
{
	size_t count;
	Memory_Chunk chunks[CHUNK_LIST_CAPACITY];
} Chunk_List;

int chunk_list_find(Chunk_List *chunk, void *ptr)
{
	assert(false && "not implemented yet");
	return -1;
}

void chunk_list_remove(Chunk_List *list, size_t index) {
	assert(false && "not implemented yet");
}

void chunk_list_insert(Chunk_List *list, void* start, size_t size) {
	assert(list->count < CHUNK_LIST_CAPACITY);
	list->chunks[list->count].start = start;
	list->chunks[list->count].size = size;
	for(size_t i = list->count; i > 0 && list->chunks[i].start < list->chunks[i - 1].start; --i) {
		const Memory_Chunk t = list->chunks[i];
		list->chunks[i] = list->chunks[i - 1];
		list->chunks[i - 1 ] = list->chunks[i];
	}	
	list->count += 1;
}

// dumping function to iterate and see whats in the heap
// with healp of meta-data struct to log
void chunk_list_dump(const Chunk_List *chunk)
{
	printf("Chunks ( %zu ):\n", chunk->count);
	for(int i = 0; i < chunk->count; ++i) {
		printf(" starts: %p, size: %zu\n", 
				chunk->chunks[i].start,
				chunk->chunks[i].size);
	}
}


char memory[MEMORY_CAPACITY];
size_t memory_size = 0;

Chunk_List allocaded_chunks = {0};
Chunk_List freed_chunks = {0};

void *memory_allocate(size_t size)
{
	if(size > 0) {
		assert(size + memory_size <= MEMORY_CAPACITY);
		void *result = memory + memory_size;
		memory_size += size;
		chunk_list_insert(&allocaded_chunks, result, size);
		return result;
	}
	// return null in case of user pass 0 size to allocate
	else {
		return NULL;
	}
}


// O(Alloceted)
void memory_free(void *ptr)
{
	assert(false && "free implemet edilecek");	
}

int main(int argc, char** argv)
{
	for(int i = 0; i < 100; ++i){
		void *p = memory_allocate(i);
		if(i % 2 == 0){
			//memory_free(p);
		}
	}
	chunk_list_dump(&allocaded_chunks);
	
	return 0;
}
