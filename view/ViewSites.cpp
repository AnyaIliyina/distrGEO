#include "ViewSites.h"
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


ViewSites::ViewSites(QWidget * parent): ui(new Ui::ViewSites) // ??
{
	ui->setupUi(this);
	setupModel();
	setDisabled();
	QObject::connect(ui->action_New, SIGNAL(triggered()), this, SLOT(slotAdd()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDelete()));
	QObject::connect(ui->action_Edit, SIGNAL(triggered()), this, SLOT(slotEdit()));
	QObject::connect(ui->action_Yes, SIGNAL(triggered()), this, SLOT(slotSave()));
	QObject::connect(ui->action_No, SIGNAL(triggered()), this, SLOT(slotCancel()));
	QObject::connect(ui->tableView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)) ,this, SLOT(slotEnableButtons(const QItemSelection &, const QItemSelection &)) );
	QObject::connect(this, SIGNAL(signalChangeEditMode()), this, SLOT(slotEnableButtons()));
	QObject::connect(this, SIGNAL(dataChanged()), this, SLOT(slotRefresh()));
	QObject::connect(ui->action_OpenUrl, SIGNAL(triggered()), this, SLOT(slotOpenUrl()));
	//QObject::connect(ui->tableView->model, SIGNAL(signalId(int)), this, SLOT(slotIdRecord()));
}

ViewSites::~ViewSites()
{
	delete ui;
	delete m_model;
}

void ViewSites::setupModel()
{
	delete m_model;
	QSqlDatabase db = Database::database();
	m_model = new ItemModel();
	createTable();
}


void ViewSites::setDisabled()
{
	ui->action_Edit->setEnabled(false);
	ui->action_Delete->setEnabled(false);
	ui->action_New->setEnabled(true);
	ui->action_Yes->setEnabled(false);
	ui->action_No->setEnabled(false);
	ui->action_OpenUrl->setEnabled(false);
	//emit valueSelected(-1);
}

void ViewSites::slotRefresh()
{
	setupModel();
}

void ViewSites::slotEnableButtons()
{
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_OpenUrl->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
		/*int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
		qDebug() << value;
		emit valueSelected(value);*/
	}
	else
	{
		ui->action_New->setEnabled(true);
		ui->action_Yes->setEnabled(false);
		ui->action_No->setEnabled(false);
		
		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(false);
			ui->action_OpenUrl->setEnabled(false);
			emit valueSelected(-1);
			
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
			ui->action_OpenUrl->setEnabled(true);
			int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
			qDebug() << value;
			emit valueSelected(value);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
			ui->action_OpenUrl->setEnabled(false);
			emit valueSelected(-1);
		}
	}
}

void ViewSites::slotEnableButtons(const QItemSelection &, const QItemSelection &)
{
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_OpenUrl->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
	/*	int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
		qDebug() << value;
		emit valueSelected(value);*/
	}
	else
	{
		ui->action_New->setEnabled(true);
		ui->action_Yes->setEnabled(false);
		ui->action_No->setEnabled(false);
		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(false);
			ui->action_OpenUrl->setEnabled(false);
			emit valueSelected(-1);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
			ui->action_OpenUrl->setEnabled(true);
			int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
			qDebug() << value;
			emit valueSelected(value);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
			ui->action_OpenUrl->setEnabled(false);
			emit valueSelected(-1);
		}
	}
	
}


void ViewSites::createTable()
{
	m_model->loadData(1);
	ui->tableView->setModel(m_model);

	comboDelegateLanguage = new ComboDelegate(Language::getList(), this);
	ui->tableView->setItemDelegateForColumn(3, comboDelegateLanguage);
	

	comboDelegateGPI = new ComboDelegate(GeodataType::getList(), this);
	ui->tableView->setItemDelegateForColumn(4, comboDelegateGPI);


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->resizeColumnsToContents();
	ui->tableView->resizeRowsToContents();
	
	ui->tableView->setColumnWidth(1, 120);
	ui->tableView->setColumnWidth(2, 300);
	ui->tableView->setColumnWidth(3, 200);
	ui->tableView->setColumnWidth(4, 300);
	ui->tableView->setColumnWidth(5, 300);

}

void ViewSites::slotAdd()
{
	m_editMode = true;
	
	QModelIndex index;
	m_model->insertRows(0, 1, index);
	ui->tableView->resizeRowsToContents();
	auto rowCount = m_model->rowCount(index);
	auto child = m_model->index(rowCount - 1, 0, index); 
	ui->tableView->selectionModel()->setCurrentIndex(child, QItemSelectionModel::SelectCurrent);
	ui->tableView->edit(child);
	emit signalChangeEditMode();
}

void ViewSites::slotDelete()
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

void ViewSites::slotEdit()
{
	
	m_editMode = true;
	emit signalChangeEditMode();
	auto index = ui->tableView->selectionModel()->currentIndex();
	m_model->startEditMode(index);
	ui->tableView->edit(index);
}

void ViewSites::slotSave()
{
	if (m_model->save())
	{
		m_editMode = false;
		emit signalChangeEditMode();
		QMessageBox::information(this, "", "Сохранено", QMessageBox::Ok);
		emit dataChanged();
	}
	else
		QMessageBox::critical(this, "", "Не удалось применить изменения", QMessageBox::Ok);
	auto index = ui->tableView->selectionModel()->currentIndex();
	ui->tableView->resizeRowsToContents();
}

void ViewSites::slotCancel()
{
	if (m_model->cancel())
	{
		setDisabled();
	}
	else
		QMessageBox::critical(this, "", "Не удалось отменить изменения", QMessageBox::Ok);
	auto index = ui->tableView->selectionModel()->currentIndex();
	ui->tableView->reset();
	ui->tableView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select |
		QItemSelectionModel::Rows);
	
}

void ViewSites::slotOpenUrl()
{
	auto index = ui->tableView->selectionModel()->currentIndex();
	int row = index.row();
	auto child = m_model->index(row, 2);
	QString url= m_model->data(child).toString();
	QUrl m_url(url);
	bool res=QDesktopServices::openUrl(m_url);
}

