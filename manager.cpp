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
		cout << "用户" << this->Ma_log.M_name << "正在使用系统" << endl;

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
			cout << "用户名:" << mit->second.first << "  " << "编号:" << mit->first << endl;
		}
	}
	else {
		cout << "无学生用户" << endl;
	}

	//输出教师用用户
	if (!this->Ma_log.TeaIsEmpty) {
		cout << "------教师用户-------" << endl;
		for (map<int, pair<string, int>>::iterator mit = this->Ma_log.tcher.begin(); mit != this->Ma_log.tcher.end(); mit++) {
			cout << "用户名:" << mit->second.first << "  " << "编号:" << mit->first << endl;
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

	int id;
	int pwd;
	string name;


	//设置新用户账号信息
	cout << "输入用户编号 1-50" << endl;      //待改进-----输入类型不匹配   依据数据类型的大小判断
	cin >> id;
	
	while (sizeof(id) != sizeof(int)) {
		cout << "输入编号无效，请重新输入" << endl;
		cin >> id;
	}

	while (this->IdExist(id)) {
		cout << "编号已存在，请重新输入" << endl;
		cin >> id;
	}

	cout << "输入用户名" << endl;
	cin >> name;

	cout << "输入用户初始密码" << endl;
	cin >> pwd;

	//将新添加的用户账号添加至相关存储容器
	if (select == 1) {
		this->Ma_log.tcher.insert(make_pair(id, make_pair(name, pwd)));
	}
	else {
		this->Ma_log.stu.insert(make_pair(id, make_pair(name, pwd)));
	}

	//保存新账号至文件 
	
	this->userSave(select,id);
	this->Ma_log.Load();
	cout << "添加成功" << endl;
}

//查看机房信息
void Manager::showlabInf()
{
	for (map<int, int>::iterator mit = this->Ma_lab.labInf.begin(); mit != this->Ma_lab.labInf.end(); mit++) {
		cout << "机房编号\t" << mit->first << "机房容量" << mit->second << endl;
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

//清空所有预约记录
void Manager::clearApp()
{
	int select;
	cout << "确定清空 1.确定 2.取消" << endl;
	cin >> select;

	if (select == 1) {
		//调用lab内的接口  清空文件
		this->Ma_lab.fileclear();
		this->Ma_lab.Load();
		cout << "清空成功" << endl;
	}
	else {
		cout << "已取消" << endl;
	}
	
}

//保存新用户账号
void Manager::userSave(int type,int key)
{
	ofstream ofs;
	if (type == 1)   //新用户为教师
	{
		ofs.open("teacher.txt",ios::app);
	}
	else			 //新用户为学生
	{
		ofs.open("student.txt",ios::app);
	}

	if (!ofs.is_open())
	{
		cout << "添加账号失败，请检查相关文件" << endl;
	}
	else {
		
		if (type == 1) {   //将新添加的教师账号保存至文件
			ofs << key << "  " << this->Ma_log.tcher[key].first << "  " << this->Ma_log.tcher[key].second;
			ofs << endl;
		}
		else{				//将新添加的学生账号保存至文件
			ofs << key << "  " << this->Ma_log.stu[key].first << "  " << this->Ma_log.stu[key].second;
			ofs << endl;
		}
		
	}
	ofs.close();
}

//析构函数
Manager::~Manager()
{

}