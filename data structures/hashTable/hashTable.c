#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList linkedList;

typedef unsigned long (* hash)( void *element);
typedef int (* compare )(void *, void *);
typedef int (* forEach)(void* val);


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

typedef struct HashTable HashTable;


 unsigned long myHash(void *str)
    {
    	unsigned char *myStr= (unsigned char*)str;
        unsigned long hash = 5381;
        int c;

        while (c = *myStr++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }


int elementCom(void *_elemA, void *_elemB){
	int ret=(*(int*)_elemA - *(int*)_elemB);
	return ret;
}
int ForEachPrint(void* value){
	printf("%d ",*(int*)value);
}

int ForEachFunc(void* value){
	*(int*)value=*(int*)value+1;
}

HashTable* createHashTable(unsigned long (* hash)( void *element),unsigned long capacity,int (* compare )(void *, void *)){
	HashTable* hashT= malloc(sizeof(HashTable));
	hashT->list = calloc(capacity,sizeof(linkedList*));
	hashT->hashFunc =hash;
	hashT->capacity=capacity;
	hashT->compare=compare;

	return hashT;
}

void push(linkedList** head, void* key,void* val)  
{  
    linkedList* newNode = (struct linkedList*) malloc(sizeof(struct linkedList));  
    newNode->key = key;
    newNode->value = val;  
  	newNode->next = (*head);  
  	(*head) = newNode;  
}  
int hashTableFind(HashTable* hashT, int offset, linkedList** current, linkedList** previous, void* key){
	*previous = NULL;
	*current = hashT->list[offset];

	while(*current != 0){
		if(hashT->compare((*current)->key,key)){
				return 1;
			}
		else{
			*previous = *current;
			*current = (*current)->next;
		}
	}
	return 0;
} 

int hashTableInsert(HashTable* hashT,void* key,void* val){
	linkedList* current;
	linkedList* previous;
	unsigned long offset= hashT->hashFunc(key)%(hashT->capacity);
	if(hashTableFind(hashT,offset,&current,&previous,key)){
		current->value=val;
	}
	else{
	push(&hashT->list[offset],key,val);
	}
	printf("%d\n",*(int*)hashT->list[offset]->key);
	printf("%d\n",*(int*)hashT->list[offset]->value);
	return 1;
}

int hashTableDelete(HashTable* hashT,void* key){
	linkedList* current;
	linkedList* previous;
	unsigned long offset= hashT->hashFunc(key)%(hashT->capacity);
	if(hashTableFind(hashT,offset,&current,&previous,key)){
		if(current->next == 0){
			free(current);
		}
		else{
		previous->next=current->next;
		free(current);
		}
	}
	return 1;
}

int hashTableDestroy(HashTable* hashT){
	linkedList** temp=hashT->list;
	linkedList* list;
	linkedList* current;
	int i;
	for(i=0;i<hashT->capacity;i++){
		list=temp[i];
		while(list!=0){
			current=list;
			list=list->next;
			free(current);
		}
		free(temp[i]);
	}
	free(hashT);
}

int hashTableForEach(HashTable* hashT,forEach func){
	linkedList* list;
	int i;
	for(i=0;i<hashT->capacity;i++){
		list=hashT->list[i];
		while(list!=0){
			func(list->value);
			list=list->next;
		}
	}
}



int main(){
	int i;
	int j;
	HashTable* hashT = createHashTable(myHash,5,elementCom);
	int mynum=2;
	int mynum2=1;
	int mykey=3;
	int mykey2=5;
	int* num=malloc(sizeof(int));
	int* num2=malloc(sizeof(int));
	int* key=malloc(sizeof(int));
	int* key2=malloc(sizeof(int));
	num=&mynum;
	num2=&mynum2;
	key=&mykey;
	key2=&mykey2;
	hashTableInsert(hashT,(void*)key,(void*)num);
	hashTableInsert(hashT,(void*)key2,(void*)num2);
	hashTableForEach(hashT,ForEachPrint);
	printf("\n");
	hashTableForEach(hashT,ForEachFunc);
	printf("after adding one:\n");
	hashTableForEach(hashT,ForEachPrint);
	printf("\n");
	hashTableDelete(hashT,(void*)key);
	hashTableForEach(hashT,ForEachPrint);
	printf("\n");
	hashTableDestroy(hashT);
	return 0;
}