#pragma once
/*!
\file
\brief
*/
#include "Parser.h"
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QDebug>


/*!
*  \brief Получает и обрабатывает данные с сайта http://beryllium.gis-lab.info/project/osmshp
*  \details Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует и заносит в БД
записи Geodata_record.
*  \author    Ильина А.
*  \date     апрель 2016
*/

class  ParserGisLub : public Parser {
	Q_OBJECT
public:
	/*!
	Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует и заносит в БД
	записи Geodata_record.
	\param session_id - id сессии поиска;
	\param site_id - id сайта gis-lab.info;
	\return 0 - без ошибок;
	\return -2 - страница недоступна;
	\return -1 - ошибка при записи в БД;
	*/
	int parse(int site_id);
	
	ParserGisLub();
	~ParserGisLub();

private:
	/*!
	Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца
	\param QByteArray& ba - исходный текст
	*/
	void separateTableBody(QByteArray& ba);

	/*!
	Просматривает содержимое таблицы. По мере нахождения 
	заносит в запись Geodata_record информацию об актуальности,
	названии местности и адресе. Сохраняет полученную запись в БД. 
	\param QByteArray& content - содержимое таблицы;
	\param Geodata_record* record - запись;
	\return -1 - ошибка при записи в базу;
	\return 0 - без ошибок*/
	int parseTable(QByteArray& content, Geodata_record* record);
};
