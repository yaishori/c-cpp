#include "building_t.h"
#include "street_t.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main(){
 building_t<int> myBuilding;
 myBuilding.setBuildingID(5);
 cout<<myBuilding.getBuildingID()<<endl;

 street_t<int,string> myStreet;
 myStreet.setStreetID("abc");
 cout<<myStreet.getStreetID()<<endl;

 myStreet.addBuilding2Street(myBuilding);
 cout<<myStreet.getBuilding(5).getBuildingID()<<endl;

}