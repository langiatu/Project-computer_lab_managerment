#include<iostream>

using namespace std;

#include "Lab.h"
#include<fstream>

//构造函数
Lab::Lab()
{
	this->appoint.clear();
	this->labInf.clear();

	this->initlab();
	this->Load();
}

//初始化机房信息
void Lab::initlab() {
	int id;    //机房编号
	int size;  //机房容量

	//1号机房
	id = 1;
	size = 20;
	this->labInf.insert(make_pair(id,size));

	//2号机房
	id = 2;
	size = 50;
	this->labInf.insert(make_pair(id, size));

	//3号机房
	id = 3;
	size = 100;
	this->labInf.insert(make_pair(id, size));
}

//加载文件记录
void Lab::Load()
{
	ifstream ifs;
	ifs.open("appoint.txt",ios::in);
	if (!ifs.is_open()) {
		
		ifs.close();
	}
	else
	{
		char eof;
		ifs >> eof;
		if (ifs.eof()) {
			
			ifs.close();
		}
		else {
			ifs.putback(eof);
			
			Appointment p1;   //机房编号 周几 上午/下午 状态编号 状态

			while (ifs >> p1.id) {
				ifs >> p1.time.first >> p1.time.second >> p1.sta.first >> p1.sta.second;
				this->appoint.push_back(p1);
			}
			ifs.close();
		}
	}
}
