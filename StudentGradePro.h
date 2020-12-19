/*学生信息界面窗口*/
#pragma once//编译一次

#include <QtWidgets/QMainWindow>//Qt窗口类和主界面类需要用到的头文件
#include "ui_StudentGradePro.h"//使用UI文件要引用的头文件
#include "Def.h"//引用一些需要用到的通用头文件，和数据结构体

class StudentGradePro : public QMainWindow//定义了一个StudentGradePro子类，公有继承于 QMainWindow(父类)
{
	Q_OBJECT//Qt里面的一个宏，Qt的各种部件都是他的子类

public://公有类
	StudentGradePro(QWidget *parent = Q_NULLPTR);//构造函数

private://私有类
	Ui::StudentGradeProClass ui;//声明ui
};
