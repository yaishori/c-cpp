#include "meeting.h"
#include "calendar_t.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int cont = 1;				
	int option;
	Calendar_t* da;
	Meeting_t* meet;
	int capacity;
	float begin;
	float end;
	int room;
	int created=0;
	int isInsert;
	char* name="file";
	while (cont) {
		printf("Choose option: \n");
		printf("1: create calendar  \n");
		printf("2: insert meeting   \n");
		printf("3: remove meeting  \n");
		printf("4: find meeting \n");
		printf("5: print calendar \n");
		printf("6: load file \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("enter capacity:\n");
				scanf("%d",&capacity);
				da = createDA(capacity);
				if(da==NULL){
					printf("calendar not created:\n");
					return 0;
				}
				created=1;	
				break;
			case 2:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				printf("enter begin time:\n");
				scanf("%f",&begin);
				printf("enter end time:\n");
				scanf("%f",&end);
				printf("enter room:\n");
				scanf("%d",&room);
				meet = createMeeting(begin,end,room);
				if(meet==NULL){
					printf("meeting not created:\n");
				}
				isInsert= insertMeeting(da,meet);
				if(!isInsert)
					printf("insert not succ\n");
				break;
			case 3:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				printf("enter begin time:\n");
				scanf("%f",&begin);
				removeMeeting(da,begin);
				break;
			case 4:
				if(!created){
					printf("please create calendar first.\n");
					break;
				}
				printf("enter begin time:\n");
				scanf("%f",&begin);
				meet = findMeeting(da,begin);
				if(meet==NULL){
					printf("not found:\n");
				}
				else{
					printf("meeting information:\n");
					printf("meeting begin:%f meeting end:%f meeting room:%d \n",meet->begin,meet->end,meet->room);
				}
				break;
			case 5:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				printDA(da);
				break;
			case 6:
				if(!created){
				printf("please create calendar first.\n");
				break;
				}
				loadFromFile(name,da);
				break;
			default:
				if(created){
				saveToFile(name,da);
				destoryDA(da);
				}
				cont = 0;	break;
		}
	}
	/*Meeting_t* meet1;
	Meeting_t* meet2;
	Meeting_t* meet3;
	Meeting_t* meet4;
	int capacity;
	Calendar_t* da;
	meet1=createMeeting(3.0,4.0,4);
	meet2=createMeeting(7.0,8.0,4);
	meet3=createMeeting(5.0,6.0,4);

	printf("enter capacity:\n");
	scanf("%d",&capacity);
	da = createDA(capacity);
	if(da==NULL)
		return 0;
	insertMeeting(da, meet1);
	insertMeeting(da, meet2);
	insertMeeting(da, meet3);
	removeMeeting(da,meet1);
	meet4=findMeeting(da,meet2);
	printf("meeting begin:%f", meet4->begin);

	printDA(da);*/

	return 0;
}