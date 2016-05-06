#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
\file
\brief    Тип карты
(таблица record_langs)
\author   Ильина А.
\date     май 2016
*/


class RecordType {
private:
	int m_id;
	int m_record_id;
	int m_language_id;

};

