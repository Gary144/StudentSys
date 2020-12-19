#include "StudentInforMationWidget.h"												//��ʾѧ����Ϣ��������Ҫʹ�õĺ����������������������ͷ�ļ������ݽṹ��
#include "Def.h"																	//����Ҫʹ�õĺ����������������������ͷ�ļ������ݽṹ��
#include "Units.h"																	//�ļ����ݸ�������ͷ�ļ�
#include <QTabWidget>																//Qt�Ʊ�ͷ�ļ�
#include <QTableWidgetItem>															//��̬��Qt������������Ҫ�Ŀ�
#include <QPainter>																	//Qt����ͷ�ļ�
#include <QPalette>																	//��ɫ��ͷ�ļ�
#include <QPixmap>																	//Qt��ͼ�豸Ҫ�õ�ͷ�ļ�
#include <QString>																	//Qt�ַ��������õ�ͷ�ļ�
#include <QBrush>																	//Qt��ˢͷ�ļ�
StudentInforMationWidget::StudentInforMationWidget(QWidget *parent)
	: QWidget(parent)																//ʵ�ֹ��캯���������б���ʽ����
																					//���캯���Զ����ò���Ҫ��Ϊ����
{
	ui.setupUi(this);																//����һ������

	ui.tableWidget->setRowCount(6);													//�Ʊ�����������Ԫ��
	ui.tableWidget->setColumnCount(1);												//�Ʊ�����һ����Ԫ��
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//����ȡ���Ҵ����˵�ѧ����Ϣ��ֵ
	string num = Units::getCurrentStudentNum();										//��ʼ��
	QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);				//��������Ѱ�ҵ���ѧ�Ŷ�Ӧ����Ϣ
	if (iter != Units::getStudentMap().end())										//����������û�е�������
	{
		StudentTag student = iter.value();											//��ȡ�����������ֵ
		QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
		QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
		QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
		QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
		QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
		QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());			//c_str��Ϊ�˽�����ת��Ϊc�����str���ͣ����ڲ���
																					/*
																					����QtableWidgetItem���ָ�룬�����½�����ֵ
																					*/
		ui.tableWidget->setItem(0, 0, numItem);
		ui.tableWidget->setItem(1, 0, nameItem);
		ui.tableWidget->setItem(2, 0, sexItem);
		ui.tableWidget->setItem(3, 0, CItem);
		ui.tableWidget->setItem(4, 0, MItem);
		ui.tableWidget->setItem(5, 0, EItem);
																					//ͨ��ָ��ļ�ӷ��ʽ��ɼ��ڽ����д�ӡ����
	}
}

StudentInforMationWidget::~StudentInforMationWidget()								//��������
{
}

