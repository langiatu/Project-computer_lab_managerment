#include<iostream>
#include "Appointment.h"
using namespace std;


//构造函数
Appointment::Appointment()
{
	this->app_sta.clear();

	this->appstaInit();
}


//初始化预约记录的状态
void Appointment::appstaInit()
{
	this->app_sta.insert(make_pair(0, make_pair(0, "审核中")));
	this->app_sta.insert(make_pair(1, make_pair(1, "已通过")));
	this->app_sta.insert(make_pair(2, make_pair(2, "未通过")));
	this->app_sta.insert(make_pair(3,make_pair(3, "已取消")));
}