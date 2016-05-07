#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
\file
\brief    Регионы, ГПИ для которых поставляют ведомства
(таблица department_regions)
\author   Ильина А.
\date     май 2016
*/


class DepartmentRegion {
private:
	int m_id;
	int m_department_id;
	int m_region_id;
public:

};

