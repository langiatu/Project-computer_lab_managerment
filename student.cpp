#include<iostream>
#include"student.h"
#include<fstream>
#include <string>

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

	//登陆验证
	if (!this->Stu_log.Stu_vertity()) {
		cout << "用户名或密码错误" << endl;
		return;
	}

	this->user_name = this->Stu_log.M_name;
	this->user_id = this->Stu_log.M_id;

	system("cls");
	int select;

	while (true) {
		cout << "用户" << this->Stu_log.M_name << "正在使用系统" << endl;

		//显示功能菜单
		this->showmenu();

		cout << "输入选项" << endl;
		cin >> select;

		switch (select) {
		case 1:     //申请预约
			this->addAppoint();
			break;
		case 2:     //查看预约记录
			this->showMyApp();
			break;
		case 3:     //查看所有预约
			this->showAppoint();
			break;
		case 4:		//取消预约
			this->cancelAppoint();
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

//申请预约
void Student::addAppoint()
{
	//用于接收新纪录的信息
	Appointment appoint;

	appoint.uid = this->user_id;

	cout << "选择需要预约的机房 1.1号 2.2号 3.3号" << endl;
	cin >> appoint.rid;
	while (appoint.rid != 1 && appoint.rid != 2 && appoint.rid != 3) {
		cout << "请输入正确的选项" << endl;
		cin >> appoint.rid;
	}

	int ftime;
	int stime;
	cout << "选择预约时间 1-5 周一至周五" << endl;
	cin >> ftime;
	while(ftime > 5 || ftime < 1) {
		cout << "请输入正确的选项" << endl;
		cin >> ftime;
	}
	switch (ftime) {
	case 1:
		appoint.time.first = "周一";
		break;
	case 2:
		appoint.time.first = "周二";
		break;
	case 3:
		appoint.time.first = "周三";
		break;
	case 4:
		appoint.time.first = "周四";
		break;
	case 5:
		appoint.time.first = "周五";
		break;
	}

	cout << "1.上午 2.下午" << endl;
	cin >> stime;
	while (stime != 1 && stime != 2) {
		cout << "请输入正确的选项" << endl;
		cin >> stime;
	}

	switch (stime) {
	case 1:
		appoint.time.second = "上午";
		break;
	case 2:
		appoint.time.second = "下午";
	}


	appoint.sta.first = 0;
	appoint.sta.second = "审核中";

	this->Stu_lab.appoint.push_back(appoint);
	this->Stu_lab.appointSave();

	cout << "提交申请成功" << endl;
	this->Stu_lab.appointIsEmpty = false;
}


//查看所有预约     
void Student::showAppoint()
{
	if (this->Stu_lab.appointIsEmpty) {
		cout << "无预约记录" << endl;
	}
	else {
		
		for (vector<Appointment>::iterator it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
			cout << "用户：" << this->Stu_log.stu[it->uid].first << "  机房：" << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.second << endl;
		}
	}
}

//查看本用户的申请
void Student::showMyApp()
{
	//从保存记录的容器中筛选预约记录的用户编号为本用户编号的记录
	for (vector<Appointment>::iterator it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
		if (it->uid == this->user_id) {
			cout << "用户：" << this->user_name << "  机房：" << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.second << endl;
		}
	}
}

void Student::cancelAppoint()
{
	int flag;
	flag = 0; //假设暂无预约可以取消

	//输出需要审核的预约记录
	for (vector<Appointment>::iterator it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
		if (it->sta.first == 0 && it->uid == this->user_id) {
			cout << "用户：" << it->uid << "  机房：" << it->rid << "  " << it->time.first << it->time.second << "  " << it->sta.second << endl;
			flag = 1;
		}
		else {
			continue;
		}

		//取消 ---- 修改预约记录的状态
		int select;
		cout << "是否确定取消 1.确定 2.返回" << endl;
		cin >> select;
		while (select != 1 && select != 2) {
			cout << "输入无效请重新输入" << endl;
			cin >> select;
		}

		if (select == 1) {
			it->sta.first = 1;
			it->sta.second.clear();
			it->sta.second = "已取消";

		}
		else {
			continue;
		}
	}

	if (flag == 1) {    //有需要取消的记录
		cout << "取消完成" << endl;
		//保存更改至文件
		this->Stu_lab.appointSave();
		this->Stu_lab.Load();
	}
	else {
		cout << "无可以被取消的预约" << endl;
	}
}

//析构函数
Student::~Student()
{

}