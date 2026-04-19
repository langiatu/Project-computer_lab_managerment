#pragma once
#include<iostream>
using namespace std;

typedef int App_id;    //C++11    using App_id = int;
typedef pair<string, string> App_time;
typedef pair<int, string>   App_stu;

//预约记录
class Appointment
{
public:
	//构造函数
	Appointment();


	//机房编号
	App_id id;
	//预约时间  第一元素为周一至周五  第二元素为上午或下午
	App_time time;
	//预约记录状态 第一元素为状态编号，第二元素为状态
	App_stu sta;
};
