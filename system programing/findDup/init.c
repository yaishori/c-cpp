#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"
#include "findDup.h"
#include "md5.h"

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


int main(int argc,char* argv[]){
	HashTable* hashT;
	hashT =createHashTable(myHash,1024,elementCom);
	listFilesRecursively(argv[1],hashT);
}