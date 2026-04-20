#pragma once
#include<iostream>
using namespace std;
#include<string>

#include<map>

//登录系统管理类
class Login
{
public:
	//构造函数
	Login();

	//加载文件内的用户信息
	void Load();
	 
	
	//学生登录验证
	bool Stu_vertity();
	
	//教师登录验证
	bool Tea_vertity();

	//管理员登录验证
	bool Mana_vertity();

	//析构函数
	~Login();

	//用于保存用户登录时的输入
	string M_name;
	int M_id;
	

	//用户账号文件是否为空
	bool StuIsEmpty;
	bool TeaIsEmpty;
	
	

	//保存教师、学生的编号与账号的映射
	map<int,pair<string ,int>> stu;
	map<int, pair<string, int>> tcher;

	map<string, int> managers;
	
};