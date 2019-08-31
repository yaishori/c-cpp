#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) {
	while(1){
	char* command[128];
	printf("->");
	scanf("%s",*command);
	    if(fork()==0){
	    	execvp(*command, argv);
		}
		else{
			wait(NULL);
		}
	}	

    return 0;
}