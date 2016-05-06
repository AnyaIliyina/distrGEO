#include "Site.h"
#include "Log.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>

const QString & Site::site_name() const
{
	return m_site_name;
}

const QString & Site::comment() const
{
	return m_comment;
}

int Site::site_id() const
{
	return m_site_id;
}


const QString&  Site::url() const
{
	return m_url;
}

Site::Site(const QString& url, const QString& site_name, int status, const QString& comment)
{
	m_site_id = 0;
	m_url = url;
	m_site_name = site_name;
	m_status_id = status;
	m_comment = comment;
}

Site::Site(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("sites");
	//const QString filter("siteId == " + QString::number(site_id));
	const QString filter = QString("site_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString url = model.record(0).value("url").toString();
	QString site_name = model.record(0).value("site_name").toString();
	int status_id= model.record(0).value("status_id").toInt();
	QString comment = model.record(0).value("comment").toString();
	db.close();
		
	m_site_id = id;
	m_url = url;
	m_site_name = site_name;
	m_status_id = status_id;
	m_comment = comment;
}

Site::~Site()
{
}


int Site::site_id()
{
	return m_site_id;
}

int Site::status_id() const
{
	return m_status_id;
}

bool Site::setStatusId(int site_id, int status_id, int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("UPDATE sites\
		SET status_id = ?\
		WHERE site_id = ?");
	query.addBindValue(status_id);
	query.addBindValue(site_id);
	if (!query.exec()) {
		qDebug() << "Site::setStatusId(int site_id, int status_id):  error inserting into Table sites";
		QString errorString =  query.lastError().text();
		db.close();
		Log::create(session_id, "Site: setStatusId", site_id, errorString);
		return false;
	}
	db.close();
	Log::create(session_id, "Site: setStatusId", site_id);
	return true;
}


int Site::site_id(QString & site_name) 
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("SELECT site_id FROM sites WHERE site_name=\'" + site_name + "\'"))
	{
		qDebug() << query.lastError().text();
		return -1;
	}
	else
	{
		if (query.next())
		{
			int id = query.value(0).toInt();
			return id;
		}
	}
}


int Site::insertIntoDatabase(int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO sites ( url, site_name, status_id, comment)\
		VALUES (?, ?, ?, ?)");
	query.addBindValue(m_url);
	query.addBindValue(m_site_name);
	query.addBindValue(m_status_id);
	query.addBindValue(m_comment);
	if (!query.exec()) {
		qDebug() << "Site::insertIntoDatabase():  error inserting into Table sites";
		QString errorString = query.lastError().text();
		qDebug() << errorString;
		db.close();
		Log::create(session_id, "Site: insert", 0, errorString);
		return -1;
	}
	else {
		int id = query.lastInsertId().toInt();
		db.close();
		Log::create(session_id, "Site: insert", id);
		return id;
	}
	
}


bool Site::insert(QList<Site> sites)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	for (int i = 0; i < sites.count(); i++)
	{
		query.prepare("INSERT INTO sites ( url, site_name, status_id, comment)\
		VALUES (?, ?, ?, ?)");
		query.addBindValue(sites.at(i).url());
		query.addBindValue(sites.at(i).site_name());
		query.addBindValue(sites.at(i).status_id());
		query.addBindValue(sites.at(i).comment());
		if (!query.exec()) {
			qDebug() << "Site::insertIntoDatabase(QList<Site> sites):  error inserting into Table sites";
			qDebug() << query.lastError().text();
			db.close();
			return false;
		}
	}
	db.close();
	return true;
}

bool Site::urlIsNew(const QString & url)
{
	// TODO
	return false;
}

bool Site::uncheckedSitesFound()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("SELECT site_id FROM sites WHERE status_id=1"))
	{
		qDebug() << "Site::uncheckedSitesFound() error";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}

	if (query.next())	{
		db.close();
		return true;
	}
	else	{
		db.close();
		return false;
	}
}



bool Site::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.exec("PRAGMA foreign_keys = ON");
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  sites (\
		site_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		url     TEXT    UNIQUE NOT NULL,\
		site_name TEXT UNIQUE NOT NULL,\
		status_id INTEGER,		\
		comment TEXT,   \
		FOREIGN KEY(status_id) REFERENCES statuses(status_id)\
		)"
		)) )
	{
		qDebug() << "error creating sites Table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
	
}

bool Site::completeTable()
{
		QList<Site> sites;
	sites << Site("http://beryllium.gis-lab.info/project/osmshp", "gis-lab.info")
		<< Site("http://www.afanas.ru/mapbase/", "afanas.ru")
		<< Site("http://download.geofabrik.de/index.html", "geofabrik.de");
	return insert(sites);
}

QList<Site> Site::sitesByStatus(int statusId)
{
	QList<Site> siteList;
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("sites");
	const QString filter = QString("status_id == %1").arg(statusId);
	model.setFilter(filter);
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
	{
		Site *s = new Site(model.record(i).value("site_id").toInt());
		siteList.append(*s);
		delete s;
	}
	db.close();
	return siteList;
}

QStringList Site::getSiteNames()

{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QStringList listSites;
	if (!query.exec("SELECT site_name FROM sites"))
	{
		qDebug() << query.lastError().text();
		db.close();
		return listSites;
	}
	while (query.next()) {
		QString name = query.value(0).toString();
		listSites.push_back(name);
	}
	return listSites;
}

bool Site::urlFromString(QString & string)
{
	const QString urlStr = string.trimmed();
	const QRegExp qualifiedUrl(QLatin1String("(http|ftp|https):\/\/[\w\-_]+(\.[\w\-_]+)+([\w\-\.,@?^=%&amp;:/~\+#]*[\w\-\@?^=%&amp;/~\+#])?"));

	// Check if it looks like a qualified URL. Try parsing it and see.
	const bool hasSchema = qualifiedUrl.exactMatch(urlStr);
	if (hasSchema) {
		const QUrl url(urlStr, QUrl::TolerantMode);
		if (url.isValid())
			return true;
	}
	return false;
}
