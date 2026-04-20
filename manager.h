#pragma once
#include "Login.h"
#include<iostream>
#include "Identity.h"
#include "Lab.h"

using namespace std;

class Manager :public Identity
{
public:
	//构造函数
	Manager();
	
	//管理方法
	void user_Manager();

	//查看用户信息
	void showUserInf();

	//显示管理员功能菜单
	void showmenu();

	//清空预约
	void clearAppoint();

	//添加用户账号
	void addUser();

	//检测用户id是否存在
	bool IdExist(int id);

	//保存新用户账号
	void userSave(int type,int key);

	//查看机房信息
	void showlabInf();

	//清空所有预约记录
	void clearApp();

	//析构函数
	~Manager();

	Lab Ma_lab;
	Login Ma_log;
};

