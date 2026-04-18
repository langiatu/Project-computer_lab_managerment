#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Student :public Identity {
public:
	//构造函数
	Student();

	//管理方法
	void user_Manager();

	//显示管理员功能菜单
	void showmenu();


	//析构函数
	~Student();
};
