/*������һ���������Ҫ���������ͣ���Ҫ�����ļ��Ķ�д�����ݵĴ���*/
#pragma once//����һ��
#include "def.h"//��������Ҫ�õ��Ĺ���ͷ�ļ�

//�ؼ���static���ñ����ͱ������Ϊһ����̬ȫ�ֱ����������Զ�����
static QMap<string, StudentTag> g_studentMap;//������һ����̬����Qmap����������ѧ����Ϣ
static QMap<string, string> g_studentUserMap;//������һ����̬����Qmap����������ѧ���û���Ϣ
static QMap<string, string> g_teaherUserMap;//������һ����̬����Qmap������������ʦ�û���Ϣ
static string g_currentStudentNum;//������һ����̬����string�����������û������ѧ��

class Units
{
public://������
	Units();//���캯��
	~Units();//��������

public://�����࣬������һЩ�������Ҷ�����һЩ����
	static void WriteFile(const std::string fileName, std::vector<std::string> data);
	/*
	������һ����̬ȫ�ֺ���WriteFile()
	����Ϊһ��string(������ʾ�ļ���)��һ��vector<string>(������ʾѧ������)
	*/
	static vector<vector<string>> ReadFile(const std::string fileName);
	/*
	������һ����̬ȫ�ֱ���ReadFile
	���Ա����أ�������Ϊ�ļ���
	*/
	static void setStudentMap(QMap<string, StudentTag> studentMap);
	/*
	������һ����̬ȫ�ֺ���setStudentMap()
	����Ϊһ��Qmap<string,StudentTag>��������ʾѧ����Ϣ
	*/
	static QMap<string, StudentTag> getStudentMap();
	/*
	������һ����̬ȫ�ֺ���getStudentMap()����������ѧ����Ϣ
	*/
	static void setStudentUserMap(QMap<string, string> studentUserMap);
	/*
	������һ����̬ȫ�ֺ���setStudentUserMap()
	����Ϊһ��Qmap<string,string>��������ʾѧ���û���Ϣ
	*/
	static QMap<string, string> getStudentUserMap();
	/*
	������һ����̬ȫ�ֺ���getStudentUserMap()����������ѧ���û���Ϣ
	*/
	static void setTeaherUserMap(QMap<string, string> teacherUserMap);
	/*
	������һ����̬ȫ�ֺ���setTeaherUserMap()
	����Ϊһ��Qmap<string,string>��������ʾ��ʦ�û���Ϣ
	*/
	static QMap<string, string> geTeacherUserMap();
	/*
	������һ����̬ȫ�ֺ���geTeacherUserMap()������������ʦ�û���Ϣ
	*/
	static void SetCurrentStudentNum(const string& num);
	/*
	������һ����̬ȫ�ֺ���setTeaherUserMap()
	����Ϊһ��string��������ʾѧ��
	*/
	static string getCurrentStudentNum();
	/*
	������һ����̬ȫ�ֺ���getCurrentStudentNum()���������������ѧ��
	*/
public:
	
};

