#include "Format.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

/*!
\file
\brief  
*/


const QString& Format::format_name() const
{
	return m_format_name;
}

int Format::format_id(QString format_name) 
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("SELECT format_id FROM formats WHERE format_name=\'" + format_name + "\'"))
	{
		qDebug() << "Zapros ne proshel";
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


Format::Format(const QString &format_name)
{
	m_format_name = format_name;
	m_format_id = 0;
}

Format::Format(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(this, db);
	model.setTable("formats");
	const QString filter = QString("format_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString format_name = model.record(0).value("format_name").toString();
	db.close();

	m_format_id = id;
	m_format_name = format_name;
}

Format::~Format()
{
}

bool Format::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO formats(format_name)\
	VALUES (?)");
	query.addBindValue(m_format_name);
	if (!query.exec()) {
		qDebug() << "Format::insertIntoDatabase(): error inserting into Table formats";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Format::insert(QStringList formatNames)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	for (int i = 0; i < formatNames.count(); i++)
	{
		query.prepare("INSERT INTO formats(format_name)\
	VALUES (?)");
		query.addBindValue(formatNames.at(i));
		if (!query.exec()) {
			qDebug() << "Format::insert(QStringList formatNames): error inserting into Table formats";
			qDebug() << query.lastError().text();
			db.close();
			return false;
		}
	}
	db.close();
}

bool Format::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS formats (\
		format_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		format_name TEXT UNIQUE NOT NULL\
		)"
		))
	{	
		qDebug() << "error creating formats Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Format::completeTable()
{
	QStringList formatNames;
	formatNames << ".shp"
				<< ".osm.pbf"
				<< ".osm.bz2"
				<< ".png";
	return insert(formatNames);
}

QStringList Format::getFormatNames()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QStringList listFormat;
	if (!query.exec("SELECT format_name FROM formats"))
	{
		qDebug() << query.lastError().text();
		db.close();
		return listFormat;
	}
	while (query.next()) {
		QString name = query.value(0).toString();
		listFormat.push_back(name);
	}
	return listFormat;
}
