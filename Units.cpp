#include "Units.h"																	//头文件的引用，函数声明，数据类型
#include <sstream>																	//字符流头文件

void Units::WriteFile(const std::string fileName, std::vector<std::string> data)	//写入文件函数
{
	ofstream outFile;																//打开文件
	outFile.open(fileName, ios::out);												//以写入文件的模式打开文件名为“FileName”的文件
	for (int i = 0; i < data.size();i++)											//循环方式写入文件
	{
		outFile << data.at(i) << endl;												//写入数据，每写完一行就换行
	}
	outFile.close();																//写入完毕之后，关闭文件
}

vector<vector<string>> Units::ReadFile(const std::string fileName)					//以双重向量vector容器的方式读取文件里面的内容
{
	ifstream inFile(fileName, ios::in);												//文件输入流
	string lineStr;																	//声明一个string变量
	vector<vector<string>> strArray;												//列
	while (getline(inFile, lineStr))												//二重循环实现将数据存储到vector的嵌套里
	{
		stringstream ss(lineStr);													//字符流
		string str;																	//声明一个string变量
		vector<string> lineArray;													//行
		while (getline(ss, str, ','))												//以逗号为间隔，获取文件里的信息，储存在str里
			lineArray.push_back(str);												//将str里面的数据储存在一重向量里
		strArray.push_back(lineArray);												//将一重向量的数据按行储存在二重向量里
	}
	return strArray;																//返回这个二重向量
}
void Units::setStudentMap(QMap<string, StudentTag> studentMap)
{
	g_studentMap = studentMap;														//将一个动态变量赋值给静态全局变量
 }

QMap<string, StudentTag> Units::getStudentMap()
{
	return g_studentMap;															//获取储存好了的静态全局变量
}

void Units::setStudentUserMap(QMap<string, string> studentUserMap)
{
	g_studentUserMap = studentUserMap;												//将一个动态变量赋值给静态全局变量
}

QMap<string, string> Units::getStudentUserMap()
{
	return g_studentUserMap;														//获取储存好了的静态全局变量
}

void Units::setTeaherUserMap(QMap<string, string> teacherUserMap)
{
	g_teaherUserMap = teacherUserMap;												//将一个动态变量赋值给静态全局变量
}

QMap<string, string> Units::geTeacherUserMap()
{
	return g_teaherUserMap;															//获取储存好了的静态全局变量
}

void Units::SetCurrentStudentNum(const string& num)
{
	g_currentStudentNum = num;														//将一个动态变量赋值给静态全局变量
}
string Units::getCurrentStudentNum()
{
	return g_currentStudentNum;														//获取储存好了的静态全局变量
}
