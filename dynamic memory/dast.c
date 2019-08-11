#include "dast.h"
#include <stdio.h>
#include <stdlib.h>

dast* createDast(int capacity){
	dast* da;
	da = malloc(sizeof(dast));
	if(da==NULL){
		printf("da null pointer!\n");
		return NULL;
	}
	da->capacity=capacity;
	da->index=0;
	da->arr=malloc((capacity) * sizeof(int));
	if(da->arr==NULL){
		free(da);
		printf("da->arr null pointer!\n");
		return NULL;
	}
	return da;
}

int insert(dast* da, int num){  /*return 1 if succ and 0 if not*/
	int *p2= da->arr;
	printf("index =%d \n",da->index);
	if(da->index==da->capacity){
		p2 = realloc(da->arr,((da->capacity)*2)*sizeof(int));
		if(p2!=NULL){
		da->arr=p2;
		(da->capacity)=(da->capacity)*2;		
		}
		else
			return 0;

	}
	da->arr[da->index]=num;
	da->index = (da->index)+1;

	return 1;
}

void printDast(dast* da){
	int i;
	int j=da->index;
	int* arr = da->arr;
	printf("capacity: %d\n", da->capacity);
	printf("index: %d\n", da->index);
	printf("array:\n");
	for(i=0;i<j;i++){
		printf("%d ",arr[i]);
	}

}

void destoryDast(dast* da){
	free(da->arr);
	free(da);
}

