#pragma once
#include "ui_SitesViewUser.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
	class SitesViewUser;
}

/*!
*  \brief Выводит содержимое таблицы Sites (временно)
*  \author Козырева О.
*  \date   март 2016
*/
class  SitesViewUser :public QDockWidget {
	Q_OBJECT
public:
	explicit SitesViewUser(QDockWidget *parent = 0);
	~SitesViewUser();

	/*!
	Метод для создания строки запроса
	\param QList<QString> args - список, содержащий строки, для составления запроса
	\return QString qry - строка запроса к базе
	*/
	QString ParseWhereArgs(QList<QString>& args);

	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	void setupModel(QString& whereQryPart);
private:
	Ui::SitesViewUser *ui;
	QSqlQueryModel *model;
private:
	void createTable();

	public slots:
	/*!
	Слот для выполнения поиска по введенным данным
	*/
	void WhereQueryPart();

};