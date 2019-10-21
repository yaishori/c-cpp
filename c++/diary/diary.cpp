#include "diary.h"
#include <algorithm>
#include <iostream>
using namespace std;

diary_t::diary_t(const diary_t& diary){
	citer cit;
	for(cit=diary.m_meetings.begin();cit!=diary.m_meetings.end();cit++){
		meeting_t* meeting= new meeting_t(*(cit->second));
		insertMeeting(meeting);
	}
}

diary_t& diary_t::operator=(const diary_t& diary){
	if(this!=&diary){
		cleanAD();
		citer cit;
		for(cit=diary.m_meetings.begin();cit!=diary.m_meetings.end();cit++){
			meeting_t* meeting= new meeting_t(*(cit->second));
			insertMeeting(meeting);
		}
	}
	return *this;
}

bool diary_t::insertMeeting(meeting_t* meeting){
	citer cit;
	if(meeting==NULL){
		return 0;
	}
	
	if(m_meetings.empty()){
		m_meetings[meeting->getBegin()]=meeting;
		return 1;
	}

	else if(m_meetings.begin()->second->getBegin()>=meeting->getEnd()){
		m_meetings[meeting->getBegin()]=meeting;
		return 1;
	}

	else if(m_meetings.rbegin()->second->getEnd()<=meeting->getBegin()){
		m_meetings[meeting->getBegin()]=meeting;
		return 1;
	}

	else{
		for(cit=m_meetings.begin(); cit!=m_meetings.end(); cit++){
			if(meeting->getBegin()>=cit->second->getEnd()){
				cit++;
				if(meeting->getEnd()<=cit->second->getBegin()){
					m_meetings[meeting->getBegin()]=meeting;
					return 1;
				}
				else{
					return 0;
				}
			}					
		}
	}
	return 0;
}


const meeting_t* diary_t::findMeeting(float begin) const{
	citer cit=m_meetings.find(begin);
	if(cit==m_meetings.end()){
		return NULL;
	}
	return cit->second;		
}

meeting_t* diary_t::removeMeeting(float begin){
	citer cit=m_meetings.find(begin);
	if(cit==m_meetings.end()){
		return NULL;
	}
	meeting_t* ret=cit->second;
	m_meetings.erase(begin);
	return ret;
}

void diary_t::cleanAD(){
	iter it;
	for(it=m_meetings.begin();it!=m_meetings.end();it++){
		delete it->second;
		m_meetings.erase(it);
	}
}

void diary_t::printDiary(){
	citer cit;
	for(cit=m_meetings.begin();cit!=m_meetings.end();cit++){
			cout<<cit->second->getBegin()<<" ";
			cout<<cit->second->getEnd()<<" ";
			cout<<cit->second->getSubject()<<" ";
			cout<<endl;
	}
}