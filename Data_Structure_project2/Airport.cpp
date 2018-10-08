#include "Airport.h"

using std::vector;
using std::tuple;
using std::map;

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

bool Airport::message(bool flag, int num, int fuel = 10000000, int v = 0)//the simple condition
{
	Plane P(flag, num, fuel, v);
	if (flag == true)
	{
		if (queue_takeoff.size() < size_queue_takeoff){
		queue_takeoff.push(P);
		return true;
	    }
		else return false;
	}
	else {
		if (queue_land.size() < size_queue_land){
		queue_land.push(P); 
		return true;
	    }
	    else return false;
	}
}



void Airport::Take_Land()
{
	map<int, Runway>:: iterator iter;
	iter = runway.begin();
	while(iter != runway.end()){
		if ((iter->second).getFlag()){
			Plane P = queue_takeoff.top();
			P.setrunway(iter->first); 
    		Taking.push_back(P);	
	    	queue_takeoff.pop();
		}
		else {
			Plane P = queue_land.top();
			P.setrunway(iter->first);			
			Landing.push_back(P);
			queue_land.pop(); 
		}
	}
}
void Airport::Order()
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
	
	temp.clear();
	
	while (!queue_land.empty())
	{
		Plane temp_Plane = queue_land.top();
		temp.push_back(temp_Plane);
		queue_land.pop();
	}
	for (auto item : temp)
	{
		if (!(item).update())
		{
			error_flag = true;
			break;
		}
		queue_land.push(item);
	}
}


tuple<bool, vector<Plane>, vector<Plane> > Airport::request() const
{
	if (error_flag)
	{
		tuple<bool, vector<Plane>, vector<Plane> > temp(false, Taking, Landing);
		return temp;
	}
	else
	{
		tuple<bool, vector<Plane>, vector<Plane> > temp(true, Taking, Landing);
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
