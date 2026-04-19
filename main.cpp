#include<iostream>
using namespace std;
#include "Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

#include "Login.h"

int main()
{
	int chioce;


	while (true)
	{
		cout << "\t-------------------------" << endl;
		cout << "\t\t1.学生登录" << endl;
		cout << "\t\t2.教师登录" << endl;
		cout << "\t\t3.管理员登录" << endl;
		cout << "\t\t0.退出系统" << endl;
		cout << "\t-------------------------" << endl;

		cout << "输入选项" << endl;
		cin >> chioce;

		Login log;
		switch (chioce) {
		case 1:   //学生
		{
			if (log.Stu_vertity()) {
				Student stu;
				stu.user_Manager();
			}
			break;
		}
		case 2:   //教师
		{
			if (log.Tea_vertity()) {
				Teacher tea;
				tea.user_Manager();
			}
			
			break;
		}
		case 3:   //管理员
		{
			
				Manager mana;
				mana.user_Manager();
			
			break;
		}
		case 0:   //退出系统
		{
			cout << "正在退出...." << endl;
			return 0;
		}
		default:
		{
			cout << "输入错误，请重新输入" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}


	system("pause");
	return 0;
}