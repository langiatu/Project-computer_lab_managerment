#include<iostream>
#include "teacher.h"

using namespace std;
#include<fstream>

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
	//登陆验证
	if (!this->Teach_log.Tea_vertity()) {
		cout << "用户名或密码错误" << endl;
		return;
	}

	system("cls");
	int select;

	while (true) {
		cout << "用户" << this->Teach_log.M_name << "正在使用系统" << endl;

		//显示功能菜单
		this->showmenu();

		cout << "输入选项" << endl;
		cin >> select;

		switch (select) {
		case 1:     //审核预约
			this->checkappoint();
			break;
		case 2:     //查看所有预约
			this->showAppoint();
			break;
		case 0:		//注销登录
			return;
		default:
			cout << "输入错误请重新输入" << endl;
			
		}
		system("pause");
		system("cls");
	}


}

//查看所有预约    
void Teacher::showAppoint()
{
	if (this->Tea_lab.appointIsEmpty) {
		cout << "预约记录为空" << endl;
	}
	else {
		for (vector<Appointment>::iterator it = this->Tea_lab.appoint.begin(); it != this->Tea_lab.appoint.end(); it++) {
			cout << "用户：" << this->Teach_log.stu[it->uid].first << "  机房：" << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.second << endl;
		}
	}
}


//审核预约
void Teacher::checkappoint()
{
	int flag;
	flag = 0; //假设暂无预约需要审核
	
	//输出需要审核的预约记录
	for (vector<Appointment>::iterator it = this->Tea_lab.appoint.begin(); it != this->Tea_lab.appoint.end(); it++) {
		if (it->sta.first == 0) {
			cout << "用户：" << it->uid << "  机房：" << it->rid << "  " << it->time.first << it->time.second << "  " << it->sta.second << endl;
			flag = 1;
		}
		else {
			continue;
		}

		//审核 ---- 修改预约记录的状态
		int select;
		cout << "是否确定通过 1.通过 2.不通过" << endl;
		cin >> select;
		while (select != 1 && select != 2) {
			cout << "输入无效请重新输入" << endl;
			cin >> select;
		}

		if (select == 1) {
			it->sta.first = 1;
			it->sta.second.clear();
			it->sta.second = "已通过";

		}
		else {
			it->sta.first = 2;
			it->sta.second.clear();
			it->sta.second = "不通过";
		}
	}
	
	if (flag == 1) {    //有需要审核的记录
		cout << "审核完成" << endl;
		//保存更改至文件
		this->Tea_lab.appointSave();
		this->Tea_lab.Load();
	}
	else {
		cout << "无需要审核的预约" << endl;
	}
}

//析构函数
Teacher::~Teacher()
{

}