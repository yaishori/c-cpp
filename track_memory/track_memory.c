#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "track_memory.h"


size_t memory_alocated_size = 0;

void* my_malloc(size_t size){
	int* ptr;
	
	ptr = (int*)malloc(size+4);
	if(ptr == NULL){
		printf("Memory allocation failed");
		return NULL;
	}
	
	*ptr = size;
	ptr = ptr+1;
	
	memory_alocated_size += size;
	
	return ptr;
}

void* my_calloc(size_t nitems, size_t size){
	int* ptr;
	
	ptr = (int*)malloc(size*nitems + 4);
	if(ptr == NULL){
		printf("Memory allocation failed");
		return NULL;
	}
	
	memset(ptr,'\0',size*nitems + 4);
	*ptr = size*nitems;
	ptr = ptr+1;
	
	memory_alocated_size += size*nitems;
	
	return ptr;
	
}

void* my_realloc(void *ptr, size_t size){
	int* ptr2;
	ptr = (int*)ptr - 1;
	ptr2 = (int*)realloc(ptr, size+4);
	if(ptr2 == NULL){
		printf("Memory allocation failed");
		return NULL;
	}
	
	*ptr2 = size;
	ptr2 = ptr2+1;
	
	memory_alocated_size += size;
	
	return ptr2;
}



void my_free(void* ptr){
	size_t size;
	
	ptr = (int*)ptr - 1;
	size = *(int*)ptr;
	memory_alocated_size -= size;
	free(ptr);
	
	
	return;
}