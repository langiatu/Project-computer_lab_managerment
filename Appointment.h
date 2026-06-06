#pragma once
#include<iostream>
#include<map>

typedef int App_Rid;    //C++11    using App_id = int;
typedef std::pair<std::string, std::string> App_time;
typedef std::pair<int, std::string>   App_sta;

//预约记录
class Appointment
{
public:
	//构造函数
	Appointment();

	//初始化预约记录的状态
	void appstaInit();

	//机房编号
	App_Rid rid;
	//预约时间  第一元素为周一至周五  第二元素为上午或下午
	App_time time;
	//预约记录状态 第一元素为状态编号，第二元素为状态
	App_sta sta;
	//预约用户编号
	int uid;

	//存储预约记录状态的映射关系
	std::map<int,App_sta> app_sta;
};
