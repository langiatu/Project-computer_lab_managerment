#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Manager :public Identity {
public:
	//管理方法
	void user_Manager();

	//显示管理员功能菜单
	void showmenu();
};

