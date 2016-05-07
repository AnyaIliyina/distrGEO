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
	QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int index)), this, SLOT(slotTabConfigure(int index)));
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
	/*vw = new ViewWindow();
	QDockWidget *viewDockWidget = new QDockWidget("Список записей");
	viewDockWidget->setWidget(vw);
	viewDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setCentralWidget(viewDockWidget);
	*/
	m_vd = new ViewDepartments();
	m_vs = new ViewSites();
	m_tr = new TreeRegions();
	tree = new QTreeView();

	QWidget *departaments = new QWidget();
	QWidget *sites = new QWidget();

	QHBoxLayout *layoutDepart = new QHBoxLayout();
	QHBoxLayout *layoutSites = new QHBoxLayout();

	layoutDepart->addWidget(m_vd);
	layoutDepart->addWidget(tree);
	layoutSites->addWidget(m_vs);
	layoutSites->addWidget(tree);

	ui->tabWidget->addTab(sites, "Интернет-ресурсы");
	ui->tabWidget->addTab(departaments, "Ведомства");
	ui->tabWidget->addTab(m_tr, "Регионы");
	
	departaments->setLayout(layoutDepart);
	sites->setLayout(layoutSites);

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

void MainWindow::slotTabConfigure(int index)
{

}


/*!
Выводит основное окно и начинает работу модуля поиска
*/
void MainWindow::showMW()
{
	this->show();
	
	// Начать работу модуля поиска
	if (Site::uncheckedSitesFound()) 
	{
		SM_Session *session = new SM_Session();
		QObject::connect(session, SIGNAL(signalStatusOffered(const QString &)),
			SLOT(slotShowStatus(const QString &)));	// по сигналу от session менять текст в StatusBar
		session->start();
	}
	else statusBar()->showMessage("Модуль поиска: не найдено сайтов для проверки");
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
