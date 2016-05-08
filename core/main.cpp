#include <QApplication>
#include <qDebug>
#include "Database.h"
#include "Session.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Site.h"
#include "Language.h"
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
	Database::restore();
	
	//// все языки:
	//QStringList languagesList = Language::getList();
	//
	//// конкретный сайт и его языки:
	//Site *site = new Site(1);
	//QStringList siteLangs;

	//QList<int>ids = site->languageIDs();
	//for (int i = 0; i < ids.count(); i++)
	//	siteLangs << languagesList.at(ids.at(i));
	//qDebug() << siteLangs.at(0);

	MainWindow *w = new MainWindow();
	return app.exec();
};