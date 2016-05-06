#pragma once
#include <QDockWidget>
#include "ui_NewSource.h"
/*!
\brief
\author Козырева О.
\date апрель 2016г.
*/

class NewSource : public QWidget {
	Q_OBJECT
private:
	Ui::NewSource *ui;
	QString m_url;
	QString m_site_name;
	QString m_comment;
	
public:
	/*!
	Конструктор
	\param QDockWidget *ptr - указатель на родительский виджет
	*/
	explicit NewSource(QWidget *ptr = 0);

	/*!
	Деструктор
	*/
	~NewSource();
private:
	/*!
	Получение данных из формы
	*/
	void textRead();
	/*!	
	Создает новую запись в таблицу sites
	*/
	void addNewRecord();
	/*!
	Проверка на заполнение ячеек
	*/
	bool emptyLine();
	/*!
	Выводит сообщение о создании новой записи
	*/
	void addMessage();
	private slots:
	/*!

	*/
	void slotCheck();
	public slots:
	/*!
	Показывает виджет
	*/
	void slotShowNS();

};