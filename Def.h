/*���ͷ�ļ��ǰ�������Ҫ���õ��Ĺ���ͷ�ļ����������ͣ����ں�������*/
#pragma once//����һ��
#pragma warning(disable:4996)//��ֹ�ϰ汾��������

#include <string>//�ַ�������ͷ�ļ�
#include <iostream>//��׼���������
#include <vector>//����������
#include <map>//����
#include<fstream>//�ļ��������������
#include<cmath>//��ѧ��������ͷ�ļ�
#include<stack>//���ջ�йص�ͷ�ļ�
#include <QScopedPointer>//Qt����ָ��
#include <QtCore/qglobal.h>//Qt���ģ��ں���ص�ͷ�ļ�
#include <QVariant>//Qt������������Ҫ�õ���ͷ�ļ�
#include <QMap>//Qt�����������ͷ�ļ�

using namespace std;//�����ռ�

//ѧ����Ϣ�ṹ��
struct StudentTag
{
	string _num;//ѧ��
	string _name;//����
	string _sex ;//�Ա�
	string _C;//c���Գɼ�
	string _M;//��ѧ�ɼ�
	string _E;//Ӣ��ɼ�
};