#pragma once
#include <QDockWidget>
#include "ui_NewRecordUser.h"
/*!
\brief
\author Козырева О.
\date апрель 2016г.
*/

class NewRecordUser : public QDockWidget {
	Q_OBJECT
private:
	Ui::NewRecordUser *ui;
	QString m_url;
	QString m_site_name;
	int m_site_id;
public:
	/*!
	Конструктор
	\param QDockWidget *ptr - указатель на родительский виджет
	*/
	explicit NewRecordUser(QDockWidget *ptr = 0);
	/*!
	Деструктор
	*/
	~NewRecordUser();
private:
	/*!
	Получение данных из формы
	*/
	void textRead();
	/*!
	Выводит сообщение о создании новой записи
	*/
	void addMessage();
	/*!
	
	*/
	void addSite();
	/*!
	Проверка на заполнение ячеек
	*/
	bool emptyLine();
	private slots:
	/*!
	check
	*/
	void check();
	
	public slots:
	/*!
	Показывает виджет
	*/
	void showNDW();

};