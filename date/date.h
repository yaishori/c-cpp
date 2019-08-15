typedef struct {
	int h;
	int m;
	int s;
}cTime_t;


typedef struct {
	int d;
	int m;
	int y;
}cDate_t;


void setTime(cTime_t* time,int h,int m,int s);
int getHour(cTime_t* time);
int getMinutes(cTime_t* time);
int getSeconds(cTime_t* time);
void addTime(cTime_t* time, cTime_t* timeToAdd);
void printTime(cTime_t* time, int format);


void setDate(cDate_t* date,int y,int m,int d);
int getDay(cDate_t* date);
int getMonth(cDate_t* date);
int getYear(cDate_t* date);
int isLeap(cDate_t* date);
int getDayOfYear(cDate_t* date);
char* getNameOfMonth(cDate_t* date);
void printDate(cDate_t* date, int format);
