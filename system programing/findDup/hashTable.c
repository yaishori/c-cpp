#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"


struct linkedList{
	void* key;
	void* value;
	linkedList* next;
};


struct HashTable{
	unsigned long capacity;
	hash hashFunc;
	compare compare;
	linkedList** list;
};




HashTable* createHashTable(unsigned long (* hash)( void *element),unsigned long capacity,int (* compare )(void *, void *)){
	HashTable* hashT= malloc(sizeof(HashTable));
	if(hashT==NULL){
		return NULL;
	}
	hashT->list = calloc(capacity,sizeof(linkedList*));
	if(hashT->list==NULL){
		free(hashT);
		return NULL;
	}
	hashT->hashFunc =hash;
	hashT->capacity=capacity;
	hashT->compare=compare;

	return hashT;
}

static void push(linkedList** head, void* key,void* val)  
{  	
	linkedList** myhead;
	linkedList* newNode; 
	if(head==NULL){
		return;
	}
	myhead=head;
    newNode = (linkedList*) malloc(sizeof(struct linkedList)); 
    if(newNode==NULL){
		return;
	}
    newNode->key = key;
    newNode->value = val;  
  	newNode->next = (*myhead);  
  	(*myhead) = newNode;  
}  
int listFind(HashTable* hashT, int offset, linkedList** current, linkedList** previous, void* key){
	*previous = NULL;
	*current = hashT->list[offset];

	while(*current != 0){
		if(!(hashT->compare((*current)->key,key))){
				return 0;
			}
		else{
			*previous = *current;
			*current = (*current)->next;
		}
	}
	return 1;
} 

AdtStatus hashTableInsert(HashTable* hashT,void* key,void* val,int update){
	linkedList* current;
	linkedList* previous;
	unsigned long offset;
	if(hashT==NULL || hashT->list==NULL){
		return NullPointer;
	}
	offset = hashT->hashFunc(key)%(hashT->capacity);
	if(!(listFind(hashT,offset,&current,&previous,key))){
		if(update){
		current->value=val;
		}
		else{return Exist;}
	}
	else{
	push(&(hashT->list[offset]),key,val);
	}
	return OK;
}

AdtStatus hashTableDelete(HashTable* hashT,void* key){
	linkedList* current;
	linkedList* previous;
	unsigned long offset;
	if(hashT==NULL || hashT->list==NULL){
		return NullPointer;
	}
	offset= hashT->hashFunc(key)%(hashT->capacity);
	if(!(listFind(hashT,offset,&current,&previous,key))){
		if(hashT->list[offset]->next == NULL){
			hashT->list[offset]=NULL;
			free(current);
			return OK;
		}
		else if(previous==NULL && current->next!=NULL){
			hashT->list[offset]=current->next;
			free(current);
			return OK;
		}
		else if(previous!=NULL){
			previous->next=current->next;
			free(current);
			return OK;
		}

	}
	return NotFound;
}

AdtStatus hashTableDestroy(HashTable* hashT){
	linkedList* current;
	int i;
	if(hashT==NULL || hashT->list==NULL){
		return NullPointer;
	}
	for(i=0;i<hashT->capacity;i++){

		while(hashT->list[i]!=NULL){
			current=hashT->list[i];
			hashT->list[i]=hashT->list[i]->next;
			free(current);
		}
		free(hashT->list[i]);
	}
	free(hashT);
	return OK;
}

AdtStatus hashTableForEach(HashTable* hashT,forEach func){
	linkedList* list;
	int i;
	if(hashT==NULL || hashT->list==NULL){
		return NullPointer;
	}
	for(i=0;i<hashT->capacity;i++){
		list=hashT->list[i];
		while(list!=0){
			func(list->value);
			list=list->next;
		}
	}
	return OK;
}

AdtStatus hashTableFind(HashTable* hashT,void* key,void** val){
	linkedList* current;
	linkedList* previous;
	unsigned long offset= hashT->hashFunc(key)%(hashT->capacity);
	if(!(listFind(hashT,offset,&current,&previous,key))){
		*val=current->value;
		return OK;
	}
	else{
		return NotFound;
	}
}

