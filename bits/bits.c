#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bits.h"


int calculate(bitsFunc f,int bitIndex,bitStruct* bitS){
	if(bitS==NULL){
		return -1;
	}
	return f(bitIndex,bitS); 
}

void reverseString(char* str) 
{ 
    int len, i; 
    char *begin, *end, tmp; 
   
    len = strlen(str); 
 
    begin = str; 
    end = str; 

    for (i = 0; i < len - 1; i++){
        end++; 
   	}
    for (i = 0; i < len / 2; i++) { 
  
        tmp = *end; 
        *end = *begin; 
        *begin = tmp; 
        begin++; 
        end--; 
    } 
} 

void int2bin(int x,int numOfFe){
	char bin;
	char* p=malloc(numOfFe*sizeof(char));
	char* p2=p;
	if(x==0){
		*p='0';
		p++;
	}
 	while(x!=0){
 		bin=(x%2==0) ? '0':'1';
		*p=bin;
 		p++;
 		x=x/2;
 	}
 	*p='\0';
 	reverseString(p2);
 	printf("%s ",p2);
 	free(p2);
}

bitStruct* createBitStruct(int numOfFe){
	int mulOfMalloc;
	int i;
	bitStruct* bitS = malloc(sizeof(bitStruct));
	if(bitS==NULL){
		return NULL;
	}
	bitS->numOfFe=numOfFe;
	mulOfMalloc= numOfFe/32;
	mulOfMalloc++;
	bitS->fe = malloc(mulOfMalloc*sizeof(int));
	if(bitS->fe==NULL){
		free(bitS);
		return NULL;
	}
	for(i=0;i<mulOfMalloc;i++){
		bitS->fe[i]=0;
	}
	return bitS;
}

int bitOn(int bitIndex,bitStruct* bitS){
	int indexBit=(bitIndex)%32;
	int index=bitIndex/32;
	int i =1;
	if(bitS==NULL){
		return -1;
	}
	if(bitIndex>(bitS->numOfFe)){
		return -1;
	}
	i= i<<indexBit;
	bitS->fe[index]= (bitS->fe[index])|i;
	return 1;
}

int bitOff(int bitIndex,bitStruct* bitS){
	int indexBit=(bitIndex)%32;
	int index=bitIndex/32;
	int i =1;
	if(bitS==NULL){
		return -1;
	}
	if(bitIndex>bitS->numOfFe){
		return -1;
	}
	i= i<<indexBit;
	i=~i;
	bitS->fe[index]= (bitS->fe[index])&i;
	return 1;
}

int bitStatus(int bitIndex,bitStruct* bitS){
	int i =1;
	int tmpFe;
	int indexBit=(bitIndex)%32;
	int index=bitIndex/32;
	if(bitS==NULL){
		return -1;
	}
	if(bitIndex>(bitS->numOfFe)){
		return -1;
	}
	i= i<<indexBit;
	tmpFe=(bitS->fe[index])&i;
	if(tmpFe>0){
		return 1;
	}
	if(tmpFe==0){
		return 0;
	}
}

void printBits(bitStruct* bitS){
	int i;
	int mulOfMalloc;
	if(bitS==NULL){
		printf("bitS-null pointer\n");
	}
	mulOfMalloc= (bitS->numOfFe)/(8*sizeof(int));
	mulOfMalloc++;
		for(i=0;i<mulOfMalloc;i++){
			int2bin(bitS->fe[mulOfMalloc-i-1],mulOfMalloc);
		}
	return;	
}

void destroyBitStruct(bitStruct* bitS){
	if(bitS==NULL){
		return;
	}
	free(bitS->fe);
	free(bitS);
	return;
}



