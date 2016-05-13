#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "Database.h"
#include "Log.h"

/*!
\file
\brief    Регионы, ГПИ о которых предоставляет интернет-ресурс
(таблица site_regions)
\author   Ильина А.
\date     май 2016
*/


class SiteRegion {
private:
	int m_site_id;
	int m_region_id;
public:	
	/*! Конструктор. Создает пару site_id -  region_id.
	\param int site_id - id интернет-ресурса
	\param int region_id - id региона*/
	SiteRegion(int site_id, int region_id);

	/*! Деструктор*/
	~SiteRegion();

	/*! Записывает в базу данных информацию о паре site_id - region_id
	*/
	void insertIntoDatabase(int session_id = Database::currentSessionId());


	/*! Возвращает список интернет-ресурсов,
	предоставляющих информацию о регионе
	\param int region_id - id региона
	\return QList<int>siteIds - список id интернет-ресурсов*/
	static QList<int>sitesByRegion(int region_id);

	/*! Возвращает список регионов, информацией о
	которых располагает интернет-ресурс
	\param int site_id - id интернет-ресурса
	\return QList<int> regionIds - список из id регионов*/
	static QList<int>regionsBySite(int site_id);

	///*! Удаляет из базы все пары, в которых упоминается регион region_id
	//\param int region_id - id региона
	//\param int language_id - id языка*/
	//static void deleteByRegion(int region_id);

	///*! Удаляет из базы все пары, в которых упоминается
	//интернет-ресурс site_id
	//\param int site_id - id интернет-ресурса*/
	//static void deleteBySite(int site_id);

	/*! Удаляет из базы запись
	*/
	static void deleteRecord(int site_id, int region_id, int session_id = Database::currentSessionId());

	/*! Создает таблицу site_regions*/
	static bool createTable();
};

