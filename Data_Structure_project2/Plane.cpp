#include "Plane.h"


Plane::Plane(){
	flag = true;
	fuel_level = 100000000;
	fuel_consumption = 0;
	wait_time = 0;
}
Plane::Plane(bool flag, int num, int fuel_level, int fuel_consumption){
	this->flag = flag;
	this->num = num;
	wait_time = 0;
	this->fuel_level = fuel_level;
	this->fuel_consumption = fuel_consumption;
}
bool Plane::update(){
	if( flag==true ) return true;
	else{
		fuel_level-=fuel_consumption;
		if( fuel_consumption<0 ) return false;
		++wait_time;
		return true;
	}
}
void Plane::setFlag(bool flag){
	this->flag = flag;
} 
bool Plane::getFlag() const{
	return flag;
}
int Plane::getNum() const{
	return num;
}
int Plane::getFuel() const{
	return fuel_level;
}
int Plane::getTime() const{
	return wait_time;
}
Plane::~Plane(){
	flag = true;
	fuel_level = 100000000;
	fuel_consumption = 0;
	wait_time = 0;
}
