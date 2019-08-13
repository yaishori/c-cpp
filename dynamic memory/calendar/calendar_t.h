#include <stdio.h>

typedef struct {
	Meeting_t **arr;
	int index;
	int capacity;
}Calendar_t;

Calendar_t* createDA(int capacity);
void loadFromFile(char* name,Calendar_t* da);
void saveToFile(char* name,Calendar_t* da);
int insertMeeting(Calendar_t* da,Meeting_t* meeting);
void printDA(Calendar_t* da);
Calendar_t* removeMeeting(Calendar_t* da,float begin);
Meeting_t* findMeeting(Calendar_t* da,float begin);
void destoryDA(Calendar_t* da);