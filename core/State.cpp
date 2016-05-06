#include "State.h"
#include "Database.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTextCodec>

QString State::state_name()
{
	return m_state_name;
}

State::State(QString state_name)
{
	m_state_name = state_name;
	m_state_id = 0;
}

State::State(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(this, db);
	model.setTable("states");
	const QString filter = QString("state_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString state_name = model.record(0).value("state_name").toString();
	db.close();

	m_state_id = id;
	m_state_name= state_name;
}

State::~State()
{
}

int State::state_id()
{
	return m_state_id;
}

int State::state_id(QString state_name)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("SELECT state_id FROM states WHERE state_name=\'" + state_name + "\'"))
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

bool State::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO states(state_name)\
	VALUES (?)");
	query.addBindValue(m_state_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table states";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool State::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS states (\
		state_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		state_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating states Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool State::insert(QStringList stateNames)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	for (int i = 0; i < stateNames.count(); i++)
	{
		query.prepare("INSERT INTO states(state_name)\
	VALUES (?)");
		query.addBindValue(stateNames.at(i));
		if (!query.exec()) {
			qDebug() << "State :: insert(QStringList stateNames): error inserting into Table states";
			qDebug() << query.lastError().text();
			db.close();
			return false;
		}
	}
	db.close();
	return true;
}


bool State::completeTable()
{
	QStringList stateNames;
	stateNames << "Не установлено"
		<< "Актуально"
		<< "Неактуально";
	return insert(stateNames);
}

QStringList State::getStates()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QStringList listStates;
	if (!query.exec("SELECT state_name FROM states"))
	{
		qDebug() << query.lastError().text();
		db.close();
		return listStates;
	}
	while (query.next()) {
		QString name = query.value(0).toString();
		listStates.push_back(name);
	}
	return listStates;
}

