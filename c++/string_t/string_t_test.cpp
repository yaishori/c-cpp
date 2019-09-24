#include <string.h>
#include "string_t.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int mylen;
	int mycmp;
	bool mybool;
	string_t mystr;
	mystr.print();
	mylen=mystr.getLen();
	cout << "length of mystr" << endl;
	cout << mylen << endl;

	string_t mystr1("abc");
	mycmp= mystr1.string_tCmp(mystr);
	cout << "compare between mystr to mystr1" << endl;
	cout << mycmp << endl;
	mystr1.print();
	mylen=mystr1.getLen();
	cout << "length of mystr1" << endl;
	cout << mylen << endl;

	string_t mystr3=mystr1;
	mystr3.print();
	mystr=mystr1;
	mycmp= mystr1.string_tCmp(mystr);
	cout << "compare between mystr to mystr1" << endl;
	cout << mycmp << endl;
	mystr.print();

	mystr.upperCase();
	mystr.print();

	mystr.prePend(mystr1);
	mystr.print();

	mybool = mystr<mystr3;
	cout << mybool << endl;

	mybool = mystr3<mystr;
	cout << mybool << endl;

	cout<<mystr;


	return 0;

}