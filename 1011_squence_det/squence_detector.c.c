#include <stdio.h>

/*1011 sequence detector overlapping
 A - start state
 A-0
 B-1
 C-2
 D-3
*/



int main(){
	int print_table[4][2]={{0,0}, {0,0}, {0,0}, {0,1}};
	int transition_table[4][2]={{0,1}, {2,1}, {0,3}, {2,1}};
	int state=0;
	printf("please enter a sequence of of 1's and 0's\n");
	int c=getchar();
	while (c == '0' || c == '1'){
		printf("%d", print_table[state][c-48]);
		state=transition_table[state][c-48];
		c=getchar();
	}
	return 0;
}





