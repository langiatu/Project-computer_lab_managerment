#pragma once
#include<iostream>
#include "Identity.h"


#include "Lab.h"

#include "Login.h"
class Teacher :public Identity {
public:
	//构造函数
	Teacher();

	//管理方法
	void user_Manager();


	//显示管理员功能菜单
	void showmenu();

	//查看所有预约记录
	void showAppoint();

	//审核预约
	void checkappoint();

	//析构函数
	~Teacher();

	Login Teach_log;
	Lab Tea_lab;
};