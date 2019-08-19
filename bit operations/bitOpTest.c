#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitOp.h"

int main(){
	int cont = 1;				
	int option;
	int num;
	int p;
	int n;
	unsigned char c;
	unsigned char c2;
	unsigned int x;
	

	while (cont) {
		printf("Choose option: \n");
		printf("1: invert \n");
		printf("2: rotate right  \n");
		printf("3: setbits  \n");
		printf("4: set from i to j  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter char\n");
				scanf("%hhu",&c);
				printf("before  \n");
				printBin(c);
				c=invertBits(c);
				printf("after \n");
				printBin(c);
				break;
			case 2:
				printf("enter char\n");
				scanf("%hhu",&c);
				printf("enter num to rotate\n");
				scanf("%d",&num);
				printf("before  \n");
				printBin(c);
				c=rotateRight(c,x);
				printf("after \n");
				printBin(c);
				break;
			case 3:
				printf("enter char\n");
				scanf("%hhu",&c);
				printf("enter second char\n");
				scanf("%hhu",&c2);
				printf("enter p\n");
				scanf("%d",&p);
				printf("enter n\n");
				scanf("%d",&n);
				printf("before  \n");
				printBin(c);
				c=setbits(c,p,n,c2);
				printf("after \n");
				printBin(c);
				break;
			case 4:
				printf("enter int\n");
				scanf("%u",&x);
				printf("enter 1 or 0 for value\n");
				scanf("%d",&num);
				printf("enter from index\n");
				scanf("%d",&p);
				printf("enter to index\n");
				scanf("%d",&n);
				printf("before  \n");
				int2bin(x);
				setItoJ(x,p,n,num);
				break;
			default:
				cont = 0;
				break;
		}
	}

	return 0;
}