struct linkedList{
	void* key;
	void* value;
	linkedList* list;
};

typedef struct linkedList linkedList;

struct HashTabale{
	unsigned long capacity;
	unsigned long (* hash)( void *element);
	linkedList** list;
	int (* compare )(void *, void *);
};

typedef struct HashTabale HashTabale;

HashTabale* createHashTable(unsigned long (* hash)( void *element),unsigned long capacity,int (* compare )(void *, void *)){
	HashTabale* hashT= malloc(sizeof(HashTabale));
	hashT->list = malloc(capacity*sizeof(linkedList));
	hashT->hash =hash;
	hashT->capacity;
	hashT->compare=comapre;

	return hashT;
	}