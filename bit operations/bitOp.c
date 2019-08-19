#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitOp.h"


void printBin(unsigned char x){
	int i;
	for(i = 7; i >= 0; i-- ) {
   	 	printf( "%d", ( x >> i ) & 1 ? 1 : 0 );
	}
	printf("\n");
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

void int2bin(int x){
	char bin;
	char* p=malloc(256);
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
 	printf("%s\n",p2);
 	free(p2);
}

unsigned char invertBits(unsigned char x){
	unsigned char y = ~0;
	x=x^y;
	return x;
}

unsigned char rotateRight(unsigned char x, int num){
	unsigned char tmp = x;
	tmp = tmp << (8-(num % 8));
	x = x >>(num % 8);
	x= x | tmp;
	return x;

}

unsigned char setbits(unsigned char x, int p, int n, unsigned char y){
	unsigned char tmp = x;
	tmp =tmp>>p;
	tmp = tmp<<p;
	x = x<<(8-p+n);
	x = x>>(8-p+n);
	y = y<<(8-n);
	y =y>>(8-p);
	x = x|tmp;
	x = x|y;
	return x;
	
}

unsigned int setItoJ(unsigned int w, int i, int j, unsigned int value){
	unsigned int count;
	unsigned int tmp=w;
	unsigned int val=value;
	w= w>>(31 - i);
	w= w<<(31 - i);
	tmp= tmp<<(31 - j);
	tmp= tmp>>(31 - j);
	w= w|tmp;
		for (count=0; count < j-i+1; count){
			val= val<<1;
			val= val | value;
			count++;
		}
		val = val<<i;
		w= w|val;
		return w;
}
/*
int main(){
	unsigned char c='a';
	unsigned int x=255;
	printBin(c);
	c= invertBits(c);
	printBin(c);
	c= rotateRight(c,2);
	printBin(c);
	c = setbits(c,6,3,x);
	printBin(c);
	printBin(c);
	c= setItoJ(c,2,4,1);
	printBin(c);

*/

