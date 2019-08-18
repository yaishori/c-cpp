#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"

int packingFields(char* str){
	union un Union;
	int i;
	int len;
	int j=0;
	if(str==NULL){
		return -1;
	}
	len=strlen(str);
	for(i=0;i<len/2+1;i=i=i+2){
		Union.bitFields.m_a = str[i] - 'a';
		Union.bitFields.m_b = str[i+1] - 'a';
		str[j]=Union.ab;
		j++;
	}

	return len;
}

int packing(char* str){
	unsigned char temp = 0;
	int i;
	int len;
	if(str==NULL){
		return -1;
	}
	len=strlen(str);
	for (i = 0; i < len; i++){
		temp = str[i] - 'a';
		if (i % 2 == 0){
			temp = temp<<4;	
			str[i] = temp;
		}

		else{
			str[i - 1] = str[i - 1] | temp;
		}

	}

	return len;
}

void printStr(char* str){
	int i;
	unsigned char tmp;
	int len;
	if(str==NULL){
		return;
	}
	for(i=0; i<len;i++){
		if (i%2==0){
			tmp=str[i];
			tmp=tmp>>4;
		}
		else{
			tmp=str[i-1];
			tmp=tmp<<4;
			tmp=tmp>>4;
		}
		printf("%d\n",tmp);
	}
	return;
}