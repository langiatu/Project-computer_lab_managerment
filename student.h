#pragma once
#include<iostream>
#include "Identity.h"
#include "Login.h"
#include "Lab.h"


class Student :public Identity {
public:
	//构造函数
	Student();

	//管理方法
	void user_Manager();

	//显示管理员功能菜单
	void showmenu();

	//申请预约
	void addAppoint();

	//查看所有预约
	void showAppoint();

	//查看本用户的申请
	void showMyApp();

	//取消预约
	void cancelAppoint();


	//析构函数
	~Student();

	Login Stu_log;
	Lab Stu_lab;
};
