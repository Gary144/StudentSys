/*���ͷ�ļ�������һЩ��ʦ�����������Ҫ�õ������Լ�����ͷ�ļ������г�Ա����*/
#pragma once//����һ��

#include <QWidget>//Qt������ͷ�ļ�
#include "ui_TeacherManagerWidget.h"//ʹ��UI�ļ�
#include "Def.h"//���ù���ͷ�ļ������ݽṹ��

class TeacherManagerWidget : public QWidget//������һ������ TeacherManagerWidget �����м̳���QWidget
{
	Q_OBJECT//Qt�����һ���꣬Qt�ĸ��ֲ���������������

public://������
	TeacherManagerWidget(QWidget *parent = Q_NULLPTR);//���캯��
	~TeacherManagerWidget();//��������
public Q_SLOTS ://���вۺ�����
	void on_OkClicked();
	void on_comboxChanged(const QString&);
private://���к������ǲ��ࣩ
	void initSetting(void);
	void initConnect(void);
	void disConnect(void);

	void find();//���ҹ���
	void edit();//�༭����
	void add();//���ӹ���
	void remove();//ɾ������
	void sort();//������
	void display();//��ʾ����
	void average();//��ƽ������
	void save();//���湦��
private:
	Ui::TeacherManagerWidget ui;//����ui
};
