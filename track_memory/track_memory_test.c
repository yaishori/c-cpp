#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "track_memory.h"

#define malloc(x) my_malloc(x)
#define calloc(x,y) my_calloc(x,y)
#define realloc(x,y) my_realloc(x,y)
#define free(x) my_free(x)

extern  size_t memory_alocated_size;

int main(){
	
	int cont = 1;				
	int option;
	int* ptr = NULL;
	int* ptr2;
	size_t size;
	size_t nitems;

	while (cont) {
		printf("Choose option: \n");
		printf("1: malloc \n");
		printf("2: calloc  \n");
		printf("3: realloc  \n");
		printf("4: free  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter size\n");
				scanf("%ld",&size);
				ptr = (int*)malloc(size);
				printf("memory alocated size : %ld\n", memory_alocated_size);
				break;
			case 2:
				printf("enter nitems\n");
				scanf("%ld",&nitems);
				printf("enter size\n");
				scanf("%ld",&size);
				ptr = (int*)calloc(nitems,size);
				printf("memory alocated size : %ld\n", memory_alocated_size);
				break;
			case 3:
				if(ptr != NULL){
					printf("enter size\n");
					scanf("%ld",&size);
					ptr2 = (int*)realloc(ptr,size);
					ptr = ptr2;
					printf("memory alocated size : %ld\n", memory_alocated_size);
				}
				else{
					printf("ptr not alocated\n");
				}
				break;
			case 4:
				free(ptr);
				ptr = NULL;
				printf("memory alocated size : %ld\n", memory_alocated_size);
				break;

			default:
				cont = 0;
				break;
		}
	}

	return 0;
}