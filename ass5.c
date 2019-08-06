#include <math.h> 
#include <stdio.h>

/*gcc ass5.c -lm*/

int isPrime(int n){
int i;
int ans=1;
int x =sqrt(n);
	for(i=2;i <= x; i++){
		if(n%i == 0){
		ans=0;
		break;
		}
	}
return ans;

}



int main (){
	int n,x;
	printf("enter number:");
	scanf("%d", &n);
	x = isPrime(n);
	printf("%d\n",x);
	return 0;
}
