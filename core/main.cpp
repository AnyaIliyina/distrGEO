#include <QApplication>
#include <qDebug>
#include "Database.h"
#include "Session.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Site.h"
#include "MainWindow.h"
#include "Multilist.h"
#include "Site.h"

/*!
\file
\brief Enterance point
*/

int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	/*MultiListWidget *multiList = new MultiListWidget();

	multiList->addItems(QStringList() << "One" << "Two" << "Three" << "Four");
	multiList->setCheckedItems(QStringList() << "One" << "Three");

	QHBoxLayout *layout = new QHBoxLayout();

	layout->addWidget(new QLabel("Select items:"));
	layout->addWidget(multiList, 1);

	QWidget widget;

	widget.setWindowTitle("MultiList example");
	widget.setLayout(layout);

	widget.show();

	return app.exec();*/
	Database::restore();
	//qDebug() << "site " << Site(1).languages().count();
	MainWindow *w = new MainWindow();
	return app.exec();
};