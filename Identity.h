#pragma once
#include<iostream>


class Identity {
public:

	//显示子菜单
	virtual ~Identity() = default;
	virtual void showmenu() = 0;
	virtual void user_Manager() = 0;

protected:
	std::string user_name;    //用户姓名
	int user_id;		 //用户编号

};