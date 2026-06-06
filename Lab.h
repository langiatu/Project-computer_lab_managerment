#pragma once
#include<iostream>
#include<map>
#include<vector>
#include "Appointment.h"


//Lab类  管理预约记录文件
class Lab
{
public:
	//构造函数
	Lab();
	//初始化机房信息
	void initlab();


	//保存记录到文件
	void appointSave();

	//加载文件
	void Load();

	//清空文件
	void fileclear();
	
	//析构函数
	~Lab();
	
	//机房信息 编号 最大容量
	std::map<int, int> labInf;

	//预约记录文件是否为空
	bool appointIsEmpty;

	//所有预约记录
	std::vector<Appointment> appoint;
};


