#pragma once//����һ��

#include <QWidget>//Qt�������ͷ�ļ�
#include "ui_StudentInforMationWidget.h"//Ϊ��ʹ�� StudentInforMationWidget.ui ���ui�ļ������ͷ�ļ���qt�Զ�����

class StudentInforMationWidget : public QWidget//������һ�� StudentInforMationWidget �����࣬���м̳���QWidget�����
{
	Q_OBJECT//Qt�����һ���꣬Qt�ĸ��ֲ���������������

public://������
	StudentInforMationWidget(QWidget *parent = Q_NULLPTR);//���캯��
	~StudentInforMationWidget();//��������

private://˽����
	Ui::StudentInforMationWidget ui;//����ui
};
