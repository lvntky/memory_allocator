#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MEMORY_CAPACITY 640000

char memory[MEMORY_CAPACITY];
size_t memory_size = 0;

void *memory_allocate(size_t size)
{
	assert(size + memory_size <= MEMORY_CAPACITY);
	void *result = memory + memory_size;
	memory_size += size;
	return result;	
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
	return 0;
}
