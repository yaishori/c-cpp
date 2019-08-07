
#include <stdio.h>
#include <stdlib.h> 

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

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

int sort5(int arr[],int n){
  	int i;
  	int sum=0;
  	int ret=0;
 	int retInt=arr[0];
  	sort1(arr,n);
  		for(i=0;i<n-1;i++){
  			if(arr[i]==arr[i+1]){
  			ret++;
  			}
  			if(ret>sum){
  				sum=ret;
  				retInt=arr[i];
  			}

 		}
 	return retInt;
}



void sort4(int arr[],int n)
{ 
   int i, j;
   int flag=0; 
   for (i = 0; i < n-1; i++){
   	   flag =0;          
       for (j = 0; j < n-i-1; j++){ 
           if ((abs(arr[j])%2!=0)&&(abs(arr[j+1])%2==0)){
              swap(&arr[j], &arr[j+1]);
              flag=1;
            }
       }
    if(flag==0) break; 
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


 

int main() {
int arr[8]={1,0,0,1,0,1,0,1};
int arr2[8]={1,5,3,7,1,0,9,5};
int arr4[8]={1,-5,4,7,-1,0,-8,5};
int arr5[8]={1,5,7,7,1,7,9,5};
int i;
int maxOccur;

sort2(arr,8);
sort1(arr2,8);
sort4(arr4,8);
maxOccur= sort5(arr5,8);

printf("sort by zero and one:\n");

	for(i=0;i<8;i++){
		printf("%d",arr[i]);
	}

printf("\n");

printf("sort in asc order:\n");


	for(i=0;i<8;i++){
		printf("%d",arr2[i]);
	}

printf("\n");
printf("sort even and odd with the same order:\n");

	for(i=0;i<8;i++){
		printf("%d",arr4[i]);
	}

printf("\n");
printf("max occur:\n");

printf("%d\n",maxOccur);

   
return 0;

}