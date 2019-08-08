#include <stdio.h>
#include <string.h>


int myStrcmp(char *X, char *Y)
{
	while(*X)
	{
		if (*X != *Y){
			break;
		}

		X++;
		Y++;
	}
	return *X - *Y;
}

char* myStrcat(char* destination, char* source)
{
	char* p = destination + strlen(destination);

	
	while (*source != '\0'){
		*p++ = *source++;
	}

	
	*p = '\0';

	return destination;
}

char* myStrcpy(char* destination, const char* source){
		char* p = destination;
		while(*source){
			*p=*source;
			p++;
			source++;
		}
		*p='\0';

		return destination;
}


int main(){
	char x[32];
	char y[32];
	char i[32];
	char j[32];
	int checkCamp;
	char* checkCat;
	char* checkCpy;
	printf("enter string:\n");
	scanf("%s",x);
	printf("enter another string:\n");
	scanf("%s",y);

	printf("enter string for strcpy:\n");
	scanf("%s",i);
	printf("enter another string for strcpy:\n");
	scanf("%s",j);

	checkCamp=myStrcmp(x,y);
	checkCat=myStrcat(x,y);
	checkCpy=myStrcpy(i,j);

	printf("checkCamp= %d\n", checkCamp);
	printf("checkCat= %s\n", checkCat);
	printf("checkCpy= %s\n", checkCpy);

}



