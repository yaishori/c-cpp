#include <stdio.h>
#include <stdlib.h>
#include "nlines.h"

int main(){
char* name="file";
char* name1="file.txt";	
int n;	
printf("enter n:\n");
scanf("%d",&n);
lastLines(n,name);
countChar(name1);
return 0;
}