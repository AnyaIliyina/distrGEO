#include "ViewFiles.h"
#include "Database.h"
#include "Scale.h"
#include "State.h"
#include "GeodataType.h"
#include "Geodata.h"

#include "Item_model.h"
#include "Combo_delegate.h"
#include "Site.h"
#include "Language.h"
#include "Session.h"
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>


ViewFiles::ViewFiles(QWidget * parent): ui(new Ui::ViewFiles) // ??
{
	ui->setupUi(this);
	setupModel();
	setDisabled();
	QObject::connect(ui->action_New, SIGNAL(triggered()), this, SLOT(slotAdd()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDelete()));
	QObject::connect(ui->tableView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)) ,this, SLOT(slotEnableButtons(const QItemSelection &, const QItemSelection &)) );
	//QObject::connect(this, SIGNAL(signalChangeEditMode()), this, SLOT(slotEnableButtons()));
	QObject::connect(this, SIGNAL(dataChanged()), this, SLOT(slotRefresh()));
		
}

ViewFiles::~ViewFiles()
{
	delete ui;
	delete m_model;
}

void ViewFiles::setupModel()
{
	delete m_model;
	QSqlDatabase db = Database::database();
	m_model = new ItemModel();
	createTable();
}


void ViewFiles::setDisabled()
{
	
	ui->action_Delete->setEnabled(false);
	ui->action_New->setEnabled(true);
	ui->action_OpenFile->setEnabled(false);
	
}

void ViewFiles::slotRefresh()
{
	setupModel();
}


void ViewFiles::slotEnableButtons(const QItemSelection &, const QItemSelection &)
{

		ui->action_New->setEnabled(true);

		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_OpenFile->setEnabled(false);

		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_OpenFile->setEnabled(true);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_OpenFile->setEnabled(false);
		}
}



void ViewFiles::createTable()
{
	m_model->loadData(4);
	ui->tableView->setModel(m_model);

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->resizeColumnsToContents();
	ui->tableView->resizeRowsToContents();

	ui->tableView->setColumnWidth(1, 150);
	ui->tableView->setColumnWidth(2, 100);
	ui->tableView->setColumnWidth(3, 100);
}

void ViewFiles::slotAdd()
{
	m_editMode = true;
	emit signalChangeEditMode();
	QModelIndex index;
	m_model->insertRows(0, 1, index);
	ui->tableView->resizeRowsToContents();
	auto rowCount = m_model->rowCount(index);
	auto child = m_model->index(rowCount - 1, 0, index); 
	ui->tableView->selectionModel()->setCurrentIndex(child, QItemSelectionModel::SelectCurrent);
	ui->tableView->edit(child);
	
}

void ViewFiles::slotDelete()
{
	
	int  deleteMsgBox = QMessageBox::question(this, "",
		"Удалить выбранную запись?",
		QMessageBox::Yes, QMessageBox::No);
	if (deleteMsgBox == QMessageBox::Yes)
	{
		auto indexes = ui->tableView->selectionModel()->selectedRows();
		for (int i = indexes.count()-1; i>=0; i--)
		{
			auto index = indexes.at(i);
			m_model->removeRows(0, 1, index);
		}
	}
}

void ViewFiles::slotOpenUrl()
{
	auto index = ui->tableView->selectionModel()->currentIndex();
	int row = index.row();
	auto child = m_model->index(row, 2);
	QString url= m_model->data(child).toString();
	QUrl m_url(url);
	bool res=QDesktopServices::openUrl(m_url);
}

