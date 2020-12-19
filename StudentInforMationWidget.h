#pragma once//编译一次

#include <QWidget>//Qt窗口类的头文件
#include "ui_StudentInforMationWidget.h"//为了使用 StudentInforMationWidget.ui 这个ui文件，这个头文件由qt自动生成

class StudentInforMationWidget : public QWidget//定义了一个 StudentInforMationWidget 的子类，公有继承于QWidget这个类
{
	Q_OBJECT//Qt里面的一个宏，Qt的各种部件都是他的子类

public://公有类
	StudentInforMationWidget(QWidget *parent = Q_NULLPTR);//构造函数
	~StudentInforMationWidget();//析构函数

private://私有类
	Ui::StudentInforMationWidget ui;//声明ui
};
