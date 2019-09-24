#include <string.h>
#include "string_t.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	string_t mystr;
	string_t mystr2;
	int input;
	int index;
	char x;
	
	do 
	{
		cout <<"choose option:\n1. to upper case\n2. prepend\n3. operator +=\n4. operator <\n5. contains\n6. operator []\n7. cout <<\n8. getcase \n9. setcase\n10. firstOccur\n 11. lastOccur\n 12. num of strings\n13. exit\n";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "Enter first string\n";
			cin >> mystr;
			mystr.upperCase();
			mystr.print();
			break;
		case 2:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter second string\n";
			cin >> mystr2;
			mystr.prePend(mystr2);
			mystr.print();
			break;
		case 3:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter second string\n";
			cin >> mystr2;
			mystr+=mystr2;
			mystr.print();
			break;
		case 4:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter second string\n";
			cin >> mystr2;
			cout << (mystr < mystr2) << "\n";
			break;
		case 5:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter second string\n";
			cin >> mystr2;
			cout << mystr.contains(mystr2) << "\n";
			break;
		case 6:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter index\n";
			cin >> index;
			cout << "s[index] = " << mystr[index] << "\n";
			break;
		case 7:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << mystr;
			break;

		case 8:
			cout << "caseSense = " << mystr.getCase() << "\n";
			break;
		case 9:
			cout << "Enter index\n";
			cin >> index;
			mystr.setCase(index);
			break;
		case 10:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter char\n";
			cin >> x;
			cout << "index = " << mystr.firstOccur(x) << "\n";
			break;
		case 11:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter char\n";
			cin >> x;
			cout << "index = " << mystr.lastOccur(x) << "\n";
			break;
		case 12:
			cout << "Enter first string\n";
			cin >> mystr;
			cout << "Enter second string\n";
			cin >> mystr2;
			cout << "num of strings = " << mystr.getNumOfString() << "\n";
			break;
		default:
			break;
		}

	} while (input < 12);
	
	return 0;
}

/*int main(){
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

}*/

