#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
	\file
	\brief    Язык интернет-ресурса
(таблица record_langs)
	\author   Ильина А.
	\date     май 2016
*/


class RecordLang{
private:
	int m_id;
	int m_record_id;
	int m_language_id;

};
