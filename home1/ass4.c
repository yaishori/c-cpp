#include <stdio.h>

int reverse(int n){
	
int remainder;
int reverseInt;
while( n != 0 ) {
remainder = n % 10;
reversedInt = reversedInt * 10 + remainder;
n=n/10;
}
return reversedInt;
}

int main (){
	printf("enter number:");
	int n;
	scanf("%d, &n);
	int x = reverse(n);
	printf("%d",x);
	return 0;
}