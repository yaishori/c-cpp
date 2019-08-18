#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"

int main(){
	int cont = 1;				
	int option;
	char* str;
	str = malloc(128);
	if(str==NULL){
		printf("null pointer\n");
		return;
	}
	

	while (cont) {
		printf("Choose option: \n");
		printf("1: packing \n");
		printf("2: packing with fields  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter string\n");
				scanf("%s",str);
				packing(str);
				printStr(str);
				break;
			case 2:
				printf("enter string\n");
				scanf("%s",str);
				packingFields(str);
				printStr(str);
				break;
			default:
				cont = 0;
				free(str);
				break;
		}
	}

	return 0;
}