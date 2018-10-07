#pragma once

//跑道类好简单，，但是好像想不到什么其他参数了
class Runway
{
public:
	Runway();
	Runway(int num, bool flag);
	~Runway();
	void setFlag(bool flag);
	bool getFlag() const;
	int getNum() const;
private:
	bool flag;	//跑道是起飞或着陆 true起飞 flase着陆 
	int num;	//跑道编号
};

