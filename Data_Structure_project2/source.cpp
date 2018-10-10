#include<iostream>
#include<fstream>
#include<tuple>

#include"Airport.h";

//Áô¸ø´óÀÐµÄ
using std::tuple;

int main()
{
	//testing_begin
	Airport myairport;
	myairport.setSize_queue_land(10);
	myairport.setSize_queue_takeoff(20);
	myairport.buildRunway(true);
	/*while (true)
	{*/
	myairport.message(false, 1001, 0, 10);
//	}
	myairport.Take_Land();
	myairport.Order();
	tuple<bool, vector<Plane>, vector<Plane>> temp = myairport.request();

	return 0;
	//testing_end
 } 
