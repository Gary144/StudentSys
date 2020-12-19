/*定义了一个类和所需要的数据类型，主要用于文件的读写，数据的处理*/
#pragma once//编译一次
#include "def.h"//引用所需要用到的公用头文件

//关键字static，该变量就被定义成为一个静态全局变量，不会自动销毁
static QMap<string, StudentTag> g_studentMap;//定义了一个静态变量Qmap，用来储存学生信息
static QMap<string, string> g_studentUserMap;//定义了一个静态变量Qmap，用来储存学生用户信息
static QMap<string, string> g_teaherUserMap;//定义了一个静态变量Qmap，用来储存老师用户信息
static string g_currentStudentNum;//定义了一个静态变量string，用来储存用户输入的学号

class Units
{
public://公有类
	Units();//构造函数
	~Units();//析构函数

public://公有类，声明了一些函数并且定义了一些变量
	static void WriteFile(const std::string fileName, std::vector<std::string> data);
	/*
	定义了一个静态全局函数WriteFile()
	参数为一个string(用来表示文件名)，一个vector<string>(用来表示学生数据)
	*/
	static vector<vector<string>> ReadFile(const std::string fileName);
	/*
	定义了一个静态全局变量ReadFile
	可以被重载，重载名为文件名
	*/
	static void setStudentMap(QMap<string, StudentTag> studentMap);
	/*
	定义了一个静态全局函数setStudentMap()
	参数为一个Qmap<string,StudentTag>，用来表示学生信息
	*/
	static QMap<string, StudentTag> getStudentMap();
	/*
	定义了一个静态全局函数getStudentMap()，用来储存学生信息
	*/
	static void setStudentUserMap(QMap<string, string> studentUserMap);
	/*
	定义了一个静态全局函数setStudentUserMap()
	参数为一个Qmap<string,string>，用来表示学生用户信息
	*/
	static QMap<string, string> getStudentUserMap();
	/*
	定义了一个静态全局函数getStudentUserMap()，用来储存学生用户信息
	*/
	static void setTeaherUserMap(QMap<string, string> teacherUserMap);
	/*
	定义了一个静态全局函数setTeaherUserMap()
	参数为一个Qmap<string,string>，用来表示老师用户信息
	*/
	static QMap<string, string> geTeacherUserMap();
	/*
	定义了一个静态全局函数geTeacherUserMap()，用来储存老师用户信息
	*/
	static void SetCurrentStudentNum(const string& num);
	/*
	定义了一个静态全局函数setTeaherUserMap()
	参数为一个string，用来表示学号
	*/
	static string getCurrentStudentNum();
	/*
	定义了一个静态全局函数getCurrentStudentNum()，用来储存输入的学号
	*/
public:
	
};

