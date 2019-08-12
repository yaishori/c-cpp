#include "meeting.h"
#include "calendar_t.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Meeting_t* meet1;
	Meeting_t* meet2;
	Meeting_t* meet3;
	Meeting_t* meet4;
	int capacity;
	Calendar_t* da;
	meet1=createMeeting(3.0,4.0,4);
	meet2=createMeeting(7.0,8.0,4);
	meet3=createMeeting(5.0,6.0,4);

	/*meet3=createMeeting(1.0,2.0,4);*/
	printf("enter capacity:\n");
	scanf("%d",&capacity);
	da = createDA(capacity);
	if(da==NULL)
		return 0;
	insertMeeting(da, meet1);
	insertMeeting(da, meet2);
	insertMeeting(da, meet3);
	removeMeeting(da,meet1);
	meet4=findMeeting(da.meet2);
	printDA(da);

	return 0;
}