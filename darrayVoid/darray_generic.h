/****************************************************************************
    Created by: Yuval Shaul.
    Creation date:      12.8.2019
    Description: Dynamic array, that grows and shrinks automatically.
*****************************************************************************/
#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>

enum AdtStatus {OK, AllocationError, NullPointer, WrongIndex}; 
typedef void (* elementDestroy)(void *_elem, void *context);
typedef int (* elementCompare)(void *_elemA, void *_elemB);
/* forward declaration of the darray type */
typedef struct darray darray;

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
enum AdtStatus darrayCreate(darray **dArr, size_t initial_capacity);
enum AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context);

/* Add number to the end. */
enum AdtStatus darrayAdd(darray *dArr,  void  *_item);

/* Delete number from the end, hand-over the deleted item 
   in a variable pointed to by _item */
enum AdtStatus darrayDelete(darray *dArr,  void  **_item);

enum AdtStatus darrayGet(darray *dArr, size_t _index, void **_item);
enum AdtStatus darraySet(darray *dArr, size_t _index, void  *_item);
enum AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems);

/* in place (ascending) sorting an array of size arraySize */
enum AdtStatus darraySort(darray *dArr,elementCompare compareFunc);
#endif