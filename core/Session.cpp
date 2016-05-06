#include "Session.h"
#include "Database.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTextCodec>

Session::Session(int user_id, QDateTime date)
{
	m_session_id = 0;
	m_user_id = user_id;
	m_date = date;
}

Session::Session(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(this, db);
	model.setTable("sessions");
	const QString filter = QString("session_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	int user_id = model.record(0).value("user_id").toInt();
	int date = model.record(0).value("date").toInt();
	db.close();

	m_session_id = id;
	m_user_id = user_id;
	m_date = QDateTime::fromTime_t(date);
	
}

Session::~Session()
{
}

int Session::session_id()
{
	return m_session_id;
}

bool Session::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO sessions ( user_id, date)\
		VALUES (?, ?)");
	query.addBindValue(m_user_id);
	query.addBindValue(m_date.toTime_t());
	
	if (!query.exec()) {
		qDebug() << "Session::insertIntoDatabase():  error inserting into Table sessions";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	m_session_id = query.lastInsertId().toInt();
	db.close();
	return true;
}


bool Session::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  sessions (\
		session_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		user_id     INTEGER ,\
		date INTEGER, \
		FOREIGN KEY(user_id) REFERENCES users(user_id)\
		 )"
		)))
	{
		qDebug() << "error creating sessions Table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;

}

bool Session::createSession(int user_id)
{
	Session *session = new Session(user_id, QDateTime::currentDateTime());
	if(!session->insertIntoDatabase())
		return false;
	Database::setCurrentSessionId(session->session_id());
	delete session;
	return true;
}

bool Session::createSMsession()
{
	Session *session = new Session(1, QDateTime::currentDateTime());
	if (!session->insertIntoDatabase())
		return false;
	Database::setSmSessionId(session->session_id());
	delete session;
	return true;
}

bool Session::createSystemSession()
{
	Session *session = new Session(2, QDateTime::currentDateTime());
	if (!session->insertIntoDatabase())
		return false;
	Database::setSystemSessionId(session->session_id());
	delete session;
	return true;
}

bool Session::completeTable()
{
	// Первая сессия в базе - сессия Системы(user_id = 2);
	Session *s = new Session(2, QDateTime::currentDateTime());
	bool succeeded = s->insertIntoDatabase();
	if(succeeded)
		Database::setSystemSessionId(s->session_id());
	delete s;
	return succeeded;
}
