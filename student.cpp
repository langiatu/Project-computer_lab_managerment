#include<iostream>
#include"student.h"

using namespace std;

//构造函数
Student::Student() 
{

}


//显示学生功能菜单
void Student::showmenu()
{
	cout << "\t-------------------------" << endl;
	cout << "\t\t1.申请预约" << endl;
	cout << "\t\t2.查看预约记录" << endl;
	cout << "\t\t3.查看所有预约" << endl;
	cout << "\t\t4.取消预约" << endl;
	cout << "\t\t0.注销登录" << endl;
	cout << "\t-------------------------" << endl;
}

//学生功能管理函数
void Student::user_Manager()
{
	system("cls");
	int select;

	while (true) {
		//显示功能菜单
		this->showmenu();

		cout << "输入选项" << endl;
		cin >> select;

		switch (select) {
		case 1:     //申请预约
			break;
		case 2:     //查看预约记录
			break;
		case 3:     //查看所有预约
			break;
		case 4:		//取消预约
			break;
		case 0:		//注销登录
			return;

		default:
			cout << "输入错误请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}


}

//析构函数
Student::~Student()
{

}