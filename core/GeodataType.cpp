#include "GeodataType.h"
#include "Database.h"
#include <QStringList>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
bool GeodataType::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS geodata_types (\
		id INTEGER PRIMARY KEY AUTOINCREMENT, \
		name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating Geodata_types table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool GeodataType::completeTable()
{
	QStringList typeNames;
	typeNames << "аэрофотоснимки"
		<< "картографические материалы"
		<< "данные дистанционного зондирования";
	return insert(typeNames);
}

bool GeodataType::insert(QStringList typeNames)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	for (int i = 0; i < typeNames.count(); i++)
	{
		query.prepare("INSERT INTO geodata_types(name)\
	VALUES (?)");
		query.addBindValue(typeNames.at(i));
		if (!query.exec()) {
			qDebug() << "GeodataType::insert(QStringList typeNames): error inserting into table Geodata_types";
			qDebug() << query.lastError().text();
			db.close();
			return false;
		}
	}
	db.close();
}

QStringList GeodataType::getList()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QStringList typeNames;
	if (!query.exec("SELECT name FROM geodata_types"))
	{
		qDebug() << query.lastError().text();
		db.close();
		return typeNames;
	}
	while (query.next()) {
		QString name = query.value(0).toString();
		typeNames.push_back(name);
	}
	return typeNames;
}
