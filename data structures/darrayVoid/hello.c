#include <stdio.h>
#include "darray_generic.h"

typedef struct{
    int x;
    int y;
}point;

void elementDes(void *_elem, void *context){
	int *mycontext=(int*)context;
	*mycontext=5;
	printf("%d\n",*mycontext);
	return;
}

int elementCom(void *_elemA, void *_elemB){
	int ret=(*(int*)_elemA - *(int*)_elemB);
	/*printf("A= %d\n",*(int*)_elemA);
	printf("B= %d\n",*(int*)_elemB);
	printf("ret= %d\n",ret);*/
	return ret;
}

 int PointsSom(void *_elemA, void *_elemB){ 
  	point* pointA=(point*)_elemA;
	point* pointB=(point*)_elemB;
    return (pointA->x+pointA->y)-(pointB->x+pointB->y);
}

void pointDes (void *_elem, void *context){
	FILE* fp=(FILE*)context;
 	point* p=(point*)_elem;
  	fprintf(fp,"point.x IS %d ",p->x);
    fprintf(fp,"point.y IS %d ",p->y);
    free(p);
}

int main(){
	int cont = 1;				
	int option;
	darray* da;
	void *retItem;
	int *intItem;
	int itemNum;
	int capacity;
	int created=0;
	int *item;
	int myIndex;
	void *context;
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
				item=malloc(sizeof(int));
				printf("enter item:\n");
				scanf("%d",item);
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
				intItem=(int*)retItem;
				printf("item=%d\n",*intItem);
				break;
			case 4:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				status=darraySort(da,elementCom);
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
				intItem=(int*)retItem;
				printf("item=%d\n",*intItem);
				
				break;
			case 6:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				item=malloc(sizeof(int));
				printf("enter item:\n");
				scanf("%d",item);
				printf("enter index:\n");
				scanf("%d",&myIndex);
				status=darraySet(da, myIndex, &item);
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
				status= darrayItemsNum(da,&itemNum);
				if(status==NullPointer){
					printf("null pointer:\n");
					return 0;
				}
				printf("num of items=%d\n",itemNum);
				break;
			default:
				if(created){
				darrayDestroy(da,elementDes,context);
				}
				cont = 0;	break;
		}
	}


	return 0;
}