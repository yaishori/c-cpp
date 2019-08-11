#include "dast.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int num=0;
	int capacity;
	dast* da;
	int isInsert;
	printf("enter capacity:\n");
	scanf("%d",&capacity);
	da = createDast(capacity);
	if(da==NULL)
		return 0;
	while(num!=-1){
		printf("enter number:\n");
		scanf("%d",&num);
		if(num!=-1){
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