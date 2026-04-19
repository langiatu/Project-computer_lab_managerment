#pragma once
#include<iostream>

using namespace std;
#include<map>
#include<vector>
#include "Appointment.h"

class Lab
{
public:
	//构造函数
	Lab();
	//初始化机房信息
	void initlab();

	//添加记录

	//保存记录到文件
	

	//加载文件
	void Load();

	
	//机房信息 编号 最大容量
	map<int, int> labInf;

	//所有预约记录
	vector<Appointment> appoint;
};


