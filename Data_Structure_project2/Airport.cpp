#include "Airport.h"

using std::vector;
using std::tuple;

Airport::Airport()
{
	count_runway = 0;
	size_queue_land = 0;
	size_queue_takeoff = 0;
}

Airport::Airport(int size_queue_takeoff, int size_queue_land)
{
	this->size_queue_land = size_queue_land;
	this->size_queue_takeoff = size_queue_takeoff;
}

bool Airport::buildRunway(bool flag)
{
	Runway temp(count_runway, flag);
	runway[count_runway] = temp;
	count_runway++;

	return true;
}

bool Airport::setSize_queue_land(int size)
{
	size_queue_land = size;
	return true;
}

bool Airport::setSize_queue_takeoff(int size)
{
	size_queue_takeoff = size;
	return true;
}

void Airport::Order()
{

}

tuple<bool, int, int> Airport::request() const
{
	if (error_flag)
	{
		tuple<bool, int, int> temp(false, num_takeoff, num_land);
		return temp;
	}
	else
	{
		tuple<bool, int, int> temp(true, num_takeoff, num_land);
	}
}

vector<Plane> Airport::show_takeoff()
{
	vector<Plane> temp;
	while (!queue_takeoff.empty())
	{
		Plane temp_Plane = queue_takeoff.top();
		temp.push_back(temp_Plane);
		queue_takeoff.pop();
	}
	for (auto item : temp)
	{
		queue_takeoff.push(item);
	}
	return temp;
}

vector<Plane> Airport::show_land()
{
	vector<Plane> temp;
	while (!queue_land.empty())
	{
		Plane temp_Plane = queue_land.top();
		temp.push_back(temp_Plane);
		queue_land.pop();
	}
	for (auto item : temp)
	{
		queue_land.push(item);
	}
	return temp;
}