#include <stdio.h>
#include <stdlib.h>
#include "nlines.h"

void lastLines(int n,char* name){
	int line;
	long int* arr;
	char str[512]; /*save offset - insert module n */
	long int pos;
	long int end;
	int i=0;
	int j=0;
	FILE* fp =fopen(name,"r");
	if (fp==NULL){
	printf("null pointer\n");
	}	
	arr=malloc(n*sizeof(long int));
	fseek(fp,0,2);
	end=ftell(fp);
	fseek(fp,0,0);	
		while(!feof(fp)){
      		pos=ftell(fp);
			printf("%d\n",i%n);
			arr[i%n]=pos;
			fgets(str,512,fp);
			pos=ftell(fp);
				if(pos==end){
					break;
				}
			printf("%ld\n",arr[i%n]);
			i++;
				
			
		}

	printf("\n");
	printf("pos:%ld\n",arr[i%n]);
	pos=arr[(i+1)%n];
	printf("pos:%ld\n",arr[(i+2)%n]);
	fseek(fp,0,0);
	fseek(fp,pos,1);
		while(!feof(fp)){
			fgets(str,512,fp);
			printf("%s\n",str);
			pos=ftell(fp);
			if(pos==end){
				break;
			}
			
      	}
	free(arr);
	return;
}


void countChar(char* name){
	int upperChar[26];
	int lowerChar[26];
	int ic;
	char ch;
	int i;
	FILE* fp =fopen(name,"r");
	if (fp==NULL){
	printf("null pointer\n");
	}
	for (i = 0; i < 26; i++){
		upperChar[i]=0;
		lowerChar[i]=0;
	}
   do {
      ic = fgetc(fp);
      if(feof(fp) ) {
         break ;
      }
	  ch=ic;
      if((ch >='A') && (ch <='Z')){
		  upperChar[ch -'A']++;
	  }
	  else if((ch >='a') && (ch <='z')){
		 lowerChar[ch-'a']++;
	  }
   } while(1);
   for (i = 0; i < 26; i++) {
		if(lowerChar[i]>0){
			printf("%c", (i + 'a'));
			printf(": %d\n", lowerChar[i]);
		}
		if(upperChar[i]>0){
			printf("%c", (i + 'A'));
			printf(": %d\n", upperChar[i]);
		}
   }
   fclose(fp);
   return;
}



