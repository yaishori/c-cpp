#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bits.h"


int main(){
	bitStruct* bitS;
	int fe;
	int cont = 1;				
	int option;
	int res;
	int bitIndex;

	bitsFunc funcArray[3]={bitOn,bitOff,bitStatus};
	printf("enter num of fe\n");
	scanf("%d",&fe);
	bitS = createBitStruct(fe);
	if(bitS==NULL){
		printf("null pointer\n");
	}

	while (cont) {
		printf("Choose option: \n");
		printf("1: bit on \n");
		printf("2: bit off   \n");
		printf("3: bit status  \n");
		printf("4: printBits  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[0],bitIndex,bitS);
				if(res==-1){
					printf("not possible index or bitS-null pointer\n");
				}
				break;
			case 2:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[1],bitIndex,bitS);
				if(res==-1){
					printf("not possible index or bitS-null pointer\n");
				}
				break;
			case 3:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[2],bitIndex,bitS);
				if(res==-1){
					printf("not possible index or bitS-null pointer\n");
				}
				if(res==0){
					printf("bit off\n");
				}
				if(res==1){
					printf("bit on\n");
				}
				break;
			case 4:
				printBits(bitS);
				break;

			default:
				cont = 0;
				destroyBitStruct(bitS);
				break;
		}
	}

	return 0;
}