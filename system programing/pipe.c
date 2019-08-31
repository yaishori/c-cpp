#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(){ 

	int fd1[2]; 
	int fd2[2];
	char str1[]="hi"; 
	char str2[] = "bye"; 
	char str3[3];
	char str4[3];
	pid_t pid; 
	pipe(fd1);
	pipe(fd2);

	pid = fork(); 

	if (pid < 0) 
	{ 
		fprintf(stderr, "failed" ); 
		return 0; 
	} 

	else if (pid > 0) 
	{ 
		 
		close(fd1[0]); 
		write(fd1[1], str1, strlen(str1)+1); 
		close(fd1[1]); 

		wait(NULL); 
		close(fd2[1]); 
		read(fd2[0], str3,strlen(str2)+1);
		printf("child  send: %s\n", str3); 
		close(fd2[0]); 
	} 

	else
	{ 
		close(fd1[1]);
 
		read(fd1[0], str4, strlen(str1)+1); 
		printf("parent send: %s\n", str4); 


		close(fd1[0]); 
		close(fd2[0]); 

		write(fd2[1], str2, strlen(str2)+1); 
		close(fd2[1]); 
	} 

	return 1;
} 
