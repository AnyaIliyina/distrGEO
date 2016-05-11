#include "MainWindow.h"
#include "SM_Session.h"
#include "Session.h"
#include "Site.h"
#include "User.h"
#include "ViewSites.h"
#include "ViewDepartments.h"
#include "TreeRegions.h"
#include "State.h"
#include "Database.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>

MainWindow::MainWindow(QMainWindow *parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
	
	// Показать диалог с запросом пароля до появления основного окна:
	LoginDialog *ld = new LoginDialog(); 
	
	QObject::connect(ld, SIGNAL(signalLogedIn(int)),	this, SLOT(slotStartSession(int)));	 // авторизация пройдена - отобразить основное окно, 
																							// начать работу модуля поиска
	ld->slotShowLD();

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
	
	setSearchResources();
	setResourcesView();
	setDepartamentView();

	ui->tabWidget->addTab(search, "Поиск источников");
	ui->tabWidget->addTab(new QWidget, "Поиск материалов");
	ui->tabWidget->addTab(sites, "Интернет-ресурсы");
	ui->tabWidget->addTab(departaments, "Ведомства");
	ui->tabWidget->addTab(new QWidget, "Материалы");
	ui->tabWidget->addTab(m_tr, "Регионы");


	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
	showMW();
	
}


void MainWindow::slotStartSession(int user_id)
{
	Session::createSession(user_id);
	qDebug() << "SEEEEEEEEEE" << Database::currentSessionId();
	slotConfigure();
}

void MainWindow::slotSelectRegion(int i)
{
	qDebug() << "slooooot";
	if (i < 0)
	{
		treeSites->showMinimized();
		treeSites->setEnabled(false);
	}
	else
	{
		treeSites->setModel(m_tr->model());
		treeSites->showNormal();
		treeSites->setEnabled(true);
		
	}
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

void MainWindow::setSearchResources()
{
	treeSearch = new QTreeView();
	treeSearch->setMaximumWidth(400);
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
	setupModel();
}

void MainWindow::setResourcesView()
{
	m_vs = new ViewSites();
	treeSites = new QTreeView();
	treeSites->setMaximumSize(300, 1000);
	treeSites->showMinimized();
	treeSites->setEnabled(false);
	QObject::connect(m_vs, SIGNAL(valueSelected(int)), this, SLOT(slotSelectRegion(int)));
	sites = new QWidget();
	QHBoxLayout *layoutSites = new QHBoxLayout();
	layoutSites->addWidget(m_vs);
	layoutSites->addWidget(treeSites);
	sites->setLayout(layoutSites);
}

void MainWindow::setDepartamentView()
{
	m_vd = new ViewDepartments();
	treeDepartments = new QTreeView();
	treeDepartments->setMaximumSize(300, 1000);
	treeDepartments->setModel(m_tr->model());
	departaments = new QWidget();
	QHBoxLayout *layoutDepart = new QHBoxLayout();
	layoutDepart->addWidget(m_vd);
	layoutDepart->addWidget(treeDepartments);
	departaments->setLayout(layoutDepart);

}

void MainWindow::setupModel()
{
	
	m_res_model = new ItemModel();
	m_res_model->loadData(1);
	m_dep_model = new ItemModel();
	m_dep_model->loadData(2);
	
	tableSites->setModel(m_res_model);
	tableSites->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableSites->setColumnHidden(0, true);
	tableSites->setSortingEnabled(true);
	tableSites->resizeColumnsToContents();
	tableDepartments->setModel(m_dep_model);
	tableDepartments->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableDepartments->setColumnHidden(0, true);
	tableDepartments->setSortingEnabled(true);
	tableDepartments->resizeColumnsToContents();
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
