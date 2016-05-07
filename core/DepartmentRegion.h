#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "Database.h"
#include "Log.h"
#include <QSqlError>

/*!
\file
\brief    Регионы, ГП-информацию о которых поставляют ведомства
(таблица department_regions)
\author   Ильина А.
\date     май 2016
*/


class DepartmentRegion {
private:
	int m_department_id;
	int m_region_id;
public:
	
	DepartmentRegion(int department_id, int region_id);
	
	~DepartmentRegion();
	
	/*! Записывает в базу данных информацию
	о паре department_id - region_id
	\param int session_id - id текущей сессии
	*/
	void insertIntoDatabase(int session_id = Database::currentSessionId());
};

