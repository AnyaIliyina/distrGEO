#include "DepartmentRegion.h"

DepartmentRegion::DepartmentRegion(int department_id, int region_id):
	m_department_id(department_id), m_region_id(region_id)
{
	m_department_id = department_id;
	m_region_id = region_id;
}

DepartmentRegion::~DepartmentRegion()
{
}

void DepartmentRegion::insertIntoDatabase(int session_id)
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO department_regions( department_id, region_id)\
		VALUES (?, ?)");
	query.addBindValue(m_department_id);
	query.addBindValue(m_region_id);
	if (!query.exec()) {
		qDebug() << "departmentRegion::insertIntoDatabase():  error ";
		QString errorString = query.lastError().text();
		qDebug() << errorString;
		db.close();
		Log::create(session_id, "DepartmentRegion: insert", 0, errorString);
	}
	else {
		int id = query.lastInsertId().toInt();
		db.close();
		Log::create(session_id, "DepartmentRegion: insert", id);
	}
}

bool DepartmentRegion::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.exec("PRAGMA foreign_keys = ON;");
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  department_regions (\
		department_id INTEGER,		\
		region_id INTEGER,   \
		FOREIGN KEY(department_id) REFERENCES departments(id) ON DELETE CASCADE ON UPDATE CASCADE,\
		FOREIGN KEY(region_id) REFERENCES regions(id) ON DELETE CASCADE ON UPDATE CASCADE\
		)"
		)))
	{
		qDebug() << "error creating Department_regions table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	DepartmentRegion(1, 1).insertIntoDatabase();
	return true;
}
