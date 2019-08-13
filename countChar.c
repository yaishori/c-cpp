#include <stdio.h>
#include <ctype.h>

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

int main(){
char* name="file.txt";	
countChar(name);
return 0;
}
