#include <stdio.h>

int isPerfect(int n){
int i;
int sum = 0;
int ans;
for(i = 1;i <= n/2; i++){
	if(n%i == 0){
	sum = sum + i;
	}
}
ans = (n == sum) ? 1:0;
return ans;
}

int main (){
	int n,x;
	printf("enter number:");
	scanf("%d", &n);
	x = isPerfect(n);
	printf("%d\n",x);
	return 0;
}
