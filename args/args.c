#include <stdio.h>
#include <ctype.h>
#include <string.h>

int number(char* str){
	int isNumber=1;
	int i;
	for (i = 0; i < strlen(str); i++){
		if(!isdigit(str[i])){
			isNumber=0;
		}
		
	}
	return isNumber;
}

int alpha(char* str){
	int isAlpha=1;
	int i;
	for (i = 0; i < strlen(str); i++){
		if(!isalpha(str[i])){
			isAlpha=0;
		}
		
	}
	return isAlpha;
}


int main(int argc,char* argv[]){
	if(argc!=3){
		printf("wrong num of args\n");
		return;
	}

	if(strlen(argv[1])==0 || strlen(argv[1])==0){
		printf("empty string\n");
		return;
	}
	
	if((alpha(argv[1])&&number(argv[2])) || (alpha(argv[2])&&number(argv[1]))){
		printf("%s %s\n", argv[1],argv[2]);
	}
	return 0;
}