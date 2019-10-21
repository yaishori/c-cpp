#include "meeting.h"
#include "TException_t.h"

using namespace std;

meeting_t::meeting_t(const float& begin,const float& end,const string& subject): m_begin(begin),m_end(end){
	if(begin<0 || begin>=24){
		throw TException_t<float>(begin,"wrong begin",__FILE__,__LINE__);
	}	
	if(end<=begin || end>24){
		throw TException_t<float>(end,"wrong end",__FILE__,__LINE__);
	}
	m_subject=subject;
}

meeting_t::meeting_t(const meeting_t& meeting):m_begin(meeting.m_begin),m_end(meeting.m_end){
	m_subject=meeting.m_subject;
}

void meeting_t::setSubject(const string& subject){
	m_subject=subject;
}