#include<iostream>
#include"student.h"
#include<fstream>
#include <string>

//构造函数
Student::Student()
{

}


//显示学生功能菜单
void Student::showmenu()
{
	std::cout << "\t-------------------------" << std::endl;
	std::cout << "\t\t1.申请预约" << std::endl;
	std::cout << "\t\t2.查看预约记录" << std::endl;
	std::cout << "\t\t3.查看所有预约" << std::endl;
	std::cout << "\t\t4.取消预约" << std::endl;
	std::cout << "\t\t0.注销登录" << std::endl;
	std::cout << "\t-------------------------" << std::endl;
}

//学生功能管理函数
void Student::user_Manager()
{

	//登陆验证
	if (!this->Stu_log.Stu_vertity()) {
		std::cout << "用户名或密码错误" << std::endl;
		return;
	}

	this->user_name = this->Stu_log.M_name;
	this->user_id = this->Stu_log.M_id;

	system("cls");
	int select;

	while (true) {
		std::cout << "用户" << this->Stu_log.M_name << "正在使用系统" << std::endl;

		//显示功能菜单
		this->showmenu();

		std::cout << "输入选项" << std::endl;
		std::cin >> select;

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
			std::cout << "输入错误请重新输入" << std::endl;
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

	std::cout << "选择需要预约的机房 1.1号 2.2号 3.3号" << std::endl;
	std::cin >> appoint.rid;
	while (appoint.rid != 1 && appoint.rid != 2 && appoint.rid != 3) {
		std::cout << "请输入正确的选项" << std::endl;
		std::cin >> appoint.rid;
	}

	int ftime;
	int stime;
	std::cout << "选择预约时间 1-5 周一至周五" << std::endl;
	std::cin >> ftime;
	while(ftime > 5 || ftime < 1) {
		std::cout << "请输入正确的选项" << std::endl;
		std::cin >> ftime;
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

	std::cout << "1.上午 2.下午" << std::endl;
	std::cin >> stime;
	while (stime != 1 && stime != 2) {
		std::cout << "请输入正确的选项" << std::endl;
		std::cin >> stime;
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

	std::cout << "提交申请成功" << std::endl;
	this->Stu_lab.appointIsEmpty = false;
}


//查看所有预约     
void Student::showAppoint()
{
	if (this->Stu_lab.appointIsEmpty) {
		std::cout << "无预约记录" << std::endl;
	}
	else {
		
		for (auto it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
			std::cout << "用户：" << this->Stu_log.stu[it->uid].first << "  机房：" << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.second << std::endl;
		}
	}
}

//查看本用户的申请
void Student::showMyApp()
{
	//从保存记录的容器中筛选预约记录的用户编号为本用户编号的记录
	for (auto it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
		if (it->uid == this->user_id) {
			std::cout << "用户：" << this->user_name << "  机房：" << it->rid << "  " << it->time.first << "  " << it->time.second << "  " << it->sta.second << std::endl;
		}
	}
}

void Student::cancelAppoint()
{
	int flag;
	flag = 0; //假设暂无预约可以取消

	//输出需要审核的预约记录
	for (auto it = this->Stu_lab.appoint.begin(); it != this->Stu_lab.appoint.end(); it++) {
		if (it->sta.first == 0 && it->uid == this->user_id) {
			std::cout << "用户：" << it->uid << "  机房：" << it->rid << "  " << it->time.first << it->time.second << "  " << it->sta.second << std::endl;
			flag = 1;
		}
		else {
			continue;
		}

		//取消 ---- 修改预约记录的状态
		int select;
		std::cout << "是否确定取消 1.确定 2.返回" << std::endl;
		std::cin >> select;
		while (select != 1 && select != 2) {
			std::cout << "输入无效请重新输入" << std::endl;
			std::cin >> select;
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
		std::cout << "取消完成" << std::endl;
		//保存更改至文件
		this->Stu_lab.appointSave();
		this->Stu_lab.Load();
	}
	else {
		std::cout << "无可以被取消的预约" << std::endl;
	}
}

//析构函数
Student::~Student()
{

}