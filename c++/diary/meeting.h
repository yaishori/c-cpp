#ifndef MEETING_H
#define MEETING_H

#include <string>
using namespace std;

class meeting_t{
	public:
		virtual ~meeting_t(){;}
		meeting_t(const float& begin,const float& end,const string& subject="");
		meeting_t(const meeting_t& meeting);

		const float& getBegin() const{return m_begin;}
		const float& getEnd() const{return m_end;}
		const string& getSubject() const{return m_subject;}
		
		void setSubject(const string& subject);

	private:
		const float m_begin;
		const float m_end;
		string m_subject;
		meeting_t& operator=(const meeting_t& meeting);
		
};


#endif