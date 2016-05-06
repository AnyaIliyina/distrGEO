#pragma once
#include "ui_SitesView.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
	class SitesView;
}

/*!
*  \brief Выводит содержимое таблицы Sites (временно)
*  \author Козырева О.
*  \date   март 2016
*/
class  SitesView:public QDockWidget {
	Q_OBJECT
public:
	explicit SitesView(QDockWidget *parent = 0);
	~SitesView();

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
	Ui::SitesView *ui;
	QSqlQueryModel *model;
private:
	void createTable();
	
public slots:
	/*!
	Слот для выполнения поиска по введенным данным
	*/
	void WhereQueryPart();
	
};