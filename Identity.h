#pragma once
#include<iostream>
using namespace std;

class Identity {
public:

	//显示子菜单
	virtual void showmenu();
	virtual void user_Manager();

	string user_name;    //用户姓名
	int user_id;		 //用户账号


};