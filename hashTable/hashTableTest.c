#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

typedef enum {Pass,Fail} testResult; 

unsigned long myHash(void *str)
    {
    	unsigned char *myStr= (unsigned char*)str;
        unsigned long hash = 5381;
        int c;

        while (c = *myStr++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }


int elementCom(void *elemA, void *elemB){
	int ret=strcmp((char*)elemA, (char*)elemB);
	return ret;
}

int ForEachPrint(void* value){
	printf("%d ",*(int*)value);
}

int ForEachFunc(void* value){
	*(int*)value=*(int*)value+1;
}

testResult testCreate(){
    HashTable* hashT=createHashTable(myHash,3, elementCom);
    if(hashT==NULL){
        printf("testCreate\n");
        return Fail;
    }
    hashTableDestroy(hashT);
    return Pass;
}

testResult insertNULLhashTest(){
    char* y="yyy";
    int x=2;
    HashTable* hashT=NULL;

    AdtStatus status= hashTableInsert(hashT,y,&x);
    if(status==OK){
        printf("insertNULLhashTest\n");
        return Fail;
    }
    return Pass;
}

testResult chainingInsertTest(){
    char* y[]={"x","g","t","d","s","j","c"};
    int x[]={1,2,3,4,5,6,7};
    int i;
    void* val;
    HashTable* hashT=createHashTable(myHash,3, elementCom);
    for(i=0;i<7;i++){
        hashTableInsert(hashT,y[i],&(x[i]));
        hashTableFind(hashT,y[i],&val);
        if(*(int*)val!=x[i]){
            printf("chainingInsertTest\n");
            hashTableDestroy(hashT);
            return Fail;
        }
    }
    hashTableForEach(hashT,ForEachPrint);
    hashTableDestroy(hashT);
    return Pass;
}


testResult testInsert(){
    if(insertNULLhashTest()==Fail){
        return Fail;
    }
    if(chainingInsertTest()==Fail){
        return Fail;
    }
} 




int main(){
    /*int i;
    int j;
    HashTable* hashT;
    char* mykey="abc";
    char* mykey2="ggg";
    void* ret;
    int num=2;
    int num2=3;*/
    testInsert();
    testCreate();
    

    /*hashTableInsert(hashT,mykey,&num);
    hashTableInsert(hashT,mykey2,&num2);
    hashTableForEach(hashT,ForEachPrint);
    printf("\n");
    hashTableForEach(hashT,ForEachFunc);
    printf("after adding one:\n");
    hashTableForEach(hashT,ForEachPrint);
    printf("\n");
    hashTableFind(hashT,mykey2,&ret);
    printf("find:\n");
    printf("%d\n",*(int*)ret);
    hashTableDelete(hashT,mykey2);
    printf("after delete:\n");
    hashTableForEach(hashT,ForEachPrint);
    printf("\n");
    hashTableDestroy(hashT);*/
    return 0;
}
