#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


void lotto(char arr[]){
	int j=0;
	int x;
	srand (time(NULL));
	printf("the numbers are:\n");
	while(j<6){
	x= (rand()%50);
		if((arr[x-1]=='-')&& x!=0){
		printf("%d \n",x);
		arr[x-1]='+';
		j++;
		}
	}
	printf("\n");
	


}


int main (){
	char arr[50];
	int i;
	int j;
	for(i=0;i<49;i++){
		arr[i]='-';
	}
	arr[49]=' ';
	lotto(arr);
	printf("  ");
	for(i=1;i<=10;i++){
		printf("%d ",i);
	}
	printf("\n");

	for(i=0;i<5;i++){
		printf("%d ",i);
			for(j=0;j<10;j++){
				printf("%c ",arr[j+10*i]);
			}
		printf("\n");
	}
	
	return 0;
}
