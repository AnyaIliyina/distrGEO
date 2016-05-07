#include "SM_Session.h"
#include "Database.h"
#include "QStatusBar"
#include "Session.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Geodata_record.h"
#include "Site.h"

/*!
\file
\brief 
*/

SM_Session::SM_Session()
{
}

SM_Session::~SM_Session()
{
}

/*!
Начинает сессию поиска
*/
void SM_Session::start()
{
	Session::createSMsession();
	setStatus("Модуль поиска начал работу...");
	search();
}


/*!
Получает список непроверенных сайтов(со статусом 0);
Если возможно, производит поиск ГПИ на этих сайтах
*/
void SM_Session::search()
{
	// получить список сайтов (нуждающихся в проверке, со статусом 1):
	m_sites = Site::sitesByStatus(1);

	// создать все возможные парсеры:
	ParserGisLub *parserGL = new ParserGisLub();
	ParserGeofabrik *parserGeofabrik = new ParserGeofabrik();
	m_parserPool << parserGL << parserGeofabrik;

	// парсить:
	int result = 0;
	for (int i = 0; i < m_parserPool.count(); i++)
		result += parseIfNeeded(m_parserPool.at(i));

	// освободить память:
	for (int i = 0; i < m_parserPool.count(); i++)
		delete m_parserPool.at(i);

	// вывести результат поиска:
	if (result == 0)
		setStatus("Модуль поиска: все сайты проверены.");
	else
		setStatus("Модуль поиска завершил работу. Не все сайты проверены.");
}

/*!
Отправляет сигнал основному окну с целью поменять 
сообщение панели QStatusBar
\param const QString &text - текст нового сообщения
*/
void SM_Session::setStatus(const QString &text)
{
	emit signalStatusOffered(text);
}


int SM_Session::parseIfNeeded(Parser* p)
{
	int result = 0;
	for (int i = 0; i < m_sites.count(); i++)
	{
		Site site = m_sites.at(i);
		if (site.url().contains(p->url()))
		{
			result = p->parse(site.id());
			
			if (result == 0)
				Geodata_record::deleteOldSmRecords(site.id());
		}
	}
	return result;
}
