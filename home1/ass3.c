#include <stdio.h>

int isPerfect(int n){
int i;
int sum = 0;
int ans;
for(i = 0;i < n/2; i++){
	if(n%i == 0){
	sum = sum + i;
	}
}
ans = (n == sum) ? 1:0;
return ans;
}

int main (){
	printf("enter number:");
	int n;
	scanf("%d, &n);
	int x = isPerfect(n);
	printf("%d",x);
	return 0;
}