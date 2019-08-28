#ifndef H_HASH
#define H_HASH

typedef struct HashTable HashTable;
typedef struct linkedList linkedList;
typedef enum {OK, AllocationError, NullPointer, WrongIndex, NotFound,Exist} AdtStatus; 
typedef unsigned long (* hash)( void *element);
typedef int (* compare )(void *, void *);
typedef int (* forEach)(void* val);

HashTable* createHashTable(unsigned long (* hash)( void *element),unsigned long capacity,int (* compare )(void *, void *));
int listFind(HashTable* hashT, int offset, linkedList** current, linkedList** previous, void* key);
AdtStatus hashTableInsert(HashTable* hashT,void* key,void* val,int update);
AdtStatus hashTableDelete(HashTable* hashT,void* key);
AdtStatus hashTableDestroy(HashTable* hashT);
AdtStatus hashTableForEach(HashTable* hashT,forEach func);
AdtStatus hashTableFind(HashTable* hashT,void* key,void** val);

#endif