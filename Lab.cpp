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

	//加载记录前清空记录容器内的数据  防止重复添加
	this->appoint.clear();


	ifstream ifs;
	ifs.open("appointment.txt",ios::in);
	if (!ifs.is_open()) {
		this->appointIsEmpty = true;
		ifs.close();
	}
	else
	{
		char eof;
		ifs >> eof;
		if (ifs.eof()) {
			this->appointIsEmpty = true;
			ifs.close();
		}
		else {
			ifs.putback(eof);
			this->appointIsEmpty = false;
			Appointment p1;   //机房编号 周几 上午/下午 状态编号 状态

			while (ifs >> p1.uid) {
				ifs >> p1.rid >> p1.time.first >> p1.time.second >> p1.sta.first >> p1.sta.second;
				this->appoint.push_back(p1);
			}
			ifs.close();
		}
	}
}

//保存记录到文件
void Lab::appointSave()
{
	ofstream ofs;
	ofs.open("appointment.txt",ios::out);

	if (!ofs.is_open()) {
		cout << "保存预约记录至文件中出错,即将退出....." << endl;
		system("pause");
		ofs.close();
		exit(1);
	}
	else {
		//先清空原先文件的内容 防止重复添加

		for (vector<Appointment>::iterator it = this->appoint.begin(); it != this->appoint.end(); it++) {
			ofs << it->uid << "  " << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.first << "  " << it->sta.second;
			ofs << endl;
		}
	}
}

//清空文件
void Lab::fileclear()
{
	ofstream ofs;
	ofs.open("appointment.txt",ios::trunc);
	ofs.close();
}

Lab::~Lab()
{
	this->appoint.clear();
	this->labInf.clear();
}