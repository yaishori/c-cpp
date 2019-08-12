#include "dastptp.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int* num;
	int capacity;
	dast* da;
	int isInsert;
	int i=0;
	num=&i;
	printf("enter capacity:\n");
	scanf("%d",&capacity);
	da = createDast(capacity);
	if(da==NULL)
		return 0;
	while(*num!=-1){
		num=malloc(sizeof(int));
		printf("enter number:\n");
		scanf("%d",num);
		if(*num!=-1){
			isInsert=insert(da, num);
			if(!isInsert){
				printf("insert not succ\n");
				break;
			}
		}
	
		else{
			break;
		}
	}
	printDast(da);
	destoryDast(da);
	return 0;
}