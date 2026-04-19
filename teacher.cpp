#include<iostream>
#include "teacher.h"

using namespace std;

//构造函数
Teacher::Teacher()
{

}

//显示教师功能菜单
void Teacher::showmenu()
{
	cout << "\t-------------------------" << endl;
	cout << "\t\t1.审核预约" << endl;
	cout << "\t\t2.查看所有预约" << endl;
	cout << "\t\t0.注销登录" << endl;
	cout << "\t-------------------------" << endl;
}

//教师功能管理函数
void Teacher::user_Manager()
{
	system("cls");
	int select;

	while (true) {
		//显示功能菜单
		this->showmenu();

		cout << "输入选项" << endl;
		cin >> select;

		switch (select) {
		case 1:     //审核预约
			break;
		case 2:     //查看所有预约
			break;
		case 0:		//注销登录
			return;
		default:
			cout << "输入错误请重新输入" << endl;
			system("pause");
		}
	}


}


//析构函数
Teacher::~Teacher()
{

}