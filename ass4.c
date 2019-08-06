#include <stdio.h>

int reverse(int n){
	
int remainder;
int reversedInt;
while( n != 0 ) {
remainder = n % 10;
reversedInt = reversedInt * 10 + remainder;
n=n/10;
}
return reversedInt;
}

int main (){
	int n,x; 
	printf("enter number:");
	scanf("%d", &n);
	x = reverse(n);
	printf("%d\n",x);
	return 0;
}
