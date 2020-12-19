#include "Units.h"																	//ͷ�ļ������ã�������������������
#include <sstream>																	//�ַ���ͷ�ļ�

void Units::WriteFile(const std::string fileName, std::vector<std::string> data)	//д���ļ�����
{
	ofstream outFile;																//���ļ�
	outFile.open(fileName, ios::out);												//��д���ļ���ģʽ���ļ���Ϊ��FileName�����ļ�
	for (int i = 0; i < data.size();i++)											//ѭ����ʽд���ļ�
	{
		outFile << data.at(i) << endl;												//д�����ݣ�ÿд��һ�оͻ���
	}
	outFile.close();																//д�����֮�󣬹ر��ļ�
}

vector<vector<string>> Units::ReadFile(const std::string fileName)					//��˫������vector�����ķ�ʽ��ȡ�ļ����������
{
	ifstream inFile(fileName, ios::in);												//�ļ�������
	string lineStr;																	//����һ��string����
	vector<vector<string>> strArray;												//��
	while (getline(inFile, lineStr))												//����ѭ��ʵ�ֽ����ݴ洢��vector��Ƕ����
	{
		stringstream ss(lineStr);													//�ַ���
		string str;																	//����һ��string����
		vector<string> lineArray;													//��
		while (getline(ss, str, ','))												//�Զ���Ϊ�������ȡ�ļ������Ϣ��������str��
			lineArray.push_back(str);												//��str��������ݴ�����һ��������
		strArray.push_back(lineArray);												//��һ�����������ݰ��д����ڶ���������
	}
	return strArray;																//���������������
}
void Units::setStudentMap(QMap<string, StudentTag> studentMap)
{
	g_studentMap = studentMap;														//��һ����̬������ֵ����̬ȫ�ֱ���
 }

QMap<string, StudentTag> Units::getStudentMap()
{
	return g_studentMap;															//��ȡ������˵ľ�̬ȫ�ֱ���
}

void Units::setStudentUserMap(QMap<string, string> studentUserMap)
{
	g_studentUserMap = studentUserMap;												//��һ����̬������ֵ����̬ȫ�ֱ���
}

QMap<string, string> Units::getStudentUserMap()
{
	return g_studentUserMap;														//��ȡ������˵ľ�̬ȫ�ֱ���
}

void Units::setTeaherUserMap(QMap<string, string> teacherUserMap)
{
	g_teaherUserMap = teacherUserMap;												//��һ����̬������ֵ����̬ȫ�ֱ���
}

QMap<string, string> Units::geTeacherUserMap()
{
	return g_teaherUserMap;															//��ȡ������˵ľ�̬ȫ�ֱ���
}

void Units::SetCurrentStudentNum(const string& num)
{
	g_currentStudentNum = num;														//��һ����̬������ֵ����̬ȫ�ֱ���
}
string Units::getCurrentStudentNum()
{
	return g_currentStudentNum;														//��ȡ������˵ľ�̬ȫ�ֱ���
}
