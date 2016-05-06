#include "Department.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include "Log.h"

/*!
\file
\brief  
*/

Department::Department()
{
}

Department::~Department()
{
}

int Department::id() const
{
	return m_id;
}

const QString & Department::name() const
{
	return m_name;
}

const QString & Department::country() const
{
	return m_country;
}

const QString & Department::adress() const
{
	return m_adress;
}

const QString & Department::mail() const
{
	return m_mail;
}

const QString & Department::phone() const
{
	return m_phone;
}

const QString & Department::fax() const
{
	return m_fax;
}

void Department::setName(const QString & name)
{
	m_name = name;
}

void Department::setCountry(const QString & country)
{
	m_country = country;
}

void Department::setPhone(const QString & phone)
{
	m_phone = phone;
}

void Department::setAdress(const QString & adress)
{
	m_adress = adress;
}

void Department::setFax(const QString & fax)
{
	m_fax = fax;
}

void Department::setMail(const QString & mail)
{
	m_mail = mail;
}

Department::Department(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("departments");
	const QString filter = QString("id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString name = model.record(0).value("name").toString();
	QString country = model.record(0).value("country").toString();
	QString adress = model.record(0).value("adress").toString();
	QString mail = model.record(0).value("mail").toString();
	QString fax = model.record(0).value("fax").toString();
	QString phone = model.record(0).value("phone").toString();
	db.close();

	m_id = id;
	m_name = name;
	m_country = country;
	m_adress = adress;
	m_mail = mail;
	m_fax = fax;
	m_phone = phone;
}

bool Department::insertIntoDatabase(int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO departments (name, country, adress, mail, fax, phone)\
		VALUES (?, ?, ?, ?, ?, ?)");
	query.addBindValue(m_name);
	query.addBindValue(m_country);
	query.addBindValue(m_adress);
	query.addBindValue(m_mail);
	query.addBindValue(m_fax);
	query.addBindValue(m_phone);
	if (!query.exec()) {
		qDebug() << "Department::insertIntoDatabase():  error inserting into table Departments";
		QString errorString = query.lastError().text();
		qDebug() << errorString;
		db.close();
		Log::create(session_id, "Department: insert", 0, errorString);
		return false;
	}
	else {
		m_id = query.lastInsertId().toInt();
		db.close();
		Log::create(session_id, "Site: insert", m_id);
		return true;
	}
}

bool Department::update(int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("UPDATE departments\
					SET\
					name=:name, country=:country, \
					adress=:adress, mail=:mail, fax=:fax,\
					phone=:phone WHERE id=:id");
	query.bindValue(":name", m_name);
	query.bindValue(":country", m_country);
	query.bindValue(":adress", m_adress);
	query.bindValue(":mail", m_mail);
	query.bindValue(":fax", m_fax);
	query.bindValue(":phone", m_phone);
	query.bindValue(":id", m_id);
	if (!query.exec()) {
		qDebug() << "Department::update():  error";
		QString errorString = query.lastError().text();
		qDebug() << errorString;
		db.close();
		Log::create(session_id, "Department: update", m_id, errorString);
		return false;
	}
	db.close();
	Log::create(session_id, "Department: update", m_id);
	return true;
}

bool Department::deleteDepartment(int department_id, int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	QString idstr = QString::number(department_id);
	if (!query.exec("DELETE FROM departments WHERE id=\'" + idstr + "\'"))
	{
		QString errorString = query.lastError().text();
		qDebug() << errorString;
		Log::create(session_id, "Department: delete", department_id, errorString);
		return false;
	}
	else
	{
		Log::create(session_id, "Department: delete", department_id);
		return true;
	}
}

bool Department::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  departments (\
		id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		name     TEXT    UNIQUE NOT NULL,\
		country TEXT NOT NULL,\
		adress TEXT NOT NULL,\
		male     TEXT   ,\
		fax     TEXT   ,\
		phone    TEXT   ,\
		)"
		)))
	{
		qDebug() << "error creating Departments table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}
