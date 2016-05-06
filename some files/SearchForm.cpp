#include "SearchForm.h"
#include "ui_SearchForm.h"
#include "State.h"
#include "Site.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
#include "Format.h"
#include <QLineEdit>
/*!
\file
\brief
*/

SearchForm::SearchForm(QDockWidget *parent) :ui(new Ui::SearchForm)
{
	ui->setupUi(this);
	ui->comboBox_format->addItems(Format::getFormatNames());
	ui->comboBox_site->addItems(Site::getSiteNames());
	//QObject::connect(ui->textGeo, SIGNAL(QLineEdit::textEdited()), this, SLOT(slotCreateQuery()));
	QObject::connect(ui->textGeo, SIGNAL(textChanged(QString)), this, SLOT(filterChange(QString)));
	QObject::connect(ui->comboBox_site, SIGNAL(currentTextChanged(QString)), this, SLOT(filterChange(QString)));
	QObject::connect(ui->comboBox_format, SIGNAL(currentTextChanged(QString)), this, SLOT(filterChange(QString)));
}

SearchForm::~SearchForm()
{
	delete ui;
}

void SearchForm::filterChange(QString text)
{
	emit filterChanged(text);
}



