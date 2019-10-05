#include "TException_t.h"
#include <iostream>
using namespace std;

int main(){
	int x=5;
	try{
		if(x>0){
			TException_t<int> tExcep(x,"bigger than zero",__FILE__,__LINE__);
			throw tExcep;
		}
	}


	catch(TException_t<int> tExcep){
		cout<<tExcep.getObject()<<endl;
		cout<<tExcep.getMessage()<<endl;
		cout<<tExcep.getFile()<<endl;
		cout<<tExcep.getLine()<<endl;
	}
	return 0;
}
