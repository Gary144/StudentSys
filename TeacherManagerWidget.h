/*这个头文件引用了一些教师管理界面所需要用到的类以及公用头文件，还有成员函数*/
#pragma once//编译一次

#include <QWidget>//Qt窗口类头文件
#include "ui_TeacherManagerWidget.h"//使用UI文件
#include "Def.h"//引用公有头文件和数据结构体

class TeacherManagerWidget : public QWidget//定义了一个子类 TeacherManagerWidget ，公有继承于QWidget
{
	Q_OBJECT//Qt里面的一个宏，Qt的各种部件都是他的子类

public://公有类
	TeacherManagerWidget(QWidget *parent = Q_NULLPTR);//构造函数
	~TeacherManagerWidget();//析构函数
public Q_SLOTS ://公有槽函数类
	void on_OkClicked();
	void on_comboxChanged(const QString&);
private://公有函数（非槽类）
	void initSetting(void);
	void initConnect(void);
	void disConnect(void);

	void find();//查找功能
	void edit();//编辑功能
	void add();//增加功能
	void remove();//删除功能
	void sort();//排序功能
	void display();//显示功能
	void average();//求平均功能
	void save();//保存功能
private:
	Ui::TeacherManagerWidget ui;//定义ui
};
