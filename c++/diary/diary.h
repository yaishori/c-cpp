#ifndef DIARY_H
#define DIARY_H

#include "meeting.h"
#include <map>

class diary_t{
	public:
		virtual ~diary_t(){cleanAD();}
		diary_t(){}
		diary_t(const diary_t& diary);

		diary_t& operator=(const diary_t& diary);

		bool insertMeeting(meeting_t* meeting);
		meeting_t* removeMeeting(float begin);
		const meeting_t* findMeeting(float begin) const;

		void cleanAD();
		void printDiary();

	private:
		map<float,meeting_t*> m_meetings;
		typedef typename map<float,meeting_t*>::iterator iter;
		typedef typename map<float,meeting_t*>::const_iterator citer;
};


#endif