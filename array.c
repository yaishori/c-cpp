
#include <stdio.h>
#include <stdlib.h> 

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}

void sort4(int arr[],int n){
int *zero;
int *one;
int *tmp;
int i;
zero=arr;
tmp=arr;
one=arr+n-1;

for(i=0;zero<one;i++){

	if((*tmp == 0)||(((abs(*tmp))%2)== 0)){
	swap(tmp,zero);
	zero++;
	tmp++;
	}

	if(((abs(*tmp))%2)!= 0){
	swap(tmp,one);
	one--;	
	}
}	
}

void sort2(int arr[],int n){
int *zero;
int *one;
int *tmp;
int i;
zero=arr;
tmp=arr;
one=arr+n-1;

for(i=0;zero<one;i++){

	if(*tmp == 0){
	swap(tmp,zero);
	zero++;
	tmp++;
	}

	if(*tmp ==1){
	swap(tmp,one);
	tmp++;
	one--;	
	}
}	
}

void sort1(int arr[],int n)
{ 
   int i, j; 
   for (i = 0; i < n-1; i++){          
       for (j = 0; j < n-i-1; j++){ 
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
            }
       } 
    }
} 

int main() {
int arr[8]={1,0,0,1,0,1,0,1};
int arr2[8]={1,5,3,7,1,0,9,5};
int arr4[8]={1,-5,4,7,-1,0,-8,5};
int i;
sort2(arr,8);
sort1(arr2,8);
sort4(arr4,8);

for(i=0;i<8;i++){
	printf("%d",arr[i]);
}
printf("\n");

for(i=0;i<8;i++){
	printf("%d",arr2[i]);
}
printf("\n");

for(i=0;i<8;i++){
	printf("%d",arr4[i]);
}
printf("\n");

   
   return 0;
}