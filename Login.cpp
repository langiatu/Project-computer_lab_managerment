#include<iostream>
#include "Login.h"
#include<fstream>

#include<algorithm>


//构造函数
Login::Login()
{
	this->managers.clear();
	this->stu.clear();
	this->tcher.clear();

	this->Load();
}

//加载文件信息     待改进
void Login::Load()
{
	//加载学生用户信息
	std::ifstream ifs1;
	ifs1.open("student.txt", std::ios::in);
	if (!ifs1.is_open()) {
		this->StuIsEmpty = true;
		ifs1.close();
	}
	else
	{
		char eof;
		ifs1 >> eof;
		if (ifs1.eof()) {
			this->StuIsEmpty = true;
			ifs1.close();
		}
		else {
			this->StuIsEmpty = false;

			ifs1.putback(eof);
			std::string name;
			int pwd;
			int id;

			while (ifs1 >> id) {

				ifs1 >> name >> pwd;

				std::pair<std::string, int>  na_pwd = std::make_pair(name, pwd);

				this->stu.insert(std::make_pair(id, na_pwd));
			}
			ifs1.close();
		}
	}
	//加载教师用户信息
	std::ifstream ifs2;
	ifs2.open("teacher.txt", std::ios::in);
	if (!ifs2.is_open()) {
		this->TeaIsEmpty = true;
		ifs2.close();
	}
	else
	{
		char eof;
		ifs2 >> eof;
		if (ifs2.eof()) {
			this->TeaIsEmpty = true;
			ifs2.close();
		}
		else {
			this->TeaIsEmpty = false;

			ifs2.putback(eof);
			std::string name;
			int pwd;
			int id;
			
			while (ifs2 >> id) {

				ifs2 >> name >> pwd;

				std::pair<std::string, int>  na_pwd = std::make_pair(name, pwd);
				

				this->tcher.insert(std::make_pair(id,na_pwd));
			}
			ifs2.close();
		}
	}

	//加载管理员用户信息
	std::ifstream ifs3;
	ifs3.open("manager.txt",std::ios::in);
	if (!ifs3.is_open()) {

		ifs3.close();
	}
	else
	{
		char eof;
		ifs3 >> eof;
		if (ifs3.eof()) {
			
			ifs3.close();
		}
		else {
			ifs3.putback(eof);
			std::string name;
			int pwd;
			
			while (ifs3 >> name) {
				ifs3 >> pwd;
				this->managers.insert(make_pair(name, pwd));
			}
			ifs3.close();
		}
	}
}

//学生登录验证
bool Login::Stu_vertity()
{
	std::string name;
	int pwd;

	std::cout << "输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "输入密码" << std::endl;
	std::cin >> pwd;

	for (auto mit = this->stu.begin(); mit != this->stu.end(); mit++) {
		if (mit->second.first == name && mit->second.second == pwd) {
			this->M_name= mit->second.first;
			this->M_id = mit->first;
			return 1;
		}
	}
	return 0;
}

//教师登录验证
bool Login::Tea_vertity()
{
	std::string name;
	int pawd;

	std::cout << "输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "输入密码" << std::endl;
	std::cin >> pawd;

	for (auto mit = this->tcher.begin(); mit != this->tcher.end(); mit++) {
		if (mit->second.first == name && mit->second.second == pawd) {
			this->M_name = mit->second.first;
			return 1;
		}
	}
	return 0;
}

//管理员登录验证
bool Login::Mana_vertity()
{
	std::string name;
	int pwd;

	std::cout << "输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "输入密码" << std::endl;
	std::cin >> pwd;

	for (auto mit = this->managers.begin(); mit != this->managers.end(); mit++) {
		if (mit->first == name && mit->second == pwd) {
			this->M_name = mit->first;
			return 1;
		}
	}
	
	return 0;
}


//析构函数
Login::~Login()
{
	this->managers.clear();
	this->stu.clear();
	this->tcher.clear();
}