/*这个头文件的作用是声明一些登录界面需要用到的类和函数*/
#pragma once//编译一次

#include <QWidget>//Qt窗口类需要用到的头文件
#include "Def.h"//引用一些需要用到的通用头文件，和数据结构体

class LoginWidgetPrivate;//定义了一个类，并没有具体描述

class LoginWidget : public QWidget//定义了LoginWidget这个子类，公有继承于QWidget
{
	Q_OBJECT//Qt里面的一个宏，Qt的各种部件都是他的子类

public://公有类：公有都可以访问
	explicit LoginWidget(QWidget *parent = Q_NULLPTR);/*声明为explicit的构造函数不能在隐式转换中使用
													    往构造函数LoginWidget()里传参，参数为QWidget的指针并初始化为NULL
													  */
	~LoginWidget();//析构函数，析构函数和构造函数名一样但是加了~关键字

public:

public Q_SIGNAL ://Q_SIGNAL是Qt一个信号类

public Q_SLOTS ://Q_SLOTS是Qt的槽函数类

    void on_loginBtnClicked();//定义的一个槽函数，槽函数的参数要和信号里面的参数一致
private:

	void initSetting(void);//声明了三个成员函数函数，为私有
	void initConnect(void);
	void disConnect(void);
private:
	Q_DECLARE_PRIVATE(LoginWidget);//Qt里面的一个宏 Q_DECLARE_PRIVATE 这个宏为了获取LoginWidget的d指针
	QScopedPointer<LoginWidgetPrivate> d_ptr;//ScopedPointer是Qt里面的智能指针获取 LoginWidgetPrivate 的d指针
};
