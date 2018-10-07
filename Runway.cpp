#include "Runway.h"


Runway::Runway(){//此处参数默认值待考虑 
	flag = true; 
	num = 0;
}
Runway::Runway(int num, bool flag){
	this->num = num;
	this->flag = flag;
}
Runway::~Runway(){
	flag = true;
	num = 0;
}
void Runway::setFlag(bool flag){
	this->flag = flag;
}
bool Runway::getFlag() const{
	return flag;
}
int Runway::getNum() const{
	return num;
}
