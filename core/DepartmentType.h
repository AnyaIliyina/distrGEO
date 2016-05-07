#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
\file
\brief    Тип ГПИ, предоставляемой ведомством
(таблица department_types)
\author   Ильина А.
\date     май 2016
*/

class DepartmentType {
private:
	int m_id;
	int m_department_id;
	int m_type_id;

};

