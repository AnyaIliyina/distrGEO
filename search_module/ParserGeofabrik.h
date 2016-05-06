#pragma once
/*!
\file
\brief
*/
#include "Parser.h"
#include <QStack>


/*!
*  \brief Получает и обрабатывает данные с сайта ??
*  \details Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует
записи Geodata_record.
*  \author    Ильина А.
*  \date     апрель 2016
*/

class  ParserGeofabrik : public Parser {
	Q_OBJECT

public:
	/*!
	Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует и заносит в БД
	записи Geodata_record.
	\param site_id - id сайта gis-lab.info;
	\return 0 - без ошибок;
	\куегкт -1 - ошибка при записи в БД
	\return -2 - страница недоступна/ неверный адрес;
	*/
	int parse(int site_id);

	ParserGeofabrik();
	~ParserGeofabrik();

private:
	int m_site_id;						// id сайта

	QStack<QString> m_pagesToParse;		// стек для записи адресов, на которых нужно провести поиск

	QString m_urlPrefix;				// "дополнение" адресов, найденных в таблице, до полного адреса
	
	/*! Устанавливает необходимое значение m_urlPrefix в зависимости
	от адреса страницы, на который в данный момент ведется поиск
	\param const QString& currUrl - адрес страницы, на который	ведется поиск*/
	void setUrlPrefix(const QString& currUrl);
	
	/*!
	Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца.
	\param QByteArray& ba - исходный текст
	*/
	bool separateTable(QByteArray& content);

	/*!
	Просматривает содержимое таблицы, создает и заносит в базу записи Geodata_record.
	Адреса добавляет в стек m_pagesToParse.
	\param QByteArray& content - содержимое таблицы;
	\bool isIndex - true для таблицы на начальной странице, false - для остальных
	\return 0 -  не возникло ошибок*/
	int parseTable(QByteArray& content, bool isIndex = false);


	/*! Возвращает новую запись Geodata_record* с установленными
	значениями	site_id, state_id, session_id
	\return Geodata_record* record - новая запись*/
	Geodata_record* recordPrepared();

	QStringRef translate(const QString& text);
};
