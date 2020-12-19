/*这个头文件是包含所需要的用到的公用头文件和数据类型，便于后续操作*/
#pragma once//编译一次
#pragma warning(disable:4996)//防止老版本函数报错

#include <string>//字符串操作头文件
#include <iostream>//标准输入输出流
#include <vector>//向量，容器
#include <map>//容器
#include<fstream>//文件操作输入输出流
#include<cmath>//数学函数操作头文件
#include<stack>//与堆栈有关的头文件
#include <QScopedPointer>//Qt智能指针
#include <QtCore/qglobal.h>//Qt核心，内核相关的头文件
#include <QVariant>//Qt数据联合所需要用到的头文件
#include <QMap>//Qt里面的容器的头文件

using namespace std;//命名空间

//学生信息结构体
struct StudentTag
{
	string _num;//学号
	string _name;//姓名
	string _sex ;//性别
	string _C;//c语言成绩
	string _M;//数学成绩
	string _E;//英语成绩
};