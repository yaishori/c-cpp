#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


lotto(char arr[]){
int j=0;
int num;
srand (time(NULL));
	while(j<6){
	x= (rand()%50);
		if((arr[x-1]=='-')&& x!=o){
		arr[x-1]='+';
		j++;
		}
	}
	


}


int main (){
	char arr[49];
	int i;
	int j;
	for(i=0;i<49,i++){
		arr[i]='-';
	}
	lotto(arr);
	printf("  ")
	for(i=1;i<=10,i++){
		printf("%d ",i);
	}
	printf("/n");

	for(i=0;i<5;i++){
		printf("%d ",i)
		for(j=o;j<10;j++){
			printf("%c ",arr[j+10*i]);
		}
		printf("/n");
	}
return 0;
}