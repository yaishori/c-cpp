#include <stdio.h>
#include <stdlib.h>
#include "nlines.h"

void lastLines(int n,char* name){
	int line;
	long int* arr;
	char str[512]; /*save offset - insert module n */
	long int pos;
	int i=0;
	int j=0;
	FILE* fp =fopen(name,"r");
	if (fp==NULL){
	printf("null pointer\n");
	}	
	arr=malloc(n*sizeof(long int));
	fseek(fp,0,0);
		
		while(1){
      		pos=ftell(fp);
			printf("%d\n",i%n);
			arr[i%n]=pos;
				if(fgets(str,512,fp)==NULL){
					break;
				}
			i++;;
		}
		for(i=0;i<n;i++){
			printf("%ld\n",arr[i]);
		}

	pos=arr[i%n];
	fseek(fp,0,0);
	fseek(fp,pos,1);
		while(1){
			if(fgets(str,512,fp)==NULL){
					break;
			}
			printf("%s\n",str);
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



