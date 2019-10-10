#include "tContainer_t.h"
#include <list>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	tContainer_t<int, vector<int*> >  cont;
	int* x = new int;
	int* y = new int;
	*x = 1;
	*y = 2;
	cont.insertElement(x);
	cont.insertElement(y);
	cout<<*cont.getFirst()<<endl;
	cout<<*cont.getLast()<<endl;
	cout<<cont.numOfElements()<<endl;
	cout<<*cont.findByVal(2)<<endl;
	cout<<*cont[0]<<endl;
	cout<<*cont[1]<<endl;
	cont.deleteByVal(1);
	cout<<cont.isEmpty()<<endl;
	cont.deleteByVal(2);
	cout<<cont.isEmpty()<<endl;

}