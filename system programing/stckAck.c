#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 


int b(){
	printf("b\n");
	return;

}

int a(int x){
	printf("a\n");
	*(&x-1)=&b;
	return;
}



int main(int argc, char *argv[]) {
	int y=5;
	a(y);
}