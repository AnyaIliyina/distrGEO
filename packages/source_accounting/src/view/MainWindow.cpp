#include "MainWindow.h"
#include "SM_Session.h"
#include "Session.h"
#include "Site.h"
#include "User.h"
#include "ViewSites.h"
#include "ViewDepartments.h"
#include "TreeRegions.h"
#include "SiteRegion.h"
#include "DepartmentRegion.h"
#include "State.h"
#include "Database.h"
#include "Types.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>
#include <QDockWidget>

MainWindow::MainWindow(QMainWindow *parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
	
	// Показать диалог с запросом пароля до появления основного окна:
	LoginDialog *ld = new LoginDialog(); 
	
	QObject::connect(ld, SIGNAL(signalLogedIn(int)),	this, SLOT(slotStartSession(int)));	 // авторизация пройдена - отобразить основное окно, 
																							// начать работу модуля поиска
	ld->slotShowLD();
	QObject::connect(tableSites, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotOpenUrl(QModelIndex)));
}


MainWindow::~MainWindow()
{
}


/*!
"Собирает" основное окно из виджетов
*/
void MainWindow::slotConfigure()
{	
	m_tr = new TreeRegions();
	
	QObject::connect(m_tr, SIGNAL(dataChanged()), SLOT(slotSetupRegionsModel()));
	setSearchResources();
	setResourcesView();
	setDepartamentView();
	//setContentView();
	ui->tabWidget->addTab(search, "Поиск источников");
	ui->tabWidget->addTab(sites, "Интернет-ресурсы");
	ui->tabWidget->addTab(departaments, "Ведомства");
	//ui->tabWidget->addTab(content, "Материалы");
	ui->tabWidget->addTab(m_tr, "Регионы");


	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
	showMW();
	
}


void MainWindow::slotStartSession(int user_id)
{
	Session::createSession(user_id);
	slotConfigure();
}

void MainWindow::slotSelectRegionSite(int id)
{
	if (id < 0)
	{
		treeSites->collapseAll();
		treeSites->setEnabled(false);
	}
	else
	{		
		treeSites->setEnabled(true);
		treeSites->expandAll();
		QList<int> IDs = SiteRegion::regionsBySite(id);
		for (int i = 0; i < map.count(); i++)
			map.values().at(i)->setChecked(false);
		for (int i = 0; i < IDs.count(); i++)
		{
			treeSites->setFocus();
			if (map.contains(IDs.at(i)))
			{
				map.value(IDs.at(i))->setChecked(true);
			}
		}		
	}
}

void MainWindow::slotSelectRegionDepartment(int id)
{
	if (id < 0)
	{
		treeDepartments->collapseAll();
		treeDepartments->setEnabled(false);
	}
	else
	{
		treeDepartments->setEnabled(true);
		treeDepartments->expandAll();
		QList<int> IDs = DepartmentRegion::regionsByDepartment(id);
		//map = RegionItemChecked::getMap();
		for (int i = 0; i < map.count(); i++)
			map.values().at(i)->setChecked(false);
		
		for (int i = 0; i < IDs.count(); i++)
		{
			treeDepartments->setFocus();
			if (map.contains(IDs.at(i)))
			{
				map.value(IDs.at(i))->setChecked(true);
				//treeDepartments->expand(m_regionsChecked->index(0, 0, treeDepartments->mo));
			}
		}

	}
}

void MainWindow::slotOpenUrl(const QModelIndex & index)
{
	auto m_index = tableSites->selectionModel()->currentIndex();
	int row = m_index.row();
	auto child = m_res_model->index(row, 2);
	QString url = m_res_model->data(child).toString();
	QUrl m_url(url);
	bool res = QDesktopServices::openUrl(m_url);
}

void MainWindow::slotForSearch(const QItemSelection &, const QItemSelection &)
{
	int id = treeSearch->model()->data(treeSearch->selectionModel()->selectedRows()[0], Qt::UserRole).toInt();
	setupModelSite(id);
	setupModelDepartment(id);
}

/*!
Выводит основное окно и начинает работу модуля поиска
*/
void MainWindow::showMW()
{
	this->setMinimumSize(1200, 600);
	this->show();
	
	// Начать работу модуля поиска
	//if (Site::uncheckedSitesFound()) 
	//{
	//	SM_Session *session = new SM_Session();
	//	QObject::connect(session, SIGNAL(signalStatusOffered(const QString &)),
	//		SLOT(slotShowStatus(const QString &)));	// по сигналу от session менять текст в StatusBar
	//	session->start();
	//}
	//else
		statusBar()->showMessage("Модуль поиска: не найдено сайтов для проверки");
}

void MainWindow::setContentView()
{
	m_vc = new ViewContent();
	m_vf = new ViewFiles();
	content = new QWidget();
	QVBoxLayout *vertLayout = new QVBoxLayout();
	vertLayout->addWidget(m_vc);
	vertLayout->addWidget(m_vf);
	content->setLayout(vertLayout);
}

void MainWindow::setSearchResources()
{
	treeSearch = new QTreeView();
	treeSearch->setMaximumWidth(400);
	treeSearch->setModel(m_tr->model());
	treeSearch->setColumnHidden(1, true);
	treeSearch->setColumnHidden(2, true);
	treeSearch->resizeColumnToContents(0);
	treeSearch->expandAll();
	tableSites = new QTableView();
	tableDepartments = new QTableView();
	search = new QWidget();
	QHBoxLayout *layoutSearch = new QHBoxLayout();
	QVBoxLayout *verticalLayout = new QVBoxLayout();
	verticalLayout->addWidget(tableSites);
	verticalLayout->addWidget(tableDepartments);
	layoutSearch->addWidget(treeSearch);
	layoutSearch->addLayout(verticalLayout);
	search->setLayout(layoutSearch);
	QObject::connect(treeSearch->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
	this, SLOT(slotForSearch(const QItemSelection &, const QItemSelection &)));
}

void MainWindow::setResourcesView()
{
	m_vs = new ViewSites();

	treeSites = new QTreeView();
	treeSites->setMaximumSize(300, 1000);
	treeSites->showMinimized();
	treeSites->setEnabled(false);

	m_regionsChecked = new ItemModel();
	m_regionsChecked->loadData(ItemTypes::RegionItemCheckedType);

	map = RegionItemChecked::getMap();

	treeSites->setModel(m_regionsChecked);
	treeSites->setColumnHidden(1, true);
	treeSites->setColumnHidden(2, true);
	
	sites = new QWidget();
	QHBoxLayout *layoutSites = new QHBoxLayout();
	layoutSites->addWidget(m_vs);
	layoutSites->addWidget(treeSites);
	sites->setLayout(layoutSites);
	QObject::connect(m_vs, SIGNAL(valueSelected(int)), this, SLOT(slotSelectRegionSite(int)));
	QObject::connect(m_vs, SIGNAL(signalEditSite()), this, SLOT(slotGetCheckSite()));
	QObject::connect(m_vs, SIGNAL(signalSave(int, bool)), this, SLOT(slotEditCheckSite(int, bool)));
}

void MainWindow::setDepartamentView()
{
	m_vd = new ViewDepartments();

	treeDepartments = new QTreeView();
	treeDepartments->setMaximumSize(300, 1000);
	treeDepartments->showMinimized();
	treeDepartments->setEnabled(false);

	//map = RegionItemChecked::getMap();

	treeDepartments->setModel(m_regionsChecked);
	treeDepartments->setColumnHidden(1, true);
	treeDepartments->setColumnHidden(2, true);
	
	departaments = new QWidget();
	QHBoxLayout *layoutDepart = new QHBoxLayout();
	layoutDepart->addWidget(m_vd);
	layoutDepart->addWidget(treeDepartments);
	departaments->setLayout(layoutDepart);
	QObject::connect(m_vd, SIGNAL(valueSelected(int)), this, SLOT(slotSelectRegionDepartment(int)));
	QObject::connect(m_vd, SIGNAL(signalEditDepartment()), this, SLOT(slotGetCheckDepartment()));
	QObject::connect(m_vd, SIGNAL(signalSave(int, bool)), this, SLOT(slotEditCheckDepartment(int, bool)));
}

void MainWindow::slotSetupRegionsModel()
{
	treeSites->setModel(NULL);
	treeDepartments->setModel(NULL);

	m_regionsChecked->loadData(ItemTypes::RegionItemCheckedType);

	treeSites->setModel(m_regionsChecked);
	treeSites->setColumnHidden(2, true);
	treeSites->setColumnHidden(3, true);

	treeDepartments->setModel(m_regionsChecked);
	treeDepartments->setColumnHidden(2, true);
	treeDepartments->setColumnHidden(3, true);

	map = RegionItemChecked::getMap();
}

void MainWindow::setupModelSite(int id)
{	
	m_res_model = new ItemModel();
	m_res_model->loadData(1, id);
	tableSites->setModel(m_res_model);
	tableSites->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableSites->setColumnHidden(0, true);
	tableSites->resizeColumnsToContents();
	tableSites->resizeRowsToContents();
	tableSites->setColumnWidth(1, 120);
	tableSites->setColumnWidth(2, 300);
	tableSites->setColumnWidth(3, 200);
	tableSites->setColumnWidth(4, 300);
	tableSites->setColumnWidth(5, 300);
}

void MainWindow::setupModelDepartment(int id)
{
	m_dep_model = new ItemModel();
	m_dep_model->loadData(2, id);
	tableDepartments->setModel(m_dep_model);
	tableDepartments->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableDepartments->setColumnHidden(0, true);
	
	tableDepartments->resizeColumnsToContents();
	tableDepartments->resizeRowsToContents();
	tableDepartments->setColumnWidth(1, 300);
	tableDepartments->setColumnWidth(2, 150);
	tableDepartments->setColumnWidth(3, 350);
	tableDepartments->setColumnWidth(4, 100);
	tableDepartments->setColumnWidth(5, 100);
	tableDepartments->setColumnWidth(6, 200);
	tableDepartments->setColumnWidth(7, 350);
	tableDepartments->setColumnWidth(8, 350);
}

/*!
Закрывает основное окно
*/
void MainWindow::slotCloseMW()
{
		this->close();
}

/*!
Выводит сообщение на панель StatusBar
\param const QString &str - текст сообщения
*/
void MainWindow::slotShowStatus(const QString &str)
{
	statusBar()->showMessage(str);
}

void MainWindow::slotGetCheckSite()
{
	qDebug() << QObject::connect(treeSites->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(slotMakeCheckEditbleSite(const QItemSelection &, const QItemSelection &)));
}

void MainWindow::slotMakeCheckEditbleSite(const QItemSelection &, const QItemSelection &)
{
	auto index = treeSites->selectionModel()->currentIndex();
	m_regionsChecked->startEditMode(index);
	treeSites->edit(index);
}

void MainWindow::slotEditCheckSite(int id, bool saveChanges)
{
	QObject::disconnect(treeSites->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(slotMakeCheckEditbleSite(const QItemSelection &, const QItemSelection &)));
	map = RegionItemChecked::getMap();
		for (int i = 0; i < map.count(); i++)
		{
			if (id != -1)
			{
				if (map.values().at(i)->save())		// значение изменилось: галочку убрали или поставили 
				{
					int region_id = map.keys().at(i);
					SiteRegion *site_reg = new SiteRegion(id, region_id);
					if (map.values().at(i)->isChecked())	//галочку поставили
					{
						site_reg->insertIntoDatabase();
					}
					else
					{
						site_reg->deleteRecord();
					}
				}
			}
		}
}

void MainWindow::slotGetCheckDepartment()
{
	qDebug() << QObject::connect(treeDepartments->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(slotMakeCheckEditbleDepartment(const QItemSelection &, const QItemSelection &)));
}

void MainWindow::slotMakeCheckEditbleDepartment(const QItemSelection &, const QItemSelection &)
{
	auto index = treeDepartments->selectionModel()->currentIndex();
	m_regionsChecked->startEditMode(index);
	treeDepartments->edit(index);
}

void MainWindow::slotEditCheckDepartment(int id, bool saveChanges)
{
	QObject::disconnect(treeDepartments->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(slotMakeCheckEditbleDepartment(const QItemSelection &, const QItemSelection &)));
	map = RegionItemChecked::getMap();
	for (int i = 0; i < map.count(); i++)
	{
		if (map.values().at(i)->save())		// значение изменилось: галочку убрали или поставили 
		{
			if (id != -1)
			{
				int region_id = map.keys().at(i);
				DepartmentRegion *dep_reg = new DepartmentRegion(id, region_id);
				if (map.values().at(i)->isChecked())	//галочку поставили
				{
					dep_reg->insertIntoDatabase();
				}
				else
				{
					dep_reg->deleteRecord();
				}

			}
		}
	}
}