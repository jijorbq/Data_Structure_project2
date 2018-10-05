#pragma once
class Plane
{
public:
	Plane();
	Plane(bool flag, int num, int fuel_level = 100000000, int fuel_consumption = 0);
	~Plane();
private:
	bool falg;//takeoff/land
	int num;
	int fuel_level;//剩余油量
	int fuel_consumption;//单位时间耗油量
};

