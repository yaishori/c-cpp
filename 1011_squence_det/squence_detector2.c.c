#include <stdio.h>

/*1011 sequence detector overlapping
 A - start state
*/

typedef enum
{
    A_State,
    B_State,
    C_State,
    D_State
} State;

State a_func(int c);
State b_func(int c);
State c_func(int c);
State d_func(int c);
int map_func(int c);

State curr_state= A_State;
int c;

State a_func(int c){
	if(c=='1'){
		curr_state=B_State;
	}
	printf("0");
	return curr_state;
}

State b_func(int c){
	if(c=='0'){
		curr_state=C_State;
	}
	printf("0");
	return curr_state;
}

State c_func(int c){
	if(c=='0'){
		curr_state=A_State;
	}
	else{
		curr_state=D_State;
	}
	printf("0");
	return curr_state;
}

State d_func(int c){
	if(c=='0'){
		curr_state=C_State;
		printf("0");
	}
	else{
		curr_state=B_State;
		printf("1");
	}
	
	return curr_state;
}

int map_func(int c){
	if(curr_state == A_State){
		curr_state= a_func(c);
	}
	else if(curr_state == B_State){
		curr_state= b_func(c);
	}
	else if(curr_state == C_State){
		curr_state= c_func(c);
	}
	else{
		curr_state= d_func(c);
	}
	
	return 0;
}

int main(){
	printf("please enter a sequence of of 1's and 0's\n");
	c=getchar();
	while (c == '0' || c == '1'){
			map_func(c);
			c=getchar();
	}
	return 0;
}





