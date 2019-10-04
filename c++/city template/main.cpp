#include "building_t.h"
#include "street_t.h"
#include "city_t.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main(){
 building_t<int> myBuilding;
 myBuilding.setBuildingID(26);
 cout<<myBuilding.getBuildingID()<<endl;

 street_t<int,string> myStreet;
 myStreet.setStreetID("kapah");
 cout<<myStreet.getStreetID()<<endl;

 myStreet.addBuilding2Street(myBuilding);
 cout<<myStreet.getBuilding(26).getBuildingID()<<endl;

 city_t<int,string,string> myCity;
 myCity.setCityID("beersheva");
 cout<<myCity.getCityID()<<endl;

 myCity.addStreet(myStreet);
 cout<<myCity.getStreet("kapah").getStreetID()<<endl;


}