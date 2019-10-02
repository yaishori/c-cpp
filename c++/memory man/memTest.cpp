#include "memPage_t.h"
#include "memPool_t.h"

int main(){
	memPage_t myPage;
	char k[]="abc";
	char* buff= new char[50];
	cout<<myPage.readData(buff,3)<<endl;
	cout<<myPage.writeData(k,sizeof(int),3)<<endl;
	cout<<myPage.writeData(k,3)<<endl;
	cout<<myPage.getString()<<endl;
	cout<<myPage.getPosition()<<endl;
	cout<<myPage.getActualSize()<<endl;
	cout<<myPage.getString()<<endl;
	cout<<myPage.readData(buff,3,0)<<endl;
	cout<<buff<<endl;
	cout<<myPage.writeData(k,3,2)<<endl;
	cout<<myPage.getString()<<endl;
	cout<<myPage.readData(buff,3,1)<<endl;
	cout<<buff<<endl;
	cout<<myPage.getPosition()<<endl;
	cout<<myPage.getActualSize()<<endl;
	cout<<""<<endl;
	memPool_t myPool;
	char d[]="abc";
	char x[]="ffff";

	cout<<myPool.writeData(d,3)<<endl;
	cout<<myPool.getPosition()<<endl;
	cout<<myPool.getActualSize()<<endl;
	cout<<""<<endl;
	cout<<myPool.writeData(x,4)<<endl;
	cout<<myPool.getPosition()<<endl;
	cout<<myPool.getActualSize()<<endl;
	cout<<""<<endl;
	cout<<myPool.writeData(d,3)<<endl;
	cout<<myPool.getPosition()<<endl;
	cout<<myPool.getActualSize()<<endl;
	cout<<""<<endl;
	cout<<myPool.writeData(d,3)<<endl;
	cout<<myPool.getPosition()<<endl;
	cout<<myPool.getActualSize()<<endl;
	cout<<""<<endl;
	cout<<"v.size="<<myPool.getVector().size()<<endl;

	myPool.print();


	return 0;
}