#include <stdio.h>

int isAsc(int n){
int x=1;
int remainder1=n%10;
int remainder2;
n=n/10;
	while(n!=0){
	remainder2=n%10;
		if(remainder2 >= remainder1){
		x=0;
		break;
		}
	remainder1=remainder2;
	n=n/10;
		if(n<10){
			if(n >= remainder1){
			x=0;
			break;
			}
			
		}
	
	}
return x;
}


int main (){
	int n,x;
	printf("enter number:");
	scanf("%d", &n);
	x = isAsc(n);
	printf("%d\n",x);
	return 0;
}

