#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
\file
\brief    Регионы, ГПИ о которых предоставляет интернет-ресурс
(таблица site_regions)
\author   Ильина А.
\date     май 2016
*/


class SiteRegion {
private:
	int m_id;
	int m_site_id;
	int m_region_id;

};

