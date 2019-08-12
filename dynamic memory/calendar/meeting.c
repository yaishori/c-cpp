#include "meeting.h"
#include <stdio.h>
#include <stdlib.h>

Meeting_t* createMeeting(float begin,float end,int room){
	Meeting_t* meeting;
	if(begin>=end){
		return NULL;
	}
	meeting =malloc(sizeof(Meeting_t));
	meeting->begin=begin;
	meeting->end=end;
	meeting->room=room;
	return meeting;
}
