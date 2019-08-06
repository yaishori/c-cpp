#include <math.h> 
#include <stdio.h>

int isPrime(int n){
int i;
int ans=1;
	for(i=2;i <= sqrt(n); i++){
		if(n%i == 0){
		ans=0;
		break;
		}
	}
return ans;

}



int main (){
	printf("enter number:");
	int n;
	scanf("%d, &n);
	int x = isPrime(n);
	printf("%d",x);
	return 0;
}