#include <stdio.h>
#include <stdlib.h>


int* insert(int num, int* p, int* index, int* capacity){
	int *p2=p;
	int i;
	printf("index =%d \n",*index);
	if(*index==*capacity){
		p = realloc(p,((*capacity)+1)*sizeof(int));
		*capacity=*capacity+1;
		p[*index]=num;

	}
	else {
		p[*index]=num;
		
	}
	*index = *index+1;

	return p;

}


int main(){
	int num=0;
	int* capacity;
	int* p;
	int i =0;
	int j;
	int* index;
	index=&i;
	printf("enter capacity:\n");
	scanf("%d",&j);
	capacity=&j;
	p=malloc((*capacity) * sizeof(int));
	while(num!=-1){
		printf("enter number:\n");
		scanf("%d",&num);
		if(num!=-1){
			insert(num, p, index, capacity);
		}
		else{
			break;
		}
	}
	for(i=0;i<*capacity;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	free(p);
	return 0;
}
