#include "StudentGradePro.h"
#include <QtWidgets/QApplication>
#include "LoginWidget.h"         //����ͷ�ļ�
int main(int argc, char *argv[]) //QT��׼��ʽ
{
	QApplication a(argc, argv);  //����ֻ��һ��QtӦ�ó���
	LoginWidget w;               //�������ⲿ��ʵ��
	w.show();                    //Qt����Ĭ��������Ҫ��Ϊ��ʾ
	return a.exec();             /*
					             �ȴ��û���������Ӧ������
					             Ҳ����д��
					             a.exec();
					             return 0;
					             */
}
