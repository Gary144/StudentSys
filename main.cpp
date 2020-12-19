#include "StudentGradePro.h"
#include <QtWidgets/QApplication>
#include "LoginWidget.h"         //引用头文件
int main(int argc, char *argv[]) //QT标准格式
{
	QApplication a(argc, argv);  //有且只有一个Qt应用程序
	LoginWidget w;               //函数在这部分实现
	w.show();                    //Qt对象默认隐藏需要人为显示
	return a.exec();             /*
					             等待用户操作保持应用运行
					             也可以写成
					             a.exec();
					             return 0;
					             */
}
