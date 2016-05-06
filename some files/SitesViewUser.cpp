#include "SitesViewUser.h"
#include "ui_SitesViewUser.h"
#include "State.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
#include "NewDockWidget.h"
#include "NewRecordUser.h"
/*!
\file
\brief
*/

SitesViewUser::SitesViewUser(QDockWidget *parent) :QDockWidget(parent), ui(new Ui::SitesViewUser)
{
	ui->setupUi(this);
	QObject::connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(WhereQueryPart()));
	NewRecordUser *ndw = new NewRecordUser();
	QObject::connect(ui->btnNew, SIGNAL(clicked()), ndw, SLOT(showNDW()));
}

SitesViewUser::~SitesViewUser()
{
	delete ui;
}

QString SitesViewUser::ParseWhereArgs(QList<QString>& args)
{
	if (args.length() == 0)
	{
		return QString();
	}
	QString qry = " WHERE ";
	for (int i = 0;i < args.length();i++)
	{
		qry += args[i];
		if (i != (args.length() - 1))
		{
			qry += " AND ";
		}
	}
	return qry;
}

void SitesViewUser::WhereQueryPart()
{
	QList<QString> whereArgs;
	if (!ui->textGeo->text().isEmpty())
	{
		whereArgs.push_back(QString("(site_id IN (SELECT site_id FROM geodata_records WHERE place_name='%1'))").arg(ui->textGeo->text()));
	}
	if (!ui->textURL->text().isEmpty())
	{
		whereArgs.push_back(QString("(site_name='%1')").arg(ui->textURL->text()));
	}
	if (!ui->comboBox->currentText().isEmpty())
	{
		whereArgs.push_back(QString("(site_id IN (SELECT site_id FROM geodata_records WHERE format_id in (SELECT format_id FROM formats WHERE format_name='%1')))").arg(ui->comboBox->currentText()));
	}
	QString whereQryPart = ParseWhereArgs(whereArgs);
	setupModel(whereQryPart);
}

void SitesViewUser::setupModel(QString& whereQryPart)
{
	QSqlDatabase db = Database::database();
	model = new QSqlQueryModel(this);
	model->setQuery(QString("SELECT site_name, url FROM sites %1").arg(whereQryPart), db);
	createTable();

}



void SitesViewUser::createTable()
{
	ui->tableView->setModel(model);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

}

