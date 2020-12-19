#include "StudentGradePro.h"										 //包含所需头文件

StudentGradePro::StudentGradePro(QWidget *parent)
	: QMainWindow(parent)										     //构造函数以列表方式传参
{
	ui.setupUi(this);												 // setupUi(this)是由.ui文件生成的类的构造函数，作用是对界面进行初始化，
																	 //它按照Qt设计器里设计的样子把窗体画出来，把Qt设计器里面定义的信号和槽建立起来。
																	 // 也可以说，setupUi是界面和写程序之间的桥梁。
}
