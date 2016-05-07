#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
\file
\brief    Типы ГПИ, предоставляемой интернет-ресурсом
(таблица syte_types)
\author   Ильина А.
\date     май 2016
*/


class RecordType {
private:
	int m_id;
	int m_site_id;
	int m_type_id;

};

