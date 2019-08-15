#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	int cont=1;
	int option=0;
	int hour;
	int min;
	int sec;
	int day;
	int year;
	int month;
	int format;
	cTime_t* mytime = (cTime_t*)malloc (sizeof(cTime_t));
	cTime_t* timeToAdd = (cTime_t*)malloc (sizeof(cTime_t));
	cDate_t* date = (cDate_t*)malloc (sizeof(cDate_t));

	struct tm* currentTime;
	time_t time_date;

	time_date=time(0);
	currentTime = localtime(&time_date);
	mytime->h=currentTime->tm_hour;
	mytime->m=currentTime->tm_min;
	mytime->s=currentTime->tm_sec;
	date->y=((currentTime->tm_year)+1900);
	date->m=((currentTime->tm_mon)+1);
	date->d=currentTime->tm_mday;


	while (cont) 

	{
		printf("Choose option: \n");
		printf("1: set Time  \n"); 
		printf("2: get hour  \n");
		printf("3: get minutes  \n");
		printf("4: get seconds \n");
		printf("5: add time \n");
		printf("6: print time \n");
		printf("7: set date \n");
		printf("8: get day of year using is leap\n");
		printf("9: print date \n");

		printf("Any another number - stop \n");

		scanf("%d", &option);
		switch (option) 
		{
			case 1: 
				printf("enter hour:\n");
				scanf("%d", &hour);
				printf("enter minutes:\n");
				scanf("%d", &min);		
				printf("enter seconds:\n");
				scanf("%d", &sec);		
				setTime(mytime,hour,min,sec);
 				break;
 			case 2:
 				hour=getHour(mytime);
 				printf("%d\n",hour);
 				break;
 			case 3:
 				min=getMinutes(mytime);
 				printf("%d\n",min);
 				break;
 			case 4:
 				sec=getSeconds(mytime);
 				printf("%d\n",sec);
 				break;
 			case 5: 
				printf("enter hour:\n");
				scanf("%d", &hour);
				printf("enter minutes:\n");
				scanf("%d", &min);		
				printf("enter seconds:\n");
				scanf("%d", &sec);		
				setTime(timeToAdd,hour,min,sec);
				addTime(mytime,timeToAdd);
				break;
			case 6: 
				printf("Select format:\n");
				printf("1: \n");
				printf("2: \n");
				scanf("%d",&format);
				printTime(mytime,format);
				break;

			case 7: 
				printf("enter day:\n");
				scanf("%d", &day);
				printf("enter month:\n");
				scanf("%d", &month);		
				printf("enter year:\n");
				scanf("%d", &year);
				setDate(date,day,month,year);
				break;
			case 8:
				day=getDayOfYear(date);
 				printf("%d\n",day);
 				break;
			case 9: 
				printf("Select printing format:\n");
				printf("1:  month as string\n");
				printf("2:  european\n");
				printf("3:  american\n");
				scanf("%d",&format);
				printDate(date,format);
				break;


			default: cont=0; break;
		}
	}
	free(mytime);
	free(timeToAdd);
	free(date);
return 0;
}
