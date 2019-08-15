#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setTime(cTime_t* time,int h,int m,int s){
	if(time==NULL){
		printf("null pointer-time\n");
	}
	else if(h>24||h<0||m>59||m<0||s>59||s<0){
		printf("not possible time\n");
	}
	else{
		time->h=h;
		time->m=m;
		time->s=s;
	}
}

int getHour(cTime_t* time){
	int h;
	if(time==NULL){
		printf("null pointer-time\n");
		h=-1;
	}
	else{
		h=time->h;
	}

	return h;
}
int getMinutes(cTime_t* time){
	int m;
	if(time==NULL){
		printf("null pointer-time\n");
		m=-1;
	}
	else{
		m=time->m;
	}

	return m;
}

int getSeconds(cTime_t* time){
	int s;
	if(time==NULL){
		printf("null pointer-time\n");
		s=-1;
	}
	else{
		s=time->s;
	}

	return s;
}
void addTime(cTime_t* time, cTime_t* timeToAdd){
	int saveH;
	int saveS;
	int saveM;
	if (time==NULL||timeToAdd==NULL){
		printf("null pointer-time\n");
		return;
	}
	saveH =time->h;
	saveM =time->m;
	saveS =time->s;

	time->s =((time->s + timeToAdd->s)%60);
	if (time->s < saveS){
		(time->m)++;
		(time->m)= (time->m)%60;
	}

	time->m =((time->m + timeToAdd->m)%60);
	if (time->m <= saveM){
		(time->h)++;
		(time->h)= (time->h)%24;
	}

	time->h =((time->h + timeToAdd->h)%24);
	
}


void printTime(cTime_t* time, int format){
	char period[2]; 
	if(time==NULL){
		printf("null pointer-time\n");
		return;
	}
	if(format>2||format<0){
		printf("format can be 1 or 2\n");
		return;
	}

	if(format==1){
		printf("%d:%02d:%02d\n", time->h,time->m,time->s);
	}

	else{
		if(time->h>12){
			period[0]='P';
			period[1]='M';
		}
		else{
			period[0]='A';
			period[1]='M';
		}

		printf("%d:%02d:%02d %s\n", time->h%12,time->m,time->s, period);
	}

	return;
}

void setDate(cDate_t* date,int y,int m,int d){
	if(date==NULL){
		printf("null pointer-date\n");
	}
	else if((m<0)||(m>12) ||(d<0) || (d>31) || 
			((y%4==0)&&(m==2)&&(d>29)) || ((y%4!=0)&&(m==2)&&(d>28))||
			(d>30 && m==4)|| (d>30 && m==6)|| (d>30 && m==9)|| (d>30 && m==11)){

				printf("not possible date\n");
	}	
	else{
		date->y=y;
		date->m=m;
		date->d=d;
	}
}
int getDay(cDate_t* date){
	int d;
	if(date==NULL){
		printf("null pointer-date\n");
		d=-1;
	}
	else{
		d=date->d;
	}

	return d;
}

int getMonth(cDate_t* date){
	int m;
	if(date==NULL){
		printf("null pointer-date\n");
		m=-1;
	}
	else{
		m=date->m;
	}

	return m;
}
int getYear(cDate_t* date){
	int y;
	if(date==NULL){
		printf("null pointer-date\n");
		y=-1;
	}
	else{
		y=date->y;
	}

	return y;
}

int isLeap(cDate_t* date){
	if(date==NULL){
		printf("null pointer-date\n");
		return 0;
	}
	return ((date->y)%4==0) ? 1:0;
}

int getDayOfYear(cDate_t* date){
	int notLeap[]={0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	int leap[]= {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

	if(date==NULL){
		printf("null pointer-date\n");
		return -1;
	}
	if(isLeap(date)){
		return (leap[date->m] + (date->d));
	}
	else{
		return (notLeap[date->m] + (date->d));
	}
}

char* getNameOfMonth(cDate_t* date){
	char* name;
	char* monthNames[13] = {"","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Nov", "Dec"};
	if(date==NULL){
		printf("null pointer-date\n");
		return "";
	}
	
	name= monthNames[date->m];
	return name; 
}


void printDate(cDate_t* date, int format){
	char* name;
	if(date==NULL){
		printf("null pointer-date\n");
		return;
	}
	if(format==1){
		name=getNameOfMonth(date);
		printf("%d/%s/%d\n", date->d,name,date->y);
	}
	else if(format==2){
		printf("%02d/%02d/%d     European\n",date->d,date->m,date->y);
	}
	else if(format==3){
		printf("%02d/%02d/%d     American\n",date->m,date->d,date->y);
	}
	else{
		printf("not possible format\n");
	}


}