
#include <stdio.h>
#include <string.h>

void reverseString(char* str) 
{ 
    int len, i; 
    char* first;
	char* last; 
	char tmp; 
   
    len=strlen(str); 
 
    first=str; 
    last=str; 

    for(i=0; i<(len - 1);i++){
        last++; 
   	}
    for(i=0; i<(len / 2);i++) { 
  
        tmp= *last; 
        *last= *first; 
        *first= tmp; 
        first++; 
        last--; 
    } 
} 
/*  not to use - I found better way.

int comp(char* str1, char* str2)
{
	int ret;
	while (*str1&&*str2)
	{
		if (*str1!=*str2);
			ret=0;
			break;
		]
		str1++;
		str2++;
	}
	ret = (*Y == '\0') ? 1:0;
	return ret;
}
*/




char* int2bin(int x,char* str){
	char bin;
	char* p=str;
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
 	reverseString(str);
 	printf("%s\n",str);
	return str;
}


int bin2int(char* str){
	int i;
	int len= strlen(str);
	int ret =0;
	int pow=1;
	for(i=len-1; i>=0; i--){
		ret= ret+(str[i]-48)*pow;
		pow=pow*2;
	}
	printf("%d\n",ret);
	return ret;
}

char* squeeze(char* s1,char* s2){
	char* p;
	char* p2;
	while(*s2 != '\0'){
		char* p= s1;
		char* p2= s1; /*save the loction we need to change*/
		while(*p != '\0'){
			if(*s2!=*p){
				*p2=*p;
				 p2++;		
			}
			p++;
		}
		*p2='\0';
		s2++;
	}
	printf("%s\n",s1);
	return s1;
}


int locatin(char* str1,char* str2){
	int len =strlen(str2);
	int count = 0;
	int flag = 0;
	int ret;
	while(*str1 != '\0'){
		if(!memcmp(str1,str2,len)){     /*if return 0 so str1 and str2 are equal*/
		flag=1;
		break;
		}
	count++;
	str1++;
	}
	ret = (flag) ? count : -1;
	printf("%d\n",ret);
	return ret;	
}



int main(){
	int x;
	char str[33];
	char str2[33];
	int cont = 1;				
	int option;
	
	while (cont) {
		printf("Choose option: \n");
		printf("1: int2bin  \n");
		printf("2: bin2int   \n");
		printf("3: squeeze  \n");
		printf("4: location \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter integer:\n");
				scanf("%d",&x);
				int2bin(x,str);	break;
			case 2:
				printf("enter bin:\n");
				scanf("%s",str);
				bin2int(str);	break;
			case 3:
				printf("enter first string:\n");
				scanf("%s",str);
				printf("enter second string:\n");
				scanf("%s",str2);
				squeeze(str,str2);	break;
			case 4:
				printf("enter first string:\n");
				scanf("%s",str);
				printf("enter second string:\n");
				scanf("%s",str2);
				locatin(str,str2);	break;
			default: cont = 0;	break;
		}
	}
return 0;
}