#include <stdio.h>

int reverse(int n){
	
int remainder;
int reversedInt=0;
while( n != 0 ) {
remainder = n % 10;
reversedInt = reversedInt * 10 + remainder;
n=n/10;
}
return reversedInt;
}

int isPalindrome(int n){
int x;
int ans;
x = reverse(n);
ans = (n==x) ? 1 : 0;

return ans;

}


int main (){
	int n,x;
	printf("enter number:");
	scanf("%d", &n);
	x = isPalindrome(n);
	printf("%d\n",x);
	return 0;
}

