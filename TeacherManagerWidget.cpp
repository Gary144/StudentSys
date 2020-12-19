#include "TeacherManagerWidget.h"                                                //类，数据类型，公用头文件
#include "Units.h"                                                               //文件操作，数据读写辅助函数头文件
#include <QTableWidgetItem>                                                      //Qt窗口组件，可以修改值
#include <QMessageBox>                                                           //Qt弹窗头文件

TeacherManagerWidget::TeacherManagerWidget(QWidget *parent)
	: QWidget(parent)                                                            //实现构造函数，并且以列表的形式向构造函数传参
{
	ui.setupUi(this);                                                            //根据UI文件显示界面

	initSetting();                                                               //普通成员函数

	initConnect();                                                               //链接信号和槽，用于功能的实现
}

TeacherManagerWidget::~TeacherManagerWidget()                                    //析构函数，消亡时调用，断开信号和槽
{
	disConnect();                                                                //断开信号和槽
}

void TeacherManagerWidget::initSetting(void)                                     //实现子函数
{
	QString quessionStr = QString::fromLocal8Bit("请输入要查询的学生学号：");    //显示在窗口上的文字
	ui.label_3->setText(quessionStr);                                            //显示上面编辑好了的文字
	ui.tableWidget->setRowCount(30);                                             //画表格纵向单元
	ui.tableWidget->setColumnCount(6);                                           //画表格横向单元
}

void TeacherManagerWidget::initConnect(void)                                     //链接信号和槽用的函数
{
	connect(ui.pushButton, &QPushButton::clicked, this, &TeacherManagerWidget::on_OkClicked);
	                                                                             //链接信号和槽
	                                                                             /*
	                                                                             链接信号和槽用connect()函数
																				 connect(信号发出者，信号发出者的类::信号类型，信号接收者，信号接收者地址::槽函数)
	                                                                             */
	connect(ui.pushButton_2, &QPushButton::clicked, this, &TeacherManagerWidget::close);
	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &TeacherManagerWidget::on_comboxChanged);
}

void TeacherManagerWidget::disConnect(void)                                      //用于析构函数，断开连接
{
	disconnect(ui.pushButton, &QPushButton::clicked, this, &TeacherManagerWidget::on_OkClicked);
	                                                                             /*
	                                                                              断开信号和槽用disconnect()函数，参数与connect函数类似
	                                                                             */
	disconnect(ui.pushButton_2, &QPushButton::clicked, this, &TeacherManagerWidget::close);
}

void TeacherManagerWidget::find()                                                //学生成绩查找功能实现函数
{
	QString textStr = ui.lineEdit->text();                                       /*将输入在输入框中的字符串储存在txtStr中，
	                                                                               QString是qt里的字符串类型，功能更强大，是qt对c++的拓展*/
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();        //Qt里的一种数据类型，studentinfomap信息在loginwidget中已经获取过了
		string num = textStr.toStdString();                                      //从输入框中获取学号信息 储存在num中
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);
		if (iter != Units::getStudentMap().end())                                /*迭代器，在studentinfomap中寻找对应num的数据，
			                                                                     当迭代器还没有迭代完所有元素*/
		{
			StudentTag student = iter.value();                                   //获取对应学号里面信息
			QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
			QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
			QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
			QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
			QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
			QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());  //新建了六个QTWI型的组件，并且给这些组件里面写值
			ui.tableWidget->setItem(0, 0, numItem);
			ui.tableWidget->setItem(0, 1, nameItem);
			ui.tableWidget->setItem(0, 2, sexItem);
			ui.tableWidget->setItem(0, 3, CItem);
			ui.tableWidget->setItem(0, 4, MItem);
			ui.tableWidget->setItem(0, 5, EItem);                                 //将数值显示在窗口里
		}
		else
		{
			                                                                      //什么都不做
		}
	}
}

void TeacherManagerWidget::edit()                                                 //编辑功能实现的函数
{
	QString textStr = ui.lineEdit->text();                                        //获取要编辑的学号
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();
		string num = textStr.toStdString();                                       //获取输入框中的学号
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);       //迭代器
		if (iter != studentInfoMap.end())
		{
			StudentTag student = iter.value();
			student._num = ui.tableWidget->item(0, 0)->text().toStdString();
			student._name = ui.tableWidget->item(0, 1)->text().toStdString();
			student._sex = ui.tableWidget->item(0, 2)->text().toStdString();
			student._C = ui.tableWidget->item(0, 3)->text().toStdString();
			student._M = ui.tableWidget->item(0, 4)->text().toStdString();         //访问形式是指针，间接访问到输入的值
			student._E = ui.tableWidget->item(0, 5)->text().toStdString();         //在表格中修改的值，储存到studentinfomap里面
			studentInfoMap[student._num] = student;                                //将旧值替换为新值
			Units::setStudentMap(studentInfoMap);                                  //转见Units.cpp实现文件的读写，从而实现数据的储存
			QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"));
			                                                                       //弹出的提示框fromLocal18Bit是为了防止乱码
		}
		else
		{
			QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("无此学生信息，修改失败"));
		}
	}
}

void TeacherManagerWidget::add()                                                   //增加功能实现函数
{
	StudentTag student;
	student._num = ui.tableWidget->item(0, 0)->text().toStdString();
	student._name = ui.tableWidget->item(0, 1)->text().toStdString();
	student._sex = ui.tableWidget->item(0, 2)->text().toStdString();
	student._C = ui.tableWidget->item(0, 3)->text().toStdString();
	student._M = ui.tableWidget->item(0, 4)->text().toStdString();				   //通过指针间接访问并且获取当前的文字
	student._E = ui.tableWidget->item(0, 5)->text().toStdString();                 //和edit模块类似的操作，将模块里面的新值储存在数据里

	QMap<string, string> studentUserMap = Units::getStudentUserMap();              //获取已经储存在静态变量里的学生用户信息
	QMap<string, string>::iterator iter1 = studentUserMap.find(student._num);      //设置一个迭代器，目的是为了找到与新输入学生学号相同的学号
	if (iter1 == studentUserMap.end())                                             //如果迭代到了最后，没有发现相同学号
	{
		studentUserMap[student._num] = "123456";                                   //往最后面加上数值，这个数值的作用是初始密码
		Units::setTeaherUserMap(studentUserMap);                                   //实现储存到静态变量中
	}

	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();              //获取已经储存在静态变量里的学生成绩信息
	QMap<string, StudentTag>::iterator iter = studentInfoMap.find(student._num);   //迭代器，实现数据遍历，寻找与输入学号相同的数据
	if (iter == studentInfoMap.end())                                              //迭代器，如果迭代到了末尾还没有发现和输入学号相同的学号
	{
		studentInfoMap[student._num] = student;                                    //将新增加的学生信息储存到信息体中
		Units::setStudentMap(studentInfoMap);                                      //实现储存到静态变量中
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));
	}
	else                                                                           //如果迭代器在迭代过程中发现了相同学号
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加失败,已经存在此学生信息"));
	}
}

void TeacherManagerWidget::remove()                                                //删除信息模块实现函数
{
	QString textStr = ui.lineEdit->text();                                         //从输入行获取信息并且储存
	{
		QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();          //从静态全局变量里获取学生信息
		string num = textStr.toStdString();                                        //获取输入框中的学号
		QMap<string, StudentTag>::iterator iter = studentInfoMap.find(num);        //迭代器，寻找到与输入学生信息相同的数据
		if (iter != Units::getStudentMap().end())                                  //如果迭代到了底之前寻找到了相同学号
		{
			studentInfoMap.erase(iter);                                            //执行数据的删除操作，earse用来删除数据
			Units::setStudentMap(studentInfoMap);                                  //将删除完成后的数据储存在静态全局变量里面
			QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除成功"));
			                                                                       //弹出弹窗提醒用户
		}
		else
		{
			QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除失败"));
		}																			//弹出弹窗提醒用户
	}
}


void TeacherManagerWidget::display()                                                //将当前所有学生信息显示出来
{
	ui.tableWidget->clearContents();                                                //清空界面
	ui.tableWidget->setRowCount(30);
	ui.tableWidget->setColumnCount(6);												//清空当前界面，并且画一个新的表格
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//获取学生数据
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();				//迭代器，从数据的开始一直迭代到最后
	for (int i = 0;iter != studentInfoMap.end(),i< studentInfoMap.size();i++,iter++)//两个自加，一个用来从头到尾遍历元素，一个用来循环放置组件
	{
		StudentTag student = iter.value();
		QTableWidgetItem* numItem = new QTableWidgetItem(student._num.c_str());
		QTableWidgetItem* nameItem = new QTableWidgetItem(student._name.c_str());
		QTableWidgetItem* sexItem = new QTableWidgetItem(student._sex.c_str());
		QTableWidgetItem* CItem = new QTableWidgetItem(student._C.c_str());
		QTableWidgetItem* MItem = new QTableWidgetItem(student._M.c_str());
		QTableWidgetItem* EItem = new QTableWidgetItem(student._E.c_str());			//新建组件，并且赋值

		ui.tableWidget->setItem(i, 0, numItem);										//通过循环变量i来实现换行放置组件
		ui.tableWidget->setItem(i, 1, nameItem);
		ui.tableWidget->setItem(i, 2, sexItem);
		ui.tableWidget->setItem(i, 3, CItem);
		ui.tableWidget->setItem(i, 4, MItem);
		ui.tableWidget->setItem(i, 5, EItem);
	}
}

void TeacherManagerWidget::average()												//求取平均分功能实现函数
{
	ui.tableWidget->clearContents();												//清空当前界面
	ui.tableWidget->setRowCount(30);
	ui.tableWidget->setColumnCount(7);												//画一个表格，这里因为加了一个平均分信息所以加了一列
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//获取储存在静态全局变量里的值
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();				//迭代器，从头迭代到尾
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
		value = value / 3;                                                          //求平均分操作，atof的作用是将str转化为int
		QTableWidgetItem* resultItem = new QTableWidgetItem(QString::number(value));//求取平均分之后将值保存在新组件中

		ui.tableWidget->setItem(i, 0, numItem);
		ui.tableWidget->setItem(i, 1, nameItem);
		ui.tableWidget->setItem(i, 2, sexItem);
		ui.tableWidget->setItem(i, 3, CItem);
		ui.tableWidget->setItem(i, 4, MItem);
		ui.tableWidget->setItem(i, 5, EItem);
		ui.tableWidget->setItem(i, 6, resultItem);                                  //将组件在界面中显示出来
	}
}

void TeacherManagerWidget::save()													//保存功能实现函数
{
	QMap<string, StudentTag> studentInfoMap = Units::getStudentMap();				//获取静态变量里的值
	QMap<string, StudentTag>::iterator iter = studentInfoMap.begin();               //迭代器，遍历容器里的数据
	std::vector<std::string> datas;													//声明变量，向量容器变量，名字为datas
	for (;iter != studentInfoMap.end();iter++)										//迭代器
	{
		StudentTag student = iter.value();											//迭代器，遍历容器里的数据
		std::string temp;															//声明变量temp
		temp = student._num + "," + student._name + "," + student._sex + "," + student._C + "," + student._M + "," + student._E;
																					/*以逗号为间隔，将所有的值转化为一个值保存在temp里面便于读写*/
		datas.push_back(temp);                                                      //将temp储存到datas里面，一维向量相当于一维数组
	}																				//push_back函数实现将某个值储存到容器里
	Units::WriteFile("StudentInfo.txt",datas);


	QMap<string, string> studentUserMap = Units::getStudentUserMap();
	QMap<string, string>::iterator iter1 = studentUserMap.begin();					//迭代器
	std::vector<std::string> datasUsers;
	for (;iter1 != studentUserMap.end();iter++)
	{
		StudentTag student = iter.value();
		std::string temp;
		temp = student._num + "," + "123456";										//以逗号为间隔
		datasUsers.push_back(temp);													//将数据储存在datausers里面
	}
	Units::WriteFile("studentUser.txt", datasUsers);								//写入文件

	QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存成功"));
																					//弹出窗口QMessageBox
}

void TeacherManagerWidget::on_OkClicked()											//如果点击了确认按钮按钮
{
	QString type = ui.comboBox->currentText();										//获取comboBox里面的文字信息，储存在type中
	if (type == QString::fromLocal8Bit("查询学生信息"))								//选择条件是选择框中的文字
	{
		find();																		//调用函数
	}
	else if (type == QString::fromLocal8Bit("修改学生信息"))						//选择条件是选择框中的文字
	{
		edit();																		//调用函数
	}

	else if (type == QString::fromLocal8Bit("增加学生信息"))						//选择条件是选择框中的文字
	{
		add();																		//调用函数
	}

	else if (type == QString::fromLocal8Bit("删除学生信息"))						//选择条件是选择框中的文字
	{
		remove();																	//调用函数
	}

	else if (type == QString::fromLocal8Bit("显示当前信息"))						//选择条件是选择框中的文字
	{
		display();																	//调用函数
	}
	else if (type == QString::fromLocal8Bit("求平均分"))							//选择条件是选择框中的文字
	{
		average();																	//调用函数
	}
	else if (type == QString::fromLocal8Bit("保存"))								//选择条件是选择框中的文字
	{
		save();																		//调用函数
	}
}

void TeacherManagerWidget::on_comboxChanged(const QString& str)						//在combox里面文字改变以后做出对应的操作
{
	if (str == QString::fromLocal8Bit("查询学生信息"))
	{
		QString quessionStr = QString::fromLocal8Bit("请输入要查找的学生学号：");
		ui.label_3->setText(quessionStr);											//更换标签里显示的文字
	}
	else if (str == QString::fromLocal8Bit("修改学生信息"))
	{
		QString quessionStr = QString::fromLocal8Bit("请输入要修改的学生学号：");
		ui.label_3->setText(quessionStr);											//更换标签里显示的文字
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
			}																		//修改的时候会有一个查询的过程
		}
	}

	else if (str == QString::fromLocal8Bit("增加学生信息"))
	{
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(30);
		ui.tableWidget->setColumnCount(6);											//将表格里面的值清空，重新绘制表格

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
		ui.tableWidget->setItem(0, 5, EItem);										//将Qt组件放进去并且初始化值为空，便于后续的添加信息
	}

	else if (str == QString::fromLocal8Bit("删除学生信息"))
	{
		QString quessionStr = QString::fromLocal8Bit("请输入要删除的学生学号：");
		ui.label_3->setText(quessionStr);											//改变一下标签上面的文字，使目的更明确
	}

	else if (str == QString::fromLocal8Bit("显示当前信息"))
	{
																					//什么也不做
	}
	else if (str == QString::fromLocal8Bit("求平均分"))
	{
																					//什么也不做
	}
	else if (str == QString::fromLocal8Bit("保存"))
	{
																					//什么也不做
	}
}