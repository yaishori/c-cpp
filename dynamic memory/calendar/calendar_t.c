#include "meeting.h"
#include "calendar_t.h"
#include <stdio.h>
#include <stdlib.h>

Calendar_t* createDA(int capacity){
	Calendar_t* da;
	da = malloc(sizeof(Calendar_t));
	da->index=0;
	da->capacity=capacity;
	if(da==NULL){
		return NULL;
	}
	da->arr=malloc(capacity * sizeof(Meeting_t*));
	if(da->arr==NULL){
		free(da);
		return NULL;
	}
	return da;
}
 int insertMeeting(Calendar_t* da,Meeting_t* meeting){
	int i;
	int saveI=0;
	int sorted=0;
	float* tmp;
	int tmpIndex;
	Meeting_t **p2= da->arr;
	if(meeting==NULL){
		return 0;
	}
	tmpIndex=da->index;
	for(i=0;i<tmpIndex;i++){
		if (meeting->begin <= p2[i]->begin){
			if(p2[i]->begin <= meeting->end){
				free(meeting);
				return 0;
			}
		}
		if (p2[i]->begin <= meeting->begin){
			if(meeting->begin <= p2[i]->end){
				free(meeting);
				return 0;	
			}
		}    
	}

	if(da->index==da->capacity){
		p2 = realloc(da->arr,((da->capacity)*2)*sizeof(Meeting_t*));
		if(p2!=NULL){
		da->arr=p2;
		(da->capacity)=(da->capacity)*2;		
		}
		else{
			return 0;
		}

	}
	tmpIndex=da->index;
	for(i=0;i<tmpIndex;i++){
		if(meeting->begin < p2[i]->begin){
			saveI=i;
			sorted=1;
			for(tmpIndex;tmpIndex>i;tmpIndex--){
				p2[tmpIndex]=p2[tmpIndex-1];
			}
			
			p2[saveI]=meeting;
			break;

		}
	}

	if(!sorted){
	da->arr[da->index]=meeting;
	}
	da->index = (da->index)+1;

	return 1;
}



void printDA(Calendar_t* da){
	int i;
	int j=da->index;
	Meeting_t** arr = da->arr;
	printf("capacity: %d\n", da->capacity);
	printf("index: %d\n", da->index);
	printf("Calendar:\n");
	for(i=0;i<j;i++){
		printf("%d) meeting begin: %f meeting end: %f meeting room: %d \n",i,arr[i]->begin,arr[i]->end,arr[i]->room);
	}
	return;

}

Calendar_t* removeMeeting(Calendar_t* da,float begin){
	int tmpIndex=da->index;
	int i;
	Meeting_t **p2= da->arr;
	if(da->index == 0)
		return da;
	
	for(i=0;i<tmpIndex;i++){
		if(begin == p2[i]->begin){
			free(p2[i]);
			for(i;i<(tmpIndex-1);i++){
				p2[i]=p2[i+1];
			}
			free(p2[da->index]);
			da->index = (da->index)-1;
			break;

		}
	}
}


Meeting_t* findMeeting(Calendar_t* da,float begin){
	int tmpIndex=da->index;
	int i;
	Meeting_t **p2= da->arr;
	for(i=0;i<tmpIndex;i++){
		if(begin == p2[i]->begin){
			return p2[i];
		}
	}
	return NULL;
}


void destoryDA(Calendar_t* da){
	Meeting_t** arr = da->arr;
	int capacity=da->capacity;
	int i;
	for(i=0;i<capacity;i++){
		free(arr[i]);
	}
	free(da->arr);
	free(da);
	return;
}


void loadFromFile(char* name,Calendar_t* da){
	Meeting_t* meet;
	float begin;
	float end;
	int room;
	FILE* fp;
	fp=fopen(name,"r");
	while(!feof(fp)){
		fscanf(fp,"%f%f%d",&begin,&end,&room);
		meet = createMeeting(begin,end,room);
			if(meet==NULL){
				printf("meeting not created:\n");
				break;
			}
		insertMeeting(da,meet);

	}
	fclose(fp);
	return;
}

void saveToFile(char* name,Calendar_t* da){
	int i;
	FILE* fp;
	int j=da->index;
	Meeting_t** arr = da->arr;
	fp=fopen(name,"w");
	for(i=0;i<j;i++){
		fprintf(fp,"%f %f %d \n",arr[i]->begin,arr[i]->end,arr[i]->room);
	}
	fclose(fp);
	return;
}