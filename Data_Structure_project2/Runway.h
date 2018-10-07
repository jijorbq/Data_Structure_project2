#pragma once

//跑道类好简单，，但是好像想不到什么其他参数了
class Runway
{
public:
	Runway();
	Runway(int num, bool flag);
	~Runway();
	bool setFlag(bool flag);
private:
	bool flag;	//跑道是起飞或着陆
	int num;	//跑道编号
};

