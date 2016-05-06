#pragma once
#include "ui_SearchForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
	class SearchForm;
}

/*!
*  \brief  Форма для поиска
*  \author Козырева О.
*  \date   апрель 2016
*/
class  SearchForm:public QDockWidget {
	Q_OBJECT
public:
	explicit SearchForm(QDockWidget *parent = 0);
	~SearchForm();

signals:
	void filterChanged(QString);
	//void textChanged(QString);
	
private:
	Ui::SearchForm *ui;
	
public slots:
	void filterChange(QString text);
};