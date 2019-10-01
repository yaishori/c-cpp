#include "memPage_t.h"

int main(){
	memPage_t myPage;
	int k=8;
	char* buff= new char[50];
	cout<<myPage.readData(buff,3)<<endl;
	cout<<myPage.writeData(&k,sizeof(int),3)<<endl;
	cout<<myPage.writeData(&k,sizeof(int))<<endl;
	myPage.print();
	cout<<myPage.getPosition()<<endl;
	cout<<myPage.getActualSize()<<endl;
	cout<<myPage.getString()<<endl;
	cout<<myPage.readData(buff,sizeof(int),0)<<endl;
	cout<<buff<<endl;
	cout<<myPage.writeData(&k,sizeof(int),3)<<endl;
	myPage.print();

	return 0;
}