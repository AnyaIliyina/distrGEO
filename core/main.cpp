#include <QApplication>
#include <qDebug>
#include "Database.h"
#include "Session.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Site.h"
#include "MainWindow.h"

/*!
\file
\brief Enterance point
*/

int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	Database::restore();
	MainWindow *w = new MainWindow();
	return app.exec();
};