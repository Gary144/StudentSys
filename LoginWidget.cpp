#include "LoginWidget.h"						//��¼��������Ҫ��ʹ�õĺ����������������������ͷ�ļ������ݽṹ��
#include "ui_LoginWidget.h"						//ʹ��UI�ļ�����Ҫ�����õ�ͷ�ļ�
#include "StudentInforMationWidget.h"			//ѧ���û���½�Ժ���Ϣ��ʾ��������Ҫ��ʹ�õĺ����������������������ͷ�ļ������ݽṹ��
#include "TeacherManagerWidget.h"				//�����û���¼�Ժ�����������Ҫ��ʹ�õĺ����������������������ͷ�ļ������ݽṹ������Ҫ�����õ�ͷ�ļ�
#include "Units.h"								//���ļ������йص����ݣ���������Ҫ�����õ�ͷ�ļ�

#include <QMessageBox>												//Qt����������Ҫ�����õ�ͷ�ļ�
#include <QPalette>													//Qt��ɫ��������Ҫ�����õ�ͷ�ļ�
#include <QPixmap>													//Qt��ͼ�豸��ͼ����ʾ����Ҫ�����õ�ͷ�ļ�
#include <QString>													//Qt�ַ�������Ҫ�����õ�ͷ�ļ�
#include <QBrush>													//Qt��ˢ����Ҫ�����õ�ͷ�ļ�

#if defined(_MSC_VER)&&(_MSC_VER > 1700)
#pragma execution_character_set("utf-8")
#endif																//��ֹ�������룬ʹ��utf-8����

class LoginWidgetPrivate											//�������ͷ�ļ����Ѿ��������ˣ��������չ��
{
	Q_DECLARE_PUBLIC(LoginWidget)									//Qt�����һ���꣬������ȡLoginWidget��qָ��

public:																//������
	LoginWidgetPrivate();											//���캯��
	~LoginWidgetPrivate() { delete ui; }							//��������������������������ɾ��UI����

private:															//˽����
	void initSetting(void);											//��������
private:
	LoginWidget* q_ptr;//qָ��
	Ui_LoginWidget* ui;//uiָ��
	StudentInforMationWidget* m_pStudentInforMationWidget;//����ָ��
	TeacherManagerWidget* m_pTeacherManagerWidget;		  //����ָ��
};


LoginWidgetPrivate::LoginWidgetPrivate()							//���캯����ʵ��
	:ui(new Ui_LoginWidget)
	,m_pStudentInforMationWidget(nullptr)
	, m_pTeacherManagerWidget(nullptr)								//���б�ķ�ʽ���캯���ﴫ�Σ����ҳ�ʼ������ָ��Ϊnull
{
	Q_Q(LoginWidget);												//��ȡLoginWidget��qָ��
	initSetting();													//���ú���initSetting(); ���庯�����·�
}

void LoginWidgetPrivate::initSetting(void)							//ʵ�������ĺ���
{
	QMap<string, string> teacherUserMap;							//Qmap��Qt���һ��������������������һ���µ�Qmap����
	vector<vector<string>> teacherDatas = Units::ReadFile("teacherUser.txt");
																	//����ReadFile��������ȡ�ı��ļ�������ݣ������䱣���ڶ�άvector����
	for (int i = 0; i < teacherDatas.size();i++)					//�������м��ж�ȡ����
																	//��������Vector����ת��ΪQmap���ͣ�������
	{
		vector<string> line = teacherDatas.at(i);
		if (line.size() == 2)										//������2��
		{
			teacherUserMap[(line.at(0).c_str())] = (line.at(1).c_str());
		}
	}
	Units::setTeaherUserMap(teacherUserMap);						//����Units����ĺ�����������teacherUserMap��ת��Ϊ��̬ȫ�ֱ���
	
	QMap<string, string>studentUserMap;								//Qmap��Qt���һ��������������������һ���µ�Qmap����
	vector<vector<string>> studentDatas = Units::ReadFile("studentUser.txt");
																	//����ReadFile��������ȡ�ı��ļ�������ݣ������䱣���ڶ�άvector����
	for (int i = 0; i < studentDatas.size();i++)					//��������Vector����ת��ΪQmap���ͣ�������
	{
		vector<string> line = studentDatas.at(i);
		if (line.size() == 2)
		{
			studentUserMap[(line.at(0).c_str())] = (line.at(1).c_str());
		}
	}
	Units::setStudentUserMap(studentUserMap);						//����Units����ĺ�����������studentUserMap
	
	QMap<string, StudentTag> studentinfoMap;						//Qmap��Qt���һ��������������������һ���µ�Qmap����
	vector<vector<string>> studentInfoDatas = Units::ReadFile("StudentInfo.txt");
																	//����ReadFile��������ȡ�ı��ļ�������ݣ������䱣���ڶ�άvector����
	for (int i = 0; i < studentInfoDatas.size();i++)				//��������Vector����ת��ΪQmap���ͣ�������
	{
		vector<string> line = studentInfoDatas.at(i);
		if (line.size() == 6)
		{
			StudentTag student;
			student._num = line.at(0);
			student._name = line.at(1);
			student._sex = line.at(2);
			student._C = line.at(3);
			student._M = line.at(4);
			student._E = line.at(5);
			studentinfoMap[student._num] = student;					//studentinfomap��Ψһ��ʶ����ѧ��student._num
		}
	}
	Units::setStudentMap(studentinfoMap);							//����Units����ĺ�����������studentinfoMap
}

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)												//���б����ʽ�����캯������
	,d_ptr(new LoginWidgetPrivate)                                  //��Ҫ��LOginWidget����ʹ��LWP��dָ�룬����Ҫ�ڹ��캯�����ε�ʱ��new����
{
	initSetting();

	initConnect();
}

LoginWidget::~LoginWidget()											//LoginWidget������������ΪDisconnect()
{
	disConnect();
}

void LoginWidget::initSetting()
{
	Q_D(LoginWidget);												//��ȡLoginWidget��Dָ�룬���ڴ�������ʸ���
	d->q_ptr = this;												//ʹ��private�����public��
	d->ui->setupUi(this);											//�ȹ���һ��QWidget���棬�ټ���xml���������Ǵ�����ui����
	QMetaObject::connectSlotsByName(this);							//QObject��ĳЩ�źŰ�����objectName���ӵ����ϡ�
}

void LoginWidget::initConnect()
{
	Q_D(LoginWidget);												//��ȡLoginWidget��Dָ�룬���ڷ���
	connect(d->ui->pushButton, &QPushButton::clicked,this, &LoginWidget::on_loginBtnClicked);
	connect(d->ui->pushButton_2, &QPushButton::clicked, this, &LoginWidget::close);
}																	//�����źźͲ�
void LoginWidget::disConnect()
{
	Q_D(LoginWidget);												//��ȡLoginWidget��Dָ�룬���ڷ���
	disconnect(d->ui->pushButton, &QPushButton::clicked, this, &LoginWidget::on_loginBtnClicked);
	disconnect(d->ui->pushButton_2, &QPushButton::clicked, this, &LoginWidget::close);
}																	//�Ͽ��źźͲ۵�����

void LoginWidget::on_loginBtnClicked()								//�ۺ���
{
	Q_D(LoginWidget);												//��ȡLoginWidget��Dָ�룬���ڷ���
	QString typeStr = d->ui->comboBox->currentText();				//����һ��Qstring���ͱ��������ҽ�����������ֵ������
	if (typeStr == "ѧ��")											//���ѡ�����ѧ��
	{
		string userName = d->ui->lineEdit->text().toStdString().c_str();
		string password = d->ui->lineEdit_2->text().toStdString().c_str();
		/*ͨ�����ָ��ķ��ʽ�����������ֵ��ֵ��������������string����*/
		QMap<string, string> studentUserMap = Units::getStudentUserMap();	//����ȡ��ѧ���û�ԭ���ݷŽ�Qmap<string,string>
		QMap<string, string>::iterator iter = studentUserMap.find(userName);//���������ڴ�����˵���������Ѱ�Һ�������ƥ���ֵ
		if (iter != studentUserMap.end()/*��������û�е�studentUserMap��ĩβ*/)
		{
			if (iter.value() == password)									//�����������ֵ��password�����ֵ���
			{
				Units::SetCurrentStudentNum(userName);						//����units��ĺ���
				d->m_pStudentInforMationWidget = new StudentInforMationWidget();
				d->m_pStudentInforMationWidget->show();						//��ʾѧ����Ϣ����
			}
			else
			{
				QMessageBox::warning(nullptr, tr("��ʾ"), tr("��¼�������"));
			}
			
		}
		else
		{
			QMessageBox::warning(nullptr, tr("��ʾ"), tr("�û�������"));
		}
	}
	else if (typeStr == "��Ա")												//���ѡ����ǽ�Ա
	{
		string userName = d->ui->lineEdit->text().toStdString().c_str();
		string password = d->ui->lineEdit_2->text().toStdString().c_str();
		/*ͨ�����ָ��ķ��ʽ�����������ֵ��ֵ��������������string����*/
		QMap<string, string> teacherUserMap = Units::geTeacherUserMap();
		QMap<string, string>::iterator iter = teacherUserMap.find(userName);//���������ڴ�����˵���������Ѱ�Һ�������ƥ���ֵ
		if (iter != teacherUserMap.end()/*��������û�е�teacherUserMap��ĩβ*/)
		{
			if (iter.value() == password)
			{
				d->m_pTeacherManagerWidget = new TeacherManagerWidget();
				d->m_pTeacherManagerWidget->show();							//��ʾ��ʦ�������
			}
			else
			{
				QMessageBox::warning(nullptr, tr("��ʾ"), tr("��¼�������"));
			}
		}
		else
		{
			QMessageBox::warning(nullptr, tr("��ʾ"), tr("�û�������"));
		}
	}
	this->close();															//�ر����е�¼����
}