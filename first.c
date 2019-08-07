
#include <stdio.h>

func1(int n){
int i;
for(i=0;i<n;i++){
	int j;
	for(j=-1;j<i;j++){
	printf("*");
	}
	printf("\n");

}

}

func2(int n){
int i;
func1(n);

for(i=(n-1);i>0;i--){
	int j;
	for(j=0;j<i;j++){
	printf("*");
	}
	printf("\n");

}

}

func3(int n){
int i;
int k =-1; 
int j;
for(i=-1;i < n - 1;i++){
	for(j=n-i-2;j>0;j=j-1){
		printf(" ");
	}

	
	k = k  + 2;
	for(j=0;j < k;j++){
	printf("*");
	}
	
	printf("\n");

}

}





int main() {
/* my first program in C */
int n;
printf("enter number! \n");
scanf("%d",&n);
func1(n);
printf("\n");
func2(n);
printf("\n");
func3(n);




   

   
return 0;
}

