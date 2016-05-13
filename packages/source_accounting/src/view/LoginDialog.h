#pragma once 
#include <QDialog>
#include "ui_LoginDialog.h"


/*!
	\file
	\brief Описывает диалог аутентификации пользователя
	\author Ильина А.
	\date март 2016г.
*/
class LoginDialog : public QDialog {
	Q_OBJECT
private:
	Ui::LoginDialog *ui;
	
public:
	QString m_login;
	
	/*!	Конструктор
	\param QDialog * ptr - указатель на родительский диалог	*/
	explicit LoginDialog(QDialog *ptr = 0);

	/*!	Деструктор	*/
	~LoginDialog();
	
	/*!
	Метод для получения логина
	*/
	QString getLogin();
	
signals:
	/*!
	Сигнал об успешной авторизации
	*/
	void signalLogedIn(int);			

	// Временно
	void dialog_shown();

private slots:
	/*!Проводит авторизацию: 
	ищет введеную пользователем пару Логин-Пароль в базе, 
	испускает сигнал logedIn(), если пара найдена.*/
	void slotAuthenticate();

	/*!
	Закрывает окно с диалогом авторизации
	*/
	void slotClose(int);

public slots:
	/*!	Показывает диалог	*/
	void slotShowLD();
};