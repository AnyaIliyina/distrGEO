#include "TreeRegions.h"
#include "RegionItem.h"
#include "Item_model.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QDesktopServices>



TreeRegions::TreeRegions(QWidget * parent): ui(new Ui::TreeRegions) // ??
{
	ui->setupUi(this);
	setupModel();
	
	
	//setDisabled();
	/*QObject::connect(ui->action_New, SIGNAL(triggered()), this, SLOT(slotAdd()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDelete()));
	QObject::connect(ui->action_Edit, SIGNAL(triggered()), this, SLOT(slotEdit()));
	QObject::connect(ui->action_Yes, SIGNAL(triggered()), this, SLOT(slotSave()));
	QObject::connect(ui->action_No, SIGNAL(triggered()), this, SLOT(slotCancel()));
	
	QObject::connect(this, SIGNAL(signalChangeEditMode()), this, SLOT(slotEnableButtons()));
	QObject::connect(this, SIGNAL(dataChanged()), this, SLOT(slotRefresh()));*/
	
	//QObject::connect(ui->tableView->model, SIGNAL(signalId(int)), this, SLOT(slotIdRecord()));
}

TreeRegions::~TreeRegions()
{
	delete ui;
	delete m_model;
}

void TreeRegions::setupModel()
{
	delete m_model;
	m_model = new ItemModel();
	m_model->loadData(3);
	ui->treeView->setModel(m_model);
	//createTable();
}

void TreeRegions::setDisabled()
{
	ui->action_Edit->setEnabled(false);
	ui->action_Delete->setEnabled(false);
	//ui->action_New->setEnabled(false);
	ui->action_Yes->setEnabled(false);
	ui->action_No->setEnabled(false);
	
}

void TreeRegions::slotRefresh()
{
	setupModel();
}

//void TreeRegions::slotEnableButtons()
//{
//	if (m_editMode)
//	{
//		ui->action_Edit->setEnabled(false);
//		ui->action_Delete->setEnabled(false);
//		ui->action_New->setEnabled(false);
//		ui->action_OpenUrl->setEnabled(false);
//		ui->action_Yes->setEnabled(true);
//		ui->action_No->setEnabled(true);
//	}
//	else
//	{
//		ui->action_New->setEnabled(true);
//		ui->action_Yes->setEnabled(false);
//		ui->action_No->setEnabled(false);
//		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
//		{
//			ui->action_Delete->setEnabled(true);
//			ui->action_Edit->setEnabled(false);
//			ui->action_OpenUrl->setEnabled(false);
//		}
//		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
//		{
//			ui->action_Delete->setEnabled(true);
//			ui->action_Edit->setEnabled(true);
//			ui->action_OpenUrl->setEnabled(true);
//		}
//		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
//		{
//			ui->action_Delete->setEnabled(false);
//			ui->action_Edit->setEnabled(false);
//			ui->action_OpenUrl->setEnabled(false);
//		}
//	}
//}
//
//void TreeRegions::slotEnableButtons(const QItemSelection &, const QItemSelection &)
//{
//	if (m_editMode)
//	{
//		ui->action_Edit->setEnabled(false);
//		ui->action_Delete->setEnabled(false);
//		ui->action_New->setEnabled(false);
//		ui->action_OpenUrl->setEnabled(false);
//		ui->action_Yes->setEnabled(true);
//		ui->action_No->setEnabled(true);
//	}
//	else
//	{
//		ui->action_New->setEnabled(true);
//		ui->action_Yes->setEnabled(false);
//		ui->action_No->setEnabled(false);
//		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
//		{
//			ui->action_Delete->setEnabled(true);
//			ui->action_Edit->setEnabled(false);
//			ui->action_OpenUrl->setEnabled(false);
//		}
//		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
//		{
//			ui->action_Delete->setEnabled(true);
//			ui->action_Edit->setEnabled(true);
//			ui->action_OpenUrl->setEnabled(true);
//		}
//		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
//		{
//			ui->action_Delete->setEnabled(false);
//			ui->action_Edit->setEnabled(false);
//			ui->action_OpenUrl->setEnabled(false);
//		}
//	}
//	
//}
//
////void TreeRegions::slotFilterChanged(QString text)
////{
////	QRegExp regExp(text, Qt::CaseInsensitive);
////	filterModel->setFilterRegExp(regExp);
////}
//
void TreeRegions::createTable()
{
	//m_model->loadData(3);
	/*filterModel = new SortFilterProxyModel();
	filterModel->setSourceModel(m_model);*/
	//ui->treeView->setModel(m_model);

//--------------

	//QStandardItemModel* standardModel = new QStandardItemModel;
	//QStandardItem *rootNode = standardModel->invisibleRootItem();

	////defining a couple of items
	//QStandardItem *americaItem = new QStandardItem("America");
	//QStandardItem *mexicoItem = new QStandardItem("Canada");
	//QStandardItem *usaItem = new QStandardItem("USA");
	//QStandardItem *bostonItem = new QStandardItem("Boston");
	//QStandardItem *europeItem = new QStandardItem("Europe");
	//QStandardItem *italyItem = new QStandardItem("Italy");
	//QStandardItem *romeItem = new QStandardItem("Rome");
	//QStandardItem *veronaItem = new QStandardItem("Verona");

	////building up the hierarchy
	//rootNode->appendRow(americaItem);
	//rootNode->appendRow(europeItem);
	//americaItem->appendRow(mexicoItem);
	//americaItem->appendRow(usaItem);
	//usaItem->appendRow(bostonItem);
	//europeItem->appendRow(italyItem);
	//italyItem->appendRow(romeItem);
	//italyItem->appendRow(veronaItem);

	////register the model
	//ui->treeView->setModel(standardModel);
	//ui->treeView->expandAll();
	//---------------

	//auto comboDelegateSite = new ComboDelegate(Site::getSiteNames(), this);
	//ui->tableView->setItemDelegateForColumn(2, comboDelegateSite);

	//auto comboDelegateFormat = new ComboDelegate(Format::getFormatNames(), this);
	//ui->tableView->setItemDelegateForColumn(3, comboDelegateFormat);

	//auto comboDelegateScale = new ComboDelegate(Scale::getDescription(), this);
	//ui->tableView->setItemDelegateForColumn(4, comboDelegateScale);

	//auto comboDelegateState = new ComboDelegate(State::getStates(), this);
	//ui->tableView->setItemDelegateForColumn(5, comboDelegateState);

	//ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui->tableView->setColumnHidden(0, true);
	//ui->tableView->setSortingEnabled(true);
	//ui->tableView->resizeColumnsToContents();

}
//
//void TreeRegions::slotAdd()
//{
//	m_editMode = true;
//	emit signalChangeEditMode();
//	QModelIndex index;
//	auto m_index = filterModel->mapToSource(index);
//	m_model->insertRows(0, 1, m_index);
//	auto rowCount = m_model->rowCount(m_index);
//	auto child = m_model->index(rowCount - 1, 0, m_index); 
//	ui->tableView->selectionModel()->setCurrentIndex(child, QItemSelectionModel::SelectCurrent);
//	ui->tableView->edit(child);
//	
//}
//
//void TreeRegions::slotDelete()
//{
//	
//	int  deleteMsgBox = QMessageBox::question(this, "",
//		"Удалить выбранную запись?",
//		QMessageBox::Yes, QMessageBox::No);
//	if (deleteMsgBox == QMessageBox::Yes)
//	{
//		auto index = ui->tableView->selectionModel()->currentIndex();
//		auto m_index = filterModel->mapToSource(index);
//		m_model->removeRows(0, 1, m_index);
//	}
//}
//
//void TreeRegions::slotEdit()
//{
//	
//	m_editMode = true;
//	emit signalChangeEditMode();
//	auto index = ui->tableView->selectionModel()->currentIndex();
//	qDebug() << "index" << index;
//	auto m_index= filterModel->mapToSource(index);
//	qDebug() << "m_index" << m_index;
//	
//	m_model->startEditMode(m_index);
//	ui->tableView->edit(m_index);
//}
//
//void TreeRegions::slotSave()
//{
//	if (m_model->save())
//	{
//		m_editMode = false;
//		emit signalChangeEditMode();
//		QMessageBox::information(this, "", "Сохранено", QMessageBox::Ok);
//		emit dataChanged();
//	}
//	else
//		QMessageBox::critical(this, "", "Не удалось применить изменения", QMessageBox::Ok);
//	auto index = ui->tableView->selectionModel()->currentIndex();
//	auto m_index = filterModel->mapToSource(index);
//
//}
//
//void TreeRegions::slotCancel()
//{
//	if (m_model->cancel())
//	{
//		m_editMode = false;
//		emit signalChangeEditMode();
//	}
//	else
//		QMessageBox::critical(this, "", "Не удалось отменить изменения", QMessageBox::Ok);
//	auto index = ui->tableView->selectionModel()->currentIndex();
//	auto m_index = filterModel->mapToSource(index);
//	ui->tableView->reset();
//	ui->tableView->selectionModel()->setCurrentIndex(m_index, QItemSelectionModel::Select |
//		QItemSelectionModel::Rows);
//	
//}
//
//
//
