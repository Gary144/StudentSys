/*ѧ����Ϣ���洰��*/
#pragma once//����һ��

#include <QtWidgets/QMainWindow>//Qt�����������������Ҫ�õ���ͷ�ļ�
#include "ui_StudentGradePro.h"//ʹ��UI�ļ�Ҫ���õ�ͷ�ļ�
#include "Def.h"//����һЩ��Ҫ�õ���ͨ��ͷ�ļ��������ݽṹ��

class StudentGradePro : public QMainWindow//������һ��StudentGradePro���࣬���м̳��� QMainWindow(����)
{
	Q_OBJECT//Qt�����һ���꣬Qt�ĸ��ֲ���������������

public://������
	StudentGradePro(QWidget *parent = Q_NULLPTR);//���캯��

private://˽����
	Ui::StudentGradeProClass ui;//����ui
};
