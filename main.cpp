#include<iostream>
#include "Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

#include "Login.h"

int main()
{
	int choice;


	while (true)
	{
		std::cout << "\t-------------------------" << std::endl;
		std::cout << "\t\t1.学生登录" << std::endl;
		std::cout << "\t\t2.教师登录" << std::endl;
		std::cout << "\t\t3.管理员登录" << std::endl;
		std::cout << "\t\t0.退出系统" << std::endl;
		std::cout << "\t-------------------------" << std::endl;

		std::cout << "输入选项" << std::endl;
		std::cin >> choice;

		Login log;
		switch (choice) {
		case 1:   //学生
		{
			std::unique_ptr<Identity> user = std::make_unique<Student>();
			user->user_Manager();
			break;
		}
		case 2:   //教师
		{
			std::unique_ptr<Identity> user = std::make_unique<Teacher>();
			user->user_Manager();	
			break;
		}
		case 3:   //管理员
		{
			std::unique_ptr<Identity> user = std::make_unique<Manager>();
			user->user_Manager();	
			break;
		}
		case 0:   //退出系统
		{
			std::cout << "正在退出...." << std::endl;
			return 0;
		}
		default:
		{
			std::cout << "输入错误，请重新输入" << std::endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}


	system("pause");
	return 0;
}