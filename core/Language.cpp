#include "Language.h"
#include "Database.h"
#include <QString>

bool Language::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS languages (\
		id INTEGER PRIMARY KEY AUTOINCREMENT, \
		name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating Languages table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Language::completeTable()
{
	QStringList languages;
	languages << "русский" << "английский";
	return insert(languages);
}

bool Language::insert(QStringList languageNames)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	for (int i = 0; i < languageNames.count(); i++)
	{
		query.prepare("INSERT INTO languages(name)\
	VALUES (?)");
		query.addBindValue(languageNames.at(i));
		if (!query.exec()) {
			qDebug() << "Language::insert(QStringList languageNames): error inserting into table Languages";
			qDebug() << query.lastError().text();
			db.close();
			return false;
		}
	}
	db.close();
}

QStringList Language::getList()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QStringList languages;
	if (!query.exec("SELECT name FROM languages"))
	{
		qDebug() << query.lastError().text();
		db.close();
		return languages;
	}
	while (query.next()) {
		QString name = query.value(0).toString();
		languages.push_back(name);
	}
	return languages;
}

