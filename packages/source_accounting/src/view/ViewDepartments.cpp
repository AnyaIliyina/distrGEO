#include "ViewDepartments.h"
#include "Database.h"
#include "Scale.h"
#include "State.h"
#include "Geodata_record.h"
#include "GeodataType.h"
#include "Item_model.h"
#include "Combo_delegate.h"
#include "Site.h"
#include "Format.h"
#include "Session.h"
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>


ViewDepartments::ViewDepartments(QWidget * parent): ui(new Ui::ViewDepartments) // ??
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
	
}

ViewDepartments::~ViewDepartments()
{
	delete ui;
	delete m_model;
}

void ViewDepartments::setupModel()
{
	delete m_model;
	QSqlDatabase db = Database::database();
	m_model = new ItemModel();
	createTable();
}

void ViewDepartments::setDisabled()
{
	ui->action_Edit->setEnabled(false);
	ui->action_Delete->setEnabled(false);
	ui->action_New->setEnabled(false);
	ui->action_Yes->setEnabled(false);
	ui->action_No->setEnabled(false);
	
}

void ViewDepartments::slotRefresh()
{
	setupModel();
}

void ViewDepartments::slotEnableButtons()
{
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
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
			emit valueSelected(-1);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
			int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
			qDebug() << value;
			emit valueSelected(value);
			
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
			emit valueSelected(-1);
		}
	}
}

void ViewDepartments::slotEnableButtons(const QItemSelection &, const QItemSelection &)
{
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
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
			emit valueSelected(-1);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
			int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
			qDebug() << value;
			emit valueSelected(value);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
			emit valueSelected(-1);
		}
	}
	
}



void ViewDepartments::createTable()
{
	m_model->loadData(2);
	ui->tableView->setModel(m_model);

	auto comboDelegate = new ComboDelegate(GeodataType::getList(), this);
	ui->tableView->setItemDelegateForColumn(7, comboDelegate);

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->resizeColumnsToContents();
	ui->tableView->resizeRowsToContents();

	ui->tableView->setColumnWidth(1, 300);
	ui->tableView->setColumnWidth(2, 150);
	ui->tableView->setColumnWidth(3, 350);
	ui->tableView->setColumnWidth(4, 100);
	ui->tableView->setColumnWidth(5, 100);
	ui->tableView->setColumnWidth(6, 200);
	ui->tableView->setColumnWidth(7, 350);
	ui->tableView->setColumnWidth(8, 350);


	
}

void ViewDepartments::slotAdd()
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

void ViewDepartments::slotDelete()
{
	
	int  deleteMsgBox = QMessageBox::question(this, "",
		"Удалить выбранную запись?",
		QMessageBox::Yes, QMessageBox::No);
	if (deleteMsgBox == QMessageBox::Yes)
	{
		auto indexes = ui->tableView->selectionModel()->selectedRows();
		for (int i = indexes.count() - 1; i >= 0; i--)
		{
			auto index = indexes.at(i);
			m_model->removeRows(0, 1, index);
		}
	}
}

void ViewDepartments::slotEdit()
{
	
	m_editMode = true;
	emit signalChangeEditMode();
	emit signalEditSite();
	auto index = ui->tableView->selectionModel()->currentIndex();
	ui->tableView->resizeRowsToContents();
	m_model->startEditMode(index);
	ui->tableView->edit(index);
}

void ViewDepartments::slotSave()
{
	if (m_model->save())
	{
		m_editMode = false;
		emit signalChangeEditMode();
		QMessageBox::information(this, "", "Сохранено", QMessageBox::Ok);
		int value = m_model->data(ui->tableView->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
		emit signalSave(value, true);
	}
	else
	{
		emit signalSave(-1, false);
		QMessageBox::critical(this, "", "Не удалось применить изменения", QMessageBox::Ok);
	}
		/*auto index = ui->tableView->selectionModel()->currentIndex();
	ui->tableView->resizeRowsToContents();*/

}

void ViewDepartments::slotCancel()
{
	if (m_model->cancel())
	{
		m_editMode = false;
		emit signalChangeEditMode();
		emit signalSave(-1, false);
	}
	else
		QMessageBox::critical(this, "", "Не удалось отменить изменения", QMessageBox::Ok);
	auto index = ui->tableView->selectionModel()->currentIndex();
	ui->tableView->reset();
	ui->tableView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select |
		QItemSelectionModel::Rows);
	
}

