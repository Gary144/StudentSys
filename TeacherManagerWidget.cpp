#include "TeacherManagerWidget.h"                                                //�࣬�������ͣ�����ͷ�ļ�
#include "Units.h"                                                               //�ļ����������ݶ�д��������ͷ�ļ�
#include <QTableWidgetItem>                                                      //Qt��������������޸�ֵ
#include <QMessageBox>                                                           //Qt����ͷ�ļ�

TeacherManagerWidget::TeacherManagerWidget(QWidget *parent)
	: QWidget(parent)                                                            //ʵ�ֹ��캯�����������б����ʽ���캯������
{
	ui.setupUi(this);                                                            //����UI�ļ���ʾ����

	initSetting();                                                               //��ͨ��Ա����

	initConnect();                                                               //�����źźͲۣ����ڹ��ܵ�ʵ��
}

TeacherManagerWidget::~TeacherManagerWidget()                                    //��������������ʱ���ã��Ͽ��źźͲ�
{
	disConnect();                                                                //�Ͽ��źźͲ�
}

void TeacherManagerWidget::initSetting(void)                                     //ʵ���Ӻ���
{
	QString quessionStr = QString::fromLocal8Bit("������Ҫ��ѯ��ѧ��ѧ�ţ�");    //��ʾ�ڴ����ϵ�����
	ui.label_3->setText(quessionStr);                                            //��ʾ����༭���˵�����
	ui.tableWidget->setRowCount(30);                                             //���������Ԫ
	ui.tableWidget->setColumnCount(6);                                           //��������Ԫ
}

void TeacherManagerWidget::initConnect(void)                                     //�����źźͲ��õĺ���
{
	connect(ui.pushButton, &QPushButton::clicked, this, &TeacherManagerWidget::on_OkClicked);
	                                                                             //�����źźͲ�
	                                                                             /*
	                                                                             �����źźͲ���connect()����
																				 connect(�źŷ����ߣ��źŷ����ߵ���::�ź����ͣ��źŽ����ߣ��źŽ����ߵ�ַ::�ۺ���)
	                                                                             */
	connect(ui.pushButton_2, &QPushButton::clicked, this, &TeacherManagerWidget::close);
	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &TeacherManagerWidget::on_comboxChanged);
}

void TeacherManagerWidget::disConnect(void)                                      //���������������Ͽ�����
{
	disconnect(ui.pushButton, &QPushButton::clicked, this, &TeacherManagerWidget::on_OkClicked);
	                                                                             /*
	                                                                              �Ͽ��źźͲ���disconnect()������������connect��������
	                                                                             */
	disconnect(ui.pushButton_2, &QPushButton::clicked, this, &TeacherManagerWidget::close);
}

void TeacherManagerWidget::find()                                                //ѧ���ɼ����ҹ���ʵ�ֺ���
{
	QString textStr = ui.lineEdit->text();                                       /*��������������е��ַ���������txtStr�У�
	                                                                               QString��qt����ַ������ͣ����ܸ�ǿ����qt��c++����չ*/
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();        //Qt���һ���������ͣ�studentinfomap��Ϣ��loginwidget���Ѿ���ȡ����
		string num = textStr.toStdString();                                      //��������л�ȡѧ����Ϣ ������num��
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);
		if (iter != Units::getStudentMap().end())                                /*����������studentinfomap��Ѱ�Ҷ�Ӧnum�����ݣ�
			                                                                     ����������û�е���������Ԫ��*/
		{
			StudentTag student = iter.value();                                   //��ȡ��Ӧѧ��������Ϣ
			QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
			QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
			QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
			QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
			QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
			QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());  //�½�������QTWI�͵���������Ҹ���Щ�������дֵ
			ui.tableWidget->setItem(0, 0, numItem);
			ui.tableWidget->setItem(0, 1, nameItem);
			ui.tableWidget->setItem(0, 2, sexItem);
			ui.tableWidget->setItem(0, 3, CItem);
			ui.tableWidget->setItem(0, 4, MItem);
			ui.tableWidget->setItem(0, 5, EItem);                                 //����ֵ��ʾ�ڴ�����
		}
		else
		{
			                                                                      //ʲô������
		}
	}
}

void TeacherManagerWidget::edit()                                                 //�༭����ʵ�ֵĺ���
{
	QString textStr = ui.lineEdit->text();                                        //��ȡҪ�༭��ѧ��
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();
		string num = textStr.toStdString();                                       //��ȡ������е�ѧ��
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);       //������
		if (iter != studentInfoMap.end())
		{
			StudentTag student = iter.value();
			student._num = ui.tableWidget->item(0, 0)->text().toStdString();
			student._name = ui.tableWidget->item(0, 1)->text().toStdString();
			student._sex = ui.tableWidget->item(0, 2)->text().toStdString();
			student._C = ui.tableWidget->item(0, 3)->text().toStdString();
			student._M = ui.tableWidget->item(0, 4)->text().toStdString();         //������ʽ��ָ�룬��ӷ��ʵ������ֵ
			student._E = ui.tableWidget->item(0, 5)->text().toStdString();         //�ڱ�����޸ĵ�ֵ�����浽studentinfomap����
			studentInfoMap[student._num] = student;                                //����ֵ�滻Ϊ��ֵ
			Units::setStudentMap(studentInfoMap);                                  //ת��Units.cppʵ���ļ��Ķ�д���Ӷ�ʵ�����ݵĴ���
			QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�޸ĳɹ�"));
			                                                                       //��������ʾ��fromLocal18Bit��Ϊ�˷�ֹ����
		}
		else
		{
			QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�޴�ѧ����Ϣ���޸�ʧ��"));
		}
	}
}

void TeacherManagerWidget::add()                                                   //���ӹ���ʵ�ֺ���
{
	StudentTag student;
	student._num = ui.tableWidget->item(0, 0)->text().toStdString();
	student._name = ui.tableWidget->item(0, 1)->text().toStdString();
	student._sex = ui.tableWidget->item(0, 2)->text().toStdString();
	student._C = ui.tableWidget->item(0, 3)->text().toStdString();
	student._M = ui.tableWidget->item(0, 4)->text().toStdString();				   //ͨ��ָ���ӷ��ʲ��һ�ȡ��ǰ������
	student._E = ui.tableWidget->item(0, 5)->text().toStdString();                 //��editģ�����ƵĲ�������ģ���������ֵ������������

	QMap<string, string> studentUserMap = Units::getStudentUserMap();              //��ȡ�Ѿ������ھ�̬�������ѧ���û���Ϣ
	QMap<string, string>::iterator iter1 = studentUserMap.find(student._num);      //����һ����������Ŀ����Ϊ���ҵ���������ѧ��ѧ����ͬ��ѧ��
	if (iter1 == studentUserMap.end())                                             //��������������û�з�����ͬѧ��
	{
		studentUserMap[student._num] = "123456";                                   //������������ֵ�������ֵ�������ǳ�ʼ����
		Units::setTeaherUserMap(studentUserMap);                                   //ʵ�ִ��浽��̬������
	}

	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();              //��ȡ�Ѿ������ھ�̬�������ѧ���ɼ���Ϣ
	QMap<string, StudentTag>::iterator iter = studentInfoMap.find(student._num);   //��������ʵ�����ݱ�����Ѱ��������ѧ����ͬ������
	if (iter == studentInfoMap.end())                                              //�������������������ĩβ��û�з��ֺ�����ѧ����ͬ��ѧ��
	{
		studentInfoMap[student._num] = student;                                    //�������ӵ�ѧ����Ϣ���浽��Ϣ����
		Units::setStudentMap(studentInfoMap);                                      //ʵ�ִ��浽��̬������
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ӳɹ�"));
	}
	else                                                                           //����������ڵ��������з�������ͬѧ��
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ʧ��,�Ѿ����ڴ�ѧ����Ϣ"));
	}
}

void TeacherManagerWidget::remove()                                                //ɾ����Ϣģ��ʵ�ֺ���
{
	QString textStr = ui.lineEdit->text();                                         //�������л�ȡ��Ϣ���Ҵ���
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();          //�Ӿ�̬ȫ�ֱ������ȡѧ����Ϣ
		string num = textStr.toStdString();                                        //��ȡ������е�ѧ��
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);        //��������Ѱ�ҵ�������ѧ����Ϣ��ͬ������
		if (iter != Units::getStudentMap().end())                                  //����������˵�֮ǰѰ�ҵ�����ͬѧ��
		{
			studentInfoMap.erase(iter);                                            //ִ�����ݵ�ɾ��������earse����ɾ������
			Units::setStudentMap(studentInfoMap);                                  //��ɾ����ɺ�����ݴ����ھ�̬ȫ�ֱ�������
			QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ɾ���ɹ�"));
			                                                                       //�������������û�
		}
		else
		{
			QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ɾ��ʧ��"));
		}																			//�������������û�
	}
}


void TeacherManagerWidget::display()                                                //����ǰ����ѧ����Ϣ��ʾ����
{
	ui.tableWidget->clearContents();                                                //��ս���
	ui.tableWidget->setRowCount(30);
	ui.tableWidget->setColumnCount(6);												//��յ�ǰ���棬���һ�һ���µı��
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//��ȡѧ������
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();				//�������������ݵĿ�ʼһֱ���������
	for (int i = 0;iter != studentInfoMap.end(),i< studentInfoMap.size();i++,iter++)//�����Լӣ�һ��������ͷ��β����Ԫ�أ�һ������ѭ���������
	{
		StudentTag student = iter.value();
		QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
		QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
		QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
		QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
		QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
		QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());			//�½���������Ҹ�ֵ

		ui.tableWidget->setItem(i, 0, numItem);										//ͨ��ѭ������i��ʵ�ֻ��з������
		ui.tableWidget->setItem(i, 1, nameItem);
		ui.tableWidget->setItem(i, 2, sexItem);
		ui.tableWidget->setItem(i, 3, CItem);
		ui.tableWidget->setItem(i, 4, MItem);
		ui.tableWidget->setItem(i, 5, EItem);
	}
}

void TeacherManagerWidget::average()												//��ȡƽ���ֹ���ʵ�ֺ���
{
	ui.tableWidget->clearContents();												//��յ�ǰ����
	ui.tableWidget->setRowCount(30);
	ui.tableWidget->setColumnCount(7);												//��һ�����������Ϊ����һ��ƽ������Ϣ���Լ���һ��
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//��ȡ�����ھ�̬ȫ�ֱ������ֵ
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();				//����������ͷ������β
	for (int i = 0;iter != studentInfoMap.end(), i < studentInfoMap.size();i++, iter++)
	{
		StudentTag student = iter.value();
		QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
		QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
		QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
		QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
		QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
		QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());
		double value = std::atof(student._C.c_str()) + std::atof(student._M.c_str()) + std::atof(student._E.c_str());
		value = value / 3;                                                          //��ƽ���ֲ�����atof�������ǽ�strת��Ϊint
		QTableWidgetItem* resultItem = new QTableWidgetItem(QString::number(value));//��ȡƽ����֮��ֵ�������������

		ui.tableWidget->setItem(i, 0, numItem);
		ui.tableWidget->setItem(i, 1, nameItem);
		ui.tableWidget->setItem(i, 2, sexItem);
		ui.tableWidget->setItem(i, 3, CItem);
		ui.tableWidget->setItem(i, 4, MItem);
		ui.tableWidget->setItem(i, 5, EItem);
		ui.tableWidget->setItem(i, 6, resultItem);                                  //������ڽ�������ʾ����
	}
}

void TeacherManagerWidget::save()													//���湦��ʵ�ֺ���
{
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//��ȡ��̬�������ֵ
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();               //�����������������������
	std::vector<std::string> datas;													//����������������������������Ϊdatas
	for (;iter != studentInfoMap.end();iter++)										//������
	{
		StudentTag student = iter.value();											//�����������������������
		std::string temp;															//��������temp
		temp = student._num + "," + student._name + "," + student._sex + "," + student._C + "," + student._M + "," + student._E;
																					/*�Զ���Ϊ����������е�ֵת��Ϊһ��ֵ������temp������ڶ�д*/
		datas.push_back(temp);                                                      //��temp���浽datas���棬һά�����൱��һά����
	}																				//push_back����ʵ�ֽ�ĳ��ֵ���浽������
	Units::WriteFile("StudentInfo.txt",datas);


	QMap<string, string> studentUserMap = Units::getStudentUserMap();
	QMap<string, string>::iterator iter1 = studentUserMap.begin();					//������
	std::vector<std::string> datasUsers;
	for (;iter1 != studentUserMap.end();iter++)
	{
		StudentTag student = iter.value();
		std::string temp;
		temp = student._num + "," + "123456";										//�Զ���Ϊ���
		datasUsers.push_back(temp);													//�����ݴ�����datausers����
	}
	Units::WriteFile("studentUser.txt", datasUsers);								//д���ļ�

	QMessageBox::information(nullptr, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ɹ�"));
																					//��������QMessageBox
}

void TeacherManagerWidget::on_OkClicked()											//��������ȷ�ϰ�ť��ť
{
	QString type = ui.comboBox->currentText();										//��ȡcomboBox�����������Ϣ��������type��
	if (type == QString::fromLocal8Bit("��ѯѧ����Ϣ"))								//ѡ��������ѡ����е�����
	{
		find();																		//���ú���
	}
	else if (type == QString::fromLocal8Bit("�޸�ѧ����Ϣ"))						//ѡ��������ѡ����е�����
	{
		edit();																		//���ú���
	}

	else if (type == QString::fromLocal8Bit("����ѧ����Ϣ"))						//ѡ��������ѡ����е�����
	{
		add();																		//���ú���
	}

	else if (type == QString::fromLocal8Bit("ɾ��ѧ����Ϣ"))						//ѡ��������ѡ����е�����
	{
		remove();																	//���ú���
	}

	else if (type == QString::fromLocal8Bit("��ʾ��ǰ��Ϣ"))						//ѡ��������ѡ����е�����
	{
		display();																	//���ú���
	}
	else if (type == QString::fromLocal8Bit("��ƽ����"))							//ѡ��������ѡ����е�����
	{
		average();																	//���ú���
	}
	else if (type == QString::fromLocal8Bit("����"))								//ѡ��������ѡ����е�����
	{
		save();																		//���ú���
	}
}

void TeacherManagerWidget::on_comboxChanged(const QString& str)						//��combox�������ָı��Ժ�������Ӧ�Ĳ���
{
	if (str == QString::fromLocal8Bit("��ѯѧ����Ϣ"))
	{
		QString quessionStr = QString::fromLocal8Bit("������Ҫ���ҵ�ѧ��ѧ�ţ�");
		ui.label_3->setText(quessionStr);											//������ǩ����ʾ������
	}
	else if (str == QString::fromLocal8Bit("�޸�ѧ����Ϣ"))
	{
		QString quessionStr = QString::fromLocal8Bit("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		ui.label_3->setText(quessionStr);											//������ǩ����ʾ������
		QString textStr = ui.lineEdit->text();
		{
			QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();
			string num = textStr.toStdString();
			QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);
			if (iter != Units::getStudentMap().end())
			{
				StudentTag student = iter.value();
				QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
				QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
				QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
				QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
				QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
				QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());
				ui.tableWidget->setItem(0, 0, numItem);
				ui.tableWidget->setItem(0, 1, nameItem);
				ui.tableWidget->setItem(0, 2, sexItem);
				ui.tableWidget->setItem(0, 3, CItem);
				ui.tableWidget->setItem(0, 4, MItem);
				ui.tableWidget->setItem(0, 5, EItem);
			}																		//�޸ĵ�ʱ�����һ����ѯ�Ĺ���
		}
	}

	else if (str == QString::fromLocal8Bit("����ѧ����Ϣ"))
	{
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(30);
		ui.tableWidget->setColumnCount(6);											//����������ֵ��գ����»��Ʊ��

		QTableWidgetItem* numItem = new QTableWidgetItem("");
		QTableWidgetItem* nameItem = new QTableWidgetItem("");
		QTableWidgetItem* sexItem = new QTableWidgetItem("");
		QTableWidgetItem* CItem = new QTableWidgetItem("");
		QTableWidgetItem* MItem = new QTableWidgetItem("");
		QTableWidgetItem* EItem = new QTableWidgetItem("");
		ui.tableWidget->setItem(0, 0, numItem);
		ui.tableWidget->setItem(0, 1, nameItem);
		ui.tableWidget->setItem(0, 2, sexItem);
		ui.tableWidget->setItem(0, 3, CItem);
		ui.tableWidget->setItem(0, 4, MItem);
		ui.tableWidget->setItem(0, 5, EItem);										//��Qt����Ž�ȥ���ҳ�ʼ��ֵΪ�գ����ں����������Ϣ
	}

	else if (str == QString::fromLocal8Bit("ɾ��ѧ����Ϣ"))
	{
		QString quessionStr = QString::fromLocal8Bit("������Ҫɾ����ѧ��ѧ�ţ�");
		ui.label_3->setText(quessionStr);											//�ı�һ�±�ǩ��������֣�ʹĿ�ĸ���ȷ
	}

	else if (str == QString::fromLocal8Bit("��ʾ��ǰ��Ϣ"))
	{
																					//ʲôҲ����
	}
	else if (str == QString::fromLocal8Bit("��ƽ����"))
	{
																					//ʲôҲ����
	}
	else if (str == QString::fromLocal8Bit("����"))
	{
																					//ʲôҲ����
	}
}