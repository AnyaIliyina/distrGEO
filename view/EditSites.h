#pragma once
#include <QDockWidget>
#include "ui_EditSites.h"
/*!
\brief 
\author Козырева О.
\date апрель 2016г.
*/

class EditSites : public QWidget {
	Q_OBJECT
private:
	Ui::EditSites *ui;
	QString m_place_name;
	QString m_url;
	QString m_site_name;
	QString m_format_name;
	QString m_comment;
	int m_format_id;
	int m_site_id;
	int m_session_id = -1;
public:
	/*!
	Конструктор
	\param QDockWidget *ptr - указатель на родительский виджет
	*/
	explicit EditSites(int session_id, QWidget *ptr = 0);
	
	/*!
	Деструктор
	*/
	~EditSites();
private:
	/*!
	Получение данных из формы
	*/
	void textRead();
	/*!
	Получает id сайта
	*/
	void getSiteId();
	/*!
	Получает id формата
	*/
	void getFormatId();
	/*!
	Создает новую запись в таблицу geodata_records
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
	void slotShowNDW();
signals:
	void signalAdded();
};