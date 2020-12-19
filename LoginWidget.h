/*���ͷ�ļ�������������һЩ��¼������Ҫ�õ�����ͺ���*/
#pragma once//����һ��

#include <QWidget>//Qt��������Ҫ�õ���ͷ�ļ�
#include "Def.h"//����һЩ��Ҫ�õ���ͨ��ͷ�ļ��������ݽṹ��

class LoginWidgetPrivate;//������һ���࣬��û�о�������

class LoginWidget : public QWidget//������LoginWidget������࣬���м̳���QWidget
{
	Q_OBJECT//Qt�����һ���꣬Qt�ĸ��ֲ���������������

public://�����ࣺ���ж����Է���
	explicit LoginWidget(QWidget *parent = Q_NULLPTR);/*����Ϊexplicit�Ĺ��캯����������ʽת����ʹ��
													    �����캯��LoginWidget()�ﴫ�Σ�����ΪQWidget��ָ�벢��ʼ��ΪNULL
													  */
	~LoginWidget();//�������������������͹��캯����һ�����Ǽ���~�ؼ���

public:

public Q_SIGNAL ://Q_SIGNAL��Qtһ���ź���

public Q_SLOTS ://Q_SLOTS��Qt�Ĳۺ�����

    void on_loginBtnClicked();//�����һ���ۺ������ۺ����Ĳ���Ҫ���ź�����Ĳ���һ��
private:

	void initSetting(void);//������������Ա����������Ϊ˽��
	void initConnect(void);
	void disConnect(void);
private:
	Q_DECLARE_PRIVATE(LoginWidget);//Qt�����һ���� Q_DECLARE_PRIVATE �����Ϊ�˻�ȡLoginWidget��dָ��
	QScopedPointer<LoginWidgetPrivate> d_ptr;//ScopedPointer��Qt���������ָ���ȡ LoginWidgetPrivate ��dָ��
};
