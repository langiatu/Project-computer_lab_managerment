#include<iostream>
#include"manager.h"
#include<fstream>

using namespace std;

//构造函数
Manager::Manager()
{
	
}

//显示管理员功能菜单
void Manager::showmenu()
{
	cout << "\t-------------------------" << endl;
	cout << "\t\t1.查看用户账号" << endl;
	cout << "\t\t2.查看机房信息" << endl;
	cout << "\t\t3.清空预约" << endl;
	cout << "\t\t4.添加账号" << endl;
	cout << "\t\t0.注销登录" << endl;
	cout << "\t-------------------------" << endl;
}


//管理员功能管理函数
void Manager::user_Manager()
{
	//登录验证
	if (!this->Ma_log.Mana_vertity()) {
		cout << "用户名或密码错误" << endl;
		return;
	}


	system("cls");
	
	int select;

	while (true) {
		cout << this->Ma_log.M_name << "用户正在使用系统" << endl;

		//显示功能菜单
		this->showmenu();

		cout << "输入选项" << endl;
		cin >> select;

		switch (select) {
		case 1:     //查看用户账号
			this->showUserInf();
			break;
		case 2:     //查看机房信息
			this->showlabInf();
			break;
		case 3:     //清空预约
			this->clearAppoint();
			break;
		case 4:
			this->addUser();
			break;
		case 0:		//注销登录
			return;
		default:
			cout << "输入错误请重新输入" << endl;
			system("pause");
		}
		system("pause");
		system("cls");
	}

}

//显示用户信息
void Manager::showUserInf()
{
	//输出学生用户
	if (!this->Ma_log.StuIsEmpty) {
		cout << "------学生用户-------" << endl;
		for (map<int, pair<string, int>>::iterator mit = this->Ma_log.stu.begin(); mit != this->Ma_log.stu.end(); mit++) {
			cout << "用户名\t" << mit->second.first << "  " << "编号\t" << mit->first << endl;
		}
	}
	else {
		cout << "无学生用户" << endl;
	}

	//输出教师用用户
	if (!this->Ma_log.TeaIsEmpty) {
		cout << "------教师用户-------" << endl;
		for (map<int, pair<string, int>>::iterator mit = this->Ma_log.tcher.begin(); mit != this->Ma_log.tcher.end(); mit++) {
			cout << "用户名\t" << mit->second.first << "  " << "编号\t" << mit->first << endl;
		}
	}
	else {
		cout << "无教师用户" << endl;
	}
}

//清空预约
void Manager::clearAppoint()
{
	ofstream ofs;
	
	
	int select;
	cout << "确定清空 1.确定 0.取消" << endl;
	cin >> select;
	if (select == 1) {
		ofs.open("appointment.txt", ios::trunc);
		if (ofs.is_open()) {
			cout << "已清空" << endl;
			ofs.close();
			return;
		}
		else {
			cout << "清空出错" << endl;
		}
	}

}

//添加用户账号
void Manager::addUser()
{
	int select;
	cout << "1.添加教师账号 2.添加学生账号" << endl;
	cin >> select;
	if (select != 1 && select != 2) {
		cout << "输入无效，请重新输入" << endl;
		cin >> select;
	}
	ofstream ofs;
	if (select == 1) {  //打开教师账号保存文件
		ofs.open("teacher.txt",ios::out);
	}
	else {				//打开学生账号保存文件
		ofs.open("student.txt", ios::out);
	}

	if (!ofs.is_open()) {
		cout << "无法添加，请检查相关文件" << endl;
		return;
	}

	int id;
	int pwd;
	string name;


	
	cout << "输入用户编号" << endl;      //待改进-----输入类型不匹配
	cin >> id;
	
	while (this->IdExist(id)) {
		cout << "编号已存在，请重新输入" << endl;
		cin >> id;
	}

	cout << "输入用户名" << endl;
	cin >> name;

	cout << "输入用户初始密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	if (select == 1) {
		this->Ma_log.tcher.insert(make_pair(id, make_pair(name, pwd)));
	}
	else {
		this->Ma_log.stu.insert(make_pair(id, make_pair(name, pwd)));
	}

	
	this->Ma_log.Load();

	cout << "添加成功" << endl;
}

//查看机房信息
void Manager::showlabInf()
{
	for (map<int, int>::iterator mit = this->lab.labInf.begin(); mit != this->lab.labInf.end(); mit++) {
		cout << "机房编号" << mit->first << "机房容量" << mit->second << endl;
	}
}

//检测用户id是否存在
bool Manager::IdExist(int id)
{
	for (map<int, pair<string, int>>::iterator mit = this->Ma_log.stu.begin(); mit != this->Ma_log.stu.end(); mit++) {
		if (mit->first == id) {
			return true;
		}
	}

	for (map<int, pair<string, int>>::iterator mit = this->Ma_log.tcher.begin(); mit != this->Ma_log.tcher.end(); mit++) {
		if (mit->first == id) {
			return true;
		}
	}

	return false;
}

//析构函数
Manager::~Manager()
{

}