#ifndef VIRTH_H
#define VIRTH_H

#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

typedef enum Status{ok_e,cant_open_file_e ,bad_accsess_e,writeErr_e,readErr_e} Status;

class virthIO_t{
	public:
		virthIO_t():m_name(""),m_mode(""){
			m_fd=NULL;
			m_stat=cant_open_file_e;
		}
		virthIO_t(const char * name,const char * mode):m_mode(mode),m_name(name){
			m_fd=fopen(m_name,m_mode);
			if (m_fd != NULL){
				m_stat = ok_e;
			}
			else{
				m_stat = cant_open_file_e;
			}
		}

		const char* getMode() const{return m_mode;}
		const char* getName() const{return m_name;}
		FILE* getFd() const{return m_fd;}
		long int getPositin() const{
			return ftell(m_fd);
		}

		long int getLength() const{
			long int size;
			fseek(m_fd, 0, SEEK_END);
			size = ftell(m_fd);
			fseek(m_fd, 0, SEEK_SET);

			return size;
		}

		Status getStatus() const{return m_stat;}

		void setStatus(const Status& stat){
			m_stat=stat;
		}

		int setPosition(long int offset, int whence){
			return fseek(m_fd,offset,whence);
		}



		FILE * open(){
			m_fd=fopen(m_name,m_mode);
			if (m_fd != NULL){
				m_stat = ok_e;
			}
			else{
				m_stat = cant_open_file_e;
			}
		}

		int close(){
			return fclose(m_fd);
		}
		
		virtual virthIO_t& operator>>(int& num)=0;
		virtual virthIO_t& operator<<(int num)=0; //in ascci-fprintf, in binary-fwrite
		virtual virthIO_t& operator>>(unsigned int& num)=0;
		virtual virthIO_t& operator<<(unsigned int num)=0;
		virtual virthIO_t& operator>>(char& num)=0;
		virtual virthIO_t& operator<<(char num)=0;
		virtual virthIO_t& operator>>(unsigned char& num)=0;
		virtual virthIO_t& operator<<(unsigned char num)=0;
		virtual virthIO_t& operator>>(short& num)=0;
		virtual virthIO_t& operator<<(short num)=0;
		virtual virthIO_t& operator>>(unsigned short& num)=0;
		virtual virthIO_t& operator<<(unsigned short num)=0;
		virtual virthIO_t& operator>>(long& num)=0;
		virtual virthIO_t& operator<<(long num)=0;
		virtual virthIO_t& operator>>(unsigned long& num)=0;
		virtual virthIO_t& operator<<(unsigned long num)=0;
		virtual virthIO_t& operator>>(float& num)=0;
		virtual virthIO_t& operator<<(float num)=0;
		virtual virthIO_t& operator>>(double& num)=0;
		virtual virthIO_t& operator<<(double num)=0;


	protected:
		virtual ~virthIO_t(){fclose(m_fd);};
		const char * m_mode;
		const char * m_name;
		Status m_stat;
		FILE* m_fd;
	
	private:
		virthIO_t(const virthIO_t &virth);
		virthIO_t& operator=(const virthIO_t& virth);
		
};


#endif