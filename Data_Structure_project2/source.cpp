#include<iostream>
#include<fstream>
#include<tuple>

#include"Airport.h";

using std::tuple;

/*chush*/
int Init(int count_runway, int size_queue_takeoff, int size_queue_land);
tuple<bool, int, int> getOrder(bool flag, int count_takeoff, int count_land);
tuple<bool,int,int> pushInf(bool flag,int num_takeoff,int num_land);

int Init(int count_runway, int size_queue_takeoff,int size_queue_land)
{
	Airport *myairport = new Airport(count_runway, size_queue_takeoff, size_queue_land);
}

tuple<bool, int, int> getOrder(bool flag, int count_takeoff, int count_land)
{
	tuple<bool, int, int> inf(flag, count_takeoff, count_land);

	return inf;
}
tuple<bool, int, int> pushInf(bool flag, int num_takeoff, int num_land)
{
	tuple<bool, int, int> inf(flag, num_takeoff, num_land);

	return inf;
}