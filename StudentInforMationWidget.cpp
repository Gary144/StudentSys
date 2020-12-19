#include "StudentInforMationWidget.h"												//显示学生信息界面所需要使用的函数声明，类的声明，公有头文件，数据结构体
#include "Def.h"																	//所需要使用的函数声明，类的声明，公有头文件，数据结构体
#include "Units.h"																	//文件数据辅助函数头文件
#include <QTabWidget>																//Qt制表头文件
#include <QTableWidgetItem>															//动态往Qt表格里加数据需要的库
#include <QPainter>																	//Qt画笔头文件
#include <QPalette>																	//调色板头文件
#include <QPixmap>																	//Qt绘图设备要用的头文件
#include <QString>																	//Qt字符串操作用的头文件
#include <QBrush>																	//Qt画刷头文件
StudentInforMationWidget::StudentInforMationWidget(QWidget *parent)
	: QWidget(parent)																//实现构造函数并且以列表形式传参
																					//构造函数自动调用不需要人为调用
{
	ui.setupUi(this);																//设置一个界面

	ui.tableWidget->setRowCount(6);													//制表，竖着六个单元格
	ui.tableWidget->setColumnCount(1);												//制表，横着一个单元格
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//将读取并且储存了的学生信息赋值
	string num = Units::getCurrentStudentNum();										//初始化
	QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);				//迭代器，寻找到和学号对应的信息
	if (iter != Units::getStudentMap().end())										//当迭代器还没有迭代到底
	{
		StudentTag student = iter.value();											//获取迭代器里面的值
		QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
		QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
		QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
		QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
		QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
		QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());			//c_str是为了将数据转化为c里面的str类型，便于操作
																					/*
																					声明QtableWidgetItem组件指针，并且新建，赋值
																					*/
		ui.tableWidget->setItem(0, 0, numItem);
		ui.tableWidget->setItem(1, 0, nameItem);
		ui.tableWidget->setItem(2, 0, sexItem);
		ui.tableWidget->setItem(3, 0, CItem);
		ui.tableWidget->setItem(4, 0, MItem);
		ui.tableWidget->setItem(5, 0, EItem);
																					//通过指针的间接访问将成绩在界面中打印出来
	}
}

StudentInforMationWidget::~StudentInforMationWidget()								//析构函数
{
}

