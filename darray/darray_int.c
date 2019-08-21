#include "darray_int.h"
#include <stdio.h>
#include <stdlib.h>


struct darray{
	int *arr;
	int capacity;
	int initial_capacity;
	int index;
};

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
enum AdtStatus darrayCreate(darray **dArr, size_t initial_capacity){
	int* myArray= malloc((initial_capacity) * sizeof(int));
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

enum AdtStatus darrayDestroy(darray *dArr){
	if(dArr==NULL){
		return NullPointer;
	}
	free(dArr->arr);
	free(dArr);
	return OK;
}

/* Add number to the end. */
enum AdtStatus   darrayAdd(darray *dArr,  int  _item){
	int *p2=dArr->arr;
	if(dArr->index==dArr->capacity){
		p2 = realloc(dArr->arr,((dArr->capacity)*2)*sizeof(int));
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
enum AdtStatus   darrayDelete(darray *dArr,  int* _item){
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


enum AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item){
	if(dArr==NULL){
		return NullPointer;
	}
	if((_index>dArr->index)||(_index<0)){
		return WrongIndex;
	}
	*_item=dArr->arr[_index];

	return OK;
}

enum AdtStatus   darraySet(darray *dArr, size_t _index, int  _item){
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


/* in place (ascending) sorting an array of size arraySize */
enum AdtStatus darraySort(darray *dArr){
	int i, j, temp;
	int isSwapped; 
	if(dArr==NULL){
		return NullPointer;
	}
   for (i = 0; i < (dArr->index)-1; i++){ 
   		isSwapped = 0;          
       for (j = 0; j < (dArr->index)-i-1; j++){ 
           if (dArr->arr[j] > dArr->arr[j+1]){
	           	temp = dArr->arr[j];
	           	dArr->arr[j] = dArr->arr[j+1];
	           	(dArr->arr[j+1]) = temp;
	            isSwapped = 1;
           }
       }

       if (!isSwapped){
        break;  
   		}
    }

    return OK;
}