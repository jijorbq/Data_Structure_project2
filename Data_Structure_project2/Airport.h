#include<tuple>
#include<vector>
#include<queue>
#include<map>

#include"Plane.h"
#include"Runway.h"
using std::vector;

const int MAXSIZE = 1000;

class Airport
{
public:
	//pre 
	Airport();
	Airport(int size_queue_takeoff, int size_queue_land);
	~Airport() = default;
	bool buildRunway(bool flag);
	bool setSize_queue_takeoff(int size);
	bool setSize_queue_land(int size);
	
	//cur
	bool message(bool flag, int num, int fuel = 10000000, int v = 0); // ���/���䣬�ɻ����, 
	void Take_Land();
	std::tuple<bool, vector<Plane>, vector<Plane> > request() const;
	std::vector<Plane> show_takeoff();
	std::vector<Plane> show_land();
	void Order(); //order������Ϊ�ǻ����ڲ��ĺ���
	//post
	
private:
	bool error_flag = false;//�����־
	int count_runway;		//�ܵ���
 
	int size_queue_takeoff;	//��ɷɻ�����
	int size_queue_land;	//����ɻ�����
	std::map<int, Runway> runway;				//��������ܵ�
	std::priority_queue <Plane> queue_takeoff;	//����ܶ���
	std::priority_queue <Plane> queue_land;		//�����ܶ���
	
	vector <Plane> Taking;  //��ǰ����ɷɻ����� 
	vector <Plane> Landing; //��ǰ�ɽ���ɻ�����	

};

