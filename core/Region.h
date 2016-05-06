#pragma once

#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>


/*!
	\file
	\brief    Представляет сущность Формат
(таблица formats)
	\author   Козырева О.
	\date     15 март 2016
*/


class Region: public QObject {
	Q_OBJECT
private:
	int m_format_id;
	QString m_format_name;
	
public:
	
};
