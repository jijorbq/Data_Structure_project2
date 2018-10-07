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
	Airport(int size_queue_takeoff, int size_queue_land);
	~Airport() = default;

	bool buildRunway(bool flag);
	bool setSize_queue_takeoff(int size);
	bool setSize_queue_land(int size);

	void Order();
	std::tuple<bool, int, int> request() const;
	std::vector<Plane> show_takeoff();
	std::vector<Plane> show_land();
private:
	bool error_flag = false;//错误标志
	int count_runway;		//跑道数
	int size_queue_takeoff;	//起飞队列数
	int size_queue_land;	//降落队列数
	int num_takeoff;		//正在起飞的飞机编号
	int num_land;			//正在降落的飞机编号
	std::map<int, Runway> runway;				//用来存放跑道
	std::priority_queue <Plane> queue_takeoff;	//起飞队列
	std::priority_queue <Plane> queue_land;		//降落队列

};

