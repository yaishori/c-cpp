#include "darray_generic.h"
#include <stdio.h>
#include <stdlib.h>


struct darray{
	void **arr;
	int capacity;
	int initial_capacity;
	int index;
};

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
enum AdtStatus darrayCreate(darray **dArr, size_t initial_capacity){
	void* myArray= malloc((initial_capacity) * sizeof(void*));
	if(myArray!=NULL){
		darray* da=malloc(sizeof(darray));
		if(da==NULL){
			free(myArray);
			return AllocationError;
		}
		else{
			da->capacity=initial_capacity;
			da->initial_capacity= initial_capacity;
			da->index=0;
			da->arr=myArray;
			*dArr=da;

			return OK;
		}
	}
	else{
		return AllocationError;
	}
}

enum AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context){
	int i;
	if(dArr==NULL){
		return NullPointer;
	}
	for(i=0;i<dArr->index;i++){
		destroyFunc(dArr->arr[i], context);
	}
	free(dArr->arr);
	free(dArr);
	return OK;
}

/* Add number to the end. */
enum AdtStatus darrayAdd(darray *dArr,  void  *_item){
	void *p2=dArr->arr;
	if(dArr->index==dArr->capacity){
		p2 = realloc(dArr->arr,((dArr->capacity)*2)*sizeof(void*));
		if(p2!=NULL){
		dArr->arr=p2;
		(dArr->capacity)=(dArr->capacity)*2;		
		}
		else
			return AllocationError;

	}
	/*printf("idex=%d\n",dArr->index);*/
	dArr->arr[dArr->index]=_item;
	dArr->index = (dArr->index)+1;

	return OK;
}

/* Delete number from the end, hand-over the deleted item 
   in a variable pointed to by _item */
enum AdtStatus darrayDelete(darray *dArr,  void  **_item){
	if(dArr==NULL){
		return NullPointer;
	}
	*_item= (dArr->arr[dArr->index]);
	dArr->index = (dArr->index)-1;
	if((dArr->index<(3/8) * (dArr->capacity))&& dArr->capacity>dArr->initial_capacity){
		(dArr->capacity)=(dArr->capacity)*3/4;
	}

	return OK;

}


enum AdtStatus darrayGet(darray *dArr, size_t _index, void **_item){
	if(dArr==NULL){
		return NullPointer;
	}
	if((_index>dArr->index)||(_index<0)){
		return WrongIndex;
	}
	*_item=dArr->arr[_index];

	return OK;
}

enum AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item){
	if(dArr==NULL){
		return NullPointer;
	}
	if((_index>dArr->index)||(_index<0)){
		return WrongIndex;
	}
	dArr->arr[_index]=_item;

	return OK;
}

enum AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems){
	if(dArr==NULL){
		return NullPointer;
	}
	*_numOfItems=(dArr->index);

	return OK;
}

int partition( darray *dArr, int left, int right,elementCompare compareFunc) {
    void *temp;
	int retCompare;
    void* pivot;
    pivot = dArr->arr[right];
    
    while(1){
    	
        while(compareFunc(dArr->arr[right],pivot)>0){
            right--;
        }
        while(compareFunc(dArr->arr[left],pivot)<0){
            left++;
        }
        if( left < right ){
            temp = dArr->arr[right];
	        dArr->arr[right] = dArr->arr[left];
	        dArr->arr[left] = temp;
            }
        else{
            return left;
        }
    }
}

void quicksort( darray *dArr, int left, int right, elementCompare compareFunc){
    int m;
    if( left < right ) {
        m = partition( dArr, left, right, compareFunc);
        quicksort( dArr, left, m-1,compareFunc);
        quicksort( dArr, m+1, right,compareFunc);
    }
}

/* in place (ascending) sorting an array of size arraySize */
enum AdtStatus darraySort(darray *dArr,elementCompare compareFunc){
	int left; 
	int right; 
	if(dArr==NULL){
		return NullPointer;
	}
	left=0;
	right=(dArr->index)-1;
	quicksort(dArr, left, right,compareFunc);
    return OK;
}