#include "LoginDialog.h"
#include "User.h"
#include "Scale.h"
#include "Database.h"
#include <QDebug>
#include <QSqlQuery>
#include <QTextCodec>

//#define login "Olga"
//#define password "iamolga"
//#define asRelease true

LoginDialog::LoginDialog(QDialog * ptr)
{
	ui = new Ui::LoginDialog();
	ui->setupUi(this);
	connect(ui->btn_login, SIGNAL(clicked()), SLOT(slotAuthenticate()));
	connect(this, SIGNAL(signalLogedIn(int)), this, SLOT(slotClose(int)));

	//// пропускать авторизацию в не дипломном варианте
	//connect(this, SIGNAL(dialog_shown()), this, SLOT(slotAuthenticate()));
}

LoginDialog::~LoginDialog()
{
	delete ui;
}

void LoginDialog::slotAuthenticate()
{
	QString login, password;
	login = ui->line_Login->text();
	password = ui->line_Pass->text();
	
	if (User::userIsValid(login, password))
	{	
		int user_id = User::user_id(login);
		emit signalLogedIn(user_id);	// сигнал об успешной авторизации
	}
	else
		{ 
		ui->lblResult->setText("Пароль неверный");
		}
}

void LoginDialog::slotClose(int)
{
	this->close();
}

void LoginDialog::slotShowLD()
{
	this->show();
	/*if(asRelease)
		emit dialog_shown();*/
}

const QString& LoginDialog::getLogin() 
{
	return m_login;
}




