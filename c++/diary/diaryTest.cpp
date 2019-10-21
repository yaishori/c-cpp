#include "meeting.h"
#include "diary.h"
#include "TException_t.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

meeting_t* createMeeting(){
	float begin;
	float end;
	string str;
	cout << "enter begin time"<<endl;
	cin >> begin;
	cout << "enter end time"<<endl;
	cin >> end;
	cout << "enter subject"<<endl;
	cin >> str;
	try{
		meeting_t* meeting=new meeting_t(begin,end,str);
		return meeting;
	}
	catch(TException_t<float> tExcep){
		cout<<tExcep.getObject()<<endl;
		cout<<tExcep.getMessage()<<endl;
		cout<<tExcep.getFile()<<endl;
		cout<<tExcep.getLine()<<endl;
		return NULL;				
	}
}

int main()
{
	int input;
	float begin;
	float end;
	string str;
	diary_t diary;
	do 
	{
		cout <<"choose option:\n1. insert meeting\n2. find meeting\n3. remove meeting\n4. clean diary\n5. print diary\n6. exit\n";
		cin >> input;

		switch (input)
		{
		case 1:{
			meeting_t* myMeeting=createMeeting();
			if(myMeeting==NULL){
				break;
			}
			else{
				diary.insertMeeting(myMeeting);
			}
		}
			break;
		case 2:
			cout << "enter begin time"<<endl;
			cin >> begin;
			cout<<diary.findMeeting(begin)->getBegin()<<endl;
			break;
		case 3:
			cout << "enter begin time"<<endl;
			cin >> begin;
			cout<<diary.removeMeeting(begin)->getBegin()<<endl;
			break;
		case 4:
			diary.cleanAD();
			break;
		case 5:
			diary.printDiary();
			break;
		
		
		default:
			break;
		}

	} while (input < 6);
	
	return 0;
}


