#include "LoginWidget.h"						//登录界面所需要的使用的函数声明，类的声明，公有头文件，数据结构体
#include "ui_LoginWidget.h"						//使用UI文件所需要的引用的头文件
#include "StudentInforMationWidget.h"			//学生用户登陆以后信息显示界面所需要的使用的函数声明，类的声明，公有头文件，数据结构体
#include "TeacherManagerWidget.h"				//教室用户登录以后管理界面所需要的使用的函数声明，类的声明，公有头文件，数据结构体所需要的引用的头文件
#include "Units.h"								//与文件操作有关的数据，函数所需要的引用的头文件

#include <QMessageBox>												//Qt弹窗类所需要的引用的头文件
#include <QPalette>													//Qt调色板类所需要的引用的头文件
#include <QPixmap>													//Qt绘图设备的图像显示所需要的引用的头文件
#include <QString>													//Qt字符串所需要的引用的头文件
#include <QBrush>													//Qt画刷所需要的引用的头文件

#if defined(_MSC_VER)&&(_MSC_VER > 1700)
#pragma execution_character_set("utf-8")
#endif																//防止中文乱码，使用utf-8编码

class LoginWidgetPrivate											//这个类在头文件里已经声明过了，这里具体展开
{
	Q_DECLARE_PUBLIC(LoginWidget)									//Qt里面的一个宏，用来获取LoginWidget的q指针

public:																//公有类
	LoginWidgetPrivate();											//构造函数
	~LoginWidgetPrivate() { delete ui; }							//析构函数，析构函数的内容是删除UI界面

private:															//私有类
	void initSetting(void);											//声明函数
private:
	LoginWidget* q_ptr;//q指针
	Ui_LoginWidget* ui;//ui指针
	StudentInforMationWidget* m_pStudentInforMationWidget;//界面指针
	TeacherManagerWidget* m_pTeacherManagerWidget;		  //界面指针
};


LoginWidgetPrivate::LoginWidgetPrivate()							//构造函数的实现
	:ui(new Ui_LoginWidget)
	,m_pStudentInforMationWidget(nullptr)
	, m_pTeacherManagerWidget(nullptr)								//以列表的方式向构造函数里传参，并且初始化部分指针为null
{
	Q_Q(LoginWidget);												//获取LoginWidget的q指针
	initSetting();													//调用函数initSetting(); 具体函数在下方
}

void LoginWidgetPrivate::initSetting(void)							//实现声明的函数
{
	QMap<string, string> teacherUserMap;							//Qmap是Qt里的一种数据容器，这里声明一个新的Qmap变量
	vector<vector<string>> teacherDatas = Units::ReadFile("teacherUser.txt");
																	//调用ReadFile函数，读取文本文件里的内容，并将其保存在二维vector里面
	for (int i = 0; i < teacherDatas.size();i++)					//行数，有几行读取几行
																	//将内容由Vector类型转化为Qmap类型，并储存
	{
		vector<string> line = teacherDatas.at(i);
		if (line.size() == 2)										//列数，2列
		{
			teacherUserMap[(line.at(0).c_str())] = (line.at(1).c_str());
		}
	}
	Units::setTeaherUserMap(teacherUserMap);						//调用Units里面的函数，参数是teacherUserMap，转换为静态全局变量
	
	QMap<string, string>studentUserMap;								//Qmap是Qt里的一种数据容器，这里声明一个新的Qmap变量
	vector<vector<string>> studentDatas = Units::ReadFile("studentUser.txt");
																	//调用ReadFile函数，读取文本文件里的内容，并将其保存在二维vector里面
	for (int i = 0; i < studentDatas.size();i++)					//将内容由Vector类型转化为Qmap类型，并储存
	{
		vector<string> line = studentDatas.at(i);
		if (line.size() == 2)
		{
			studentUserMap[(line.at(0).c_str())] = (line.at(1).c_str());
		}
	}
	Units::setStudentUserMap(studentUserMap);						//调用Units里面的函数，参数是studentUserMap
	
	QMap<string, StudentTag> studentinfoMap;						//Qmap是Qt里的一种数据容器，这里声明一个新的Qmap变量
	vector<vector<string>> studentInfoDatas = Units::ReadFile("StudentInfo.txt");
																	//调用ReadFile函数，读取文本文件里的内容，并将其保存在二维vector里面
	for (int i = 0; i < studentInfoDatas.size();i++)				//将内容由Vector类型转化为Qmap类型，并储存
	{
		vector<string> line = studentInfoDatas.at(i);
		if (line.size() == 6)
		{
			StudentTag student;
			student._num = line.at(0);
			student._name = line.at(1);
			student._sex = line.at(2);
			student._C = line.at(3);
			student._M = line.at(4);
			student._E = line.at(5);
			studentinfoMap[student._num] = student;					//studentinfomap的唯一标识符是学号student._num
		}
	}
	Units::setStudentMap(studentinfoMap);							//调用Units里面的函数，参数是studentinfoMap
}

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)												//以列表的形式给构造函数传参
	,d_ptr(new LoginWidgetPrivate)                                  //想要在LOginWidget里面使用LWP的d指针，必须要在构造函数传参的时候new出来
{
	initSetting();

	initConnect();
}

LoginWidget::~LoginWidget()											//LoginWidget的析构函数，为Disconnect()
{
	disConnect();
}

void LoginWidget::initSetting()
{
	Q_D(LoginWidget);												//获取LoginWidget的D指针，便于从子类访问父类
	d->q_ptr = this;												//使用private类访问public类
	d->ui->setupUi(this);											//先构建一个QWidget界面，再加载xml构建出我们创建的ui界面
	QMetaObject::connectSlotsByName(this);							//QObject的某些信号按照其objectName连接到槽上。
}

void LoginWidget::initConnect()
{
	Q_D(LoginWidget);												//获取LoginWidget的D指针，便于访问
	connect(d->ui->pushButton, &QPushButton::clicked,this, &LoginWidget::on_loginBtnClicked);
	connect(d->ui->pushButton_2, &QPushButton::clicked, this, &LoginWidget::close);
}																	//链接信号和槽
void LoginWidget::disConnect()
{
	Q_D(LoginWidget);												//获取LoginWidget的D指针，便于访问
	disconnect(d->ui->pushButton, &QPushButton::clicked, this, &LoginWidget::on_loginBtnClicked);
	disconnect(d->ui->pushButton_2, &QPushButton::clicked, this, &LoginWidget::close);
}																	//断开信号和槽的链接

void LoginWidget::on_loginBtnClicked()								//槽函数
{
	Q_D(LoginWidget);												//获取LoginWidget的D指针，便于访问
	QString typeStr = d->ui->comboBox->currentText();				//声明一个Qstring类型变量，并且将输入框里面的值赋给它
	if (typeStr == "学生")											//如果选择的是学生
	{
		string userName = d->ui->lineEdit->text().toStdString().c_str();
		string password = d->ui->lineEdit_2->text().toStdString().c_str();
		/*通过层层指针的访问将输入框里面的值赋值给两个新声明的string变量*/
		QMap<string, string> studentUserMap = Units::getStudentUserMap();	//将读取的学生用户原数据放进Qmap<string,string>
		QMap<string, string>::iterator iter = studentUserMap.find(userName);//迭代器，在储存好了的数据里面寻找和输入相匹配的值
		if (iter != studentUserMap.end()/*迭代器还没有到studentUserMap的末尾*/)
		{
			if (iter.value() == password)									//迭代器里面的值和password里面的值相等
			{
				Units::SetCurrentStudentNum(userName);						//调用units里的函数
				d->m_pStudentInforMationWidget = new StudentInforMationWidget();
				d->m_pStudentInforMationWidget->show();						//显示学生信息界面
			}
			else
			{
				QMessageBox::warning(nullptr, tr("提示"), tr("登录密码错误"));
			}
			
		}
		else
		{
			QMessageBox::warning(nullptr, tr("提示"), tr("用户不存在"));
		}
	}
	else if (typeStr == "教员")												//如果选择的是教员
	{
		string userName = d->ui->lineEdit->text().toStdString().c_str();
		string password = d->ui->lineEdit_2->text().toStdString().c_str();
		/*通过层层指针的访问将输入框里面的值赋值给两个新声明的string变量*/
		QMap<string, string> teacherUserMap = Units::geTeacherUserMap();
		QMap<string, string>::iterator iter = teacherUserMap.find(userName);//迭代器，在储存好了的数据里面寻找和输入相匹配的值
		if (iter != teacherUserMap.end()/*迭代器还没有到teacherUserMap的末尾*/)
		{
			if (iter.value() == password)
			{
				d->m_pTeacherManagerWidget = new TeacherManagerWidget();
				d->m_pTeacherManagerWidget->show();							//显示教师管理界面
			}
			else
			{
				QMessageBox::warning(nullptr, tr("提示"), tr("登录密码错误"));
			}
		}
		else
		{
			QMessageBox::warning(nullptr, tr("提示"), tr("用户不存在"));
		}
	}
	this->close();															//关闭现有登录窗口
}