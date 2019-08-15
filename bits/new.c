#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numOfFe;
	int* fe;	
}bitStruct;

bitStruct* createBitStruct(int numOfFe);
int bitOn(int bitIndex,bitStruct* bitS);
int bitOff(int bitIndex,bitStruct* bitS);
int bitStatus(int bitIndex,bitStruct* bitS);
void destroyBitStruct(bitStruct* bitS);

typedef int (*bitsFunc)(int bitIndex,bitStruct* bitS);

int calculate(bitsFunc f,int bitIndex,bitStruct* bitS){
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
	int index=(bitIndex)/32;
	int i =1;
	if(bitIndex>(bitS->numOfFe)){
		return -1;
	}
	i= i<<bitIndex;
	bitS->fe[index]= (bitS->fe[index])|i;
	return 1;
}

int bitOff(int bitIndex,bitStruct* bitS){
	int index=(bitIndex)/32;
	int i =1;
	if(bitIndex>bitS->numOfFe){
		return -1;
	}
	i= i<<bitIndex;
	i=~i;
	bitS->fe[index]= (bitS->fe[index])&i;
	return 1;
}

int bitStatus(int bitIndex,bitStruct* bitS){
	int i =1;
	int tmpFe;
	int index=(bitIndex)/32;
	if(bitIndex>(bitS->numOfFe)){
		return -1;
	}
	i= i<<bitIndex;
	tmpFe=(bitS->fe[index])&i;
	if(tmpFe>0){
		return 1;
	}
	if(tmpFe==0){
		return 0;
	}
}

int main(){
	bitStruct* bitS;
	int fe;
	int cont = 1;				
	int option;
	int res;
	int bitIndex;
	int i;
	int mulOfMalloc;
	bitsFunc funcArray[3]={bitOn,bitOff,bitStatus};
	printf("enter num of fe\n");
	scanf("%d",&fe);
	bitS = createBitStruct(fe);
	if(bitS==NULL){
		printf("null prointer\n");
	}

	while (cont) {
		printf("Choose option: \n");
		printf("1: bit on \n");
		printf("2: bit off   \n");
		printf("3: bit status  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[0],bitIndex,bitS);
				if(res==-1){
					printf("not possible index\n");
				}
				mulOfMalloc= (bitS->numOfFe)/(8*sizeof(int));
				mulOfMalloc++;
				for(i=0;i<mulOfMalloc;i++){
					int2bin(bitS->fe[i],mulOfMalloc);
				}
				break;
			case 2:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[1],bitIndex,bitS);
				if(res==-1){
					printf("not possible index\n");
				}
				mulOfMalloc= (bitS->numOfFe)/(8*sizeof(int));
				mulOfMalloc++;
				for(i=0;i<mulOfMalloc;i++){
					int2bin(bitS->fe[i],mulOfMalloc);
				}
				break;
			case 3:
				printf("enter bit index\n");
				scanf("%d",&bitIndex);
				res = calculate(funcArray[2],bitIndex,bitS);
				if(res==-1){
					printf("not possible index\n");
				}
				if(res==0){
					printf("bit off\n");
				}
				if(res==1){
					printf("bit on\n");
				}

				break;

			default:
				cont = 0;	break;
		}
	}

	return 0;
}



