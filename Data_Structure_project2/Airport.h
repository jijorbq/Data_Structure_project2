#pragma once

#include<tuple>
#include<vector>
#include<queue>
#include<map>

#include"Plane.h"
#include"Runway.h"

const int MAXSIZE = 1000;

class Airport
{
public:
	Airport();
	Airport(int count_runway, int size_queue_takeoff, int size_queue_land);
	~Airport();

	void Order(bool flag, int count_plane_takeoff, int count_plane_land);
	std::tuple<bool, int, int> request();	
	std::vector<Plane> show_takeoff();
	std::vector<Plane> show_land();			
private:
	int count_runway;		//跑道数
	int size_queue_takeoff;	//起飞队列数
	int size_queue_land;	//降落队列数
	std::map<int, Runway> runway;				//用来存放跑道
	std::priority_queue <Plane> queue_takeoff;	//起飞队列
	std::priority_queue <Plane> queue_land;		//降落队列

};

