#include <stdio.h>
#include "darray_int.h"

int main(){
	int cont = 1;				
	int option;
	darray* da;
	int retItem;
	int capacity;
	int created=0;
	int item;
	int myIndex;
	enum AdtStatus status;
	while (cont) {
		printf("Choose option: \n");
		printf("1: create darray  \n");
		printf("2: insert   \n");
		printf("3: remove \n");
		printf("4: sort \n");
		printf("5: get \n");
		printf("6: set \n");
		printf("7: num of items \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter capacity:\n");
				scanf("%d",&capacity);
				status=darrayCreate(&da,capacity);
				if(status==AllocationError){
					printf("calendar not created:\n");
					return 0;
				}
				created=1;	
				break;
			case 2:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				printf("enter item:\n");
				scanf("%d",&item);
				status=darrayAdd(da,item);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}

				break;
			case 3:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
		
				status =darrayDelete(da,&retItem);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				printf("item=%d\n",retItem);
				break;
			case 4:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				status=darraySort(da);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				break;
			case 5:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				printf("enter index:\n");
				scanf("%d",&myIndex);
				status= darrayGet(da, myIndex, &retItem);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				if(status==WrongIndex){
					printf("wrong index:\n");
					return 0;
				}
				printf("item=%d\n",retItem);
				
				break;
			case 6:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				printf("enter item:\n");
				scanf("%d",&item);
				printf("enter index:\n");
				scanf("%d",&myIndex);
				status=darraySet(da, myIndex, item);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				if(status==WrongIndex){
					printf("wrong index:\n");
					return 0;
				}
				break;
			case 7:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				status= darrayItemsNum(da,&retItem);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				printf("num of items=%d\n",retItem);
				break;
			default:
				if(created){
				darrayDestroy(da);
				}
				cont = 0;	break;
		}
	}


	return 0;
}