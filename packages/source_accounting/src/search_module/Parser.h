#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QMap>
#include "Session.h"
#include "State.h"
#include "Site.h"
#include "Geodata_record.h"
#include "Database.h"

#define PAGE_NOT_AVAILABLE -2;
#define ERROR_INSERTING_INTO_DB -1;
#define SUCCEEDED 0;
/*!
\file
\brief 
*/

/*!
*  \brief Базовый класс для ParserGisLub, ParserGeofabrik
*  \details
*  \author    Ильина А.
*  \date      март 2016
*/
class  Parser : public QObject {
Q_OBJECT
public:
	/*!
	Отправляет get-запрос на сайт m_url, ищет в ответе сведенья об источниках ГПИ, формирует и заносит в БД
	записи Geodata_record.
	\param session_id - id сессии поиска;
	\param site_id - id сайта gis-lab.info;
	\return 0 - без ошибок;
	\return -2 - страница недоступна;
	\return -1 - ошибка при записи в БД;
	*/
	virtual int parse(int site_id) = 0;
	
	/*!
	Возвращает url страницы, с которой работает парсер
	\return const QString& url*/
	const QString& url();

protected:
	/*!
	Отправляет get-запрос на m_url
	\return QByteArray* - ответ сервера;
	\return nullptr - возникли ошибки;*/
	QByteArray* getReply();

	/*!
	Отправляет get-запрос на адрес url
	\param const QString& url - адрес
	\return QByteArray* - ответ сервера;
	\return nullptr - возникли ошибки;*/
	QByteArray* getReply(const QString& url);
	
	/*! Устанавливает значение m_url
	\param const QString& url - новое значение m_url*/
	void setUrl(const QString& url);

	int m_session_id = Database::smSessionId();

private:
	QString m_url;
	
};
