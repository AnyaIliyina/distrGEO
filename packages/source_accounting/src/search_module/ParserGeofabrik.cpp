#include "ParserGeofabrik.h"
#include "Geodata_record.h"
#include <QTextEdit>
#include <QXmlStreamReader>

/*!
\file
\brief 
*/

#define formatID_pbf 2
#define formatID_shape 1
#define formatID_bz2 3
#define stateID_actual 2
#define statusId_checked 2

int ParserGeofabrik::parse(int site_id)
{
	m_site_id = site_id;

	// Начальная страница:
	QByteArray *replyIndex = getReply();
	if (*replyIndex == "")
		return PAGE_NOT_AVAILABLE;
	separateTable(*replyIndex);
	parseTable(*replyIndex, true);

	// Остальные страницы:
	while (!m_pagesToParse.isEmpty())
	{
		QString currentPage = m_pagesToParse.pop();		
		setUrlPrefix(currentPage);
		
		qDebug() << "\n going to " << currentPage;
		QByteArray *reply = getReply(currentPage);

		if (*reply == "")	{
			qDebug() << "wrong address.";
			return PAGE_NOT_AVAILABLE;
		}
		if (!separateTable(*reply)) {
			qDebug() << "no subregions.";
			qDebug() << m_pagesToParse.length();
			continue;
		}
		if(parseTable(*reply)==-1)
			return ERROR_INSERTING_INTO_DB;
	}

	Site::setStatusId(site_id, statusId_checked);
	return SUCCEEDED;
}



ParserGeofabrik::ParserGeofabrik()
{
	setUrl("http://download.geofabrik.de/index.html");
}


ParserGeofabrik::~ParserGeofabrik()
{
}


void ParserGeofabrik::setUrlPrefix(const QString & currUrl)
{
	QUrl tempUrl(currUrl);
	m_urlPrefix = tempUrl.adjusted(QUrl::RemoveFilename).toString();
}


Geodata_record * ParserGeofabrik::recordPrepared()
{
	Geodata_record *record = new Geodata_record();
	record->setSessionId(m_session_id);
	record->setSiteId(m_site_id);
	record->setStateId(stateID_actual);
	return record;
}

int ParserGeofabrik::parseTable(QByteArray &content, bool isIndex)
{ 
	Geodata_record* record = recordPrepared();
	QXmlStreamReader xml(content);
	int counter = 0;
	QString temp;
	while (xml.readNextStartElement())			// в <table>	
	{
		while (xml.readNextStartElement())		// в <tr>
		{
			while (xml.readNextStartElement())	// в <td>
			{
				while (xml.readNextStartElement())	// в <a>
				{
					if (fmod(counter, 4) == 0)
					{
						temp = xml.attributes().at(0).value().toString();
						qDebug() << m_pagesToParse.length();
						if (isIndex)
							record->setUrl(QString("http://download.geofabrik.de").
								append(temp.right(temp.length() - 1)));
						else
							record->setUrl(m_urlPrefix +temp);
						qDebug() << record->url();
						m_pagesToParse.push(record->url());
											
					}
					int columnNumber = fmod(counter, 4);
					switch (columnNumber)
					{
					case 0:
						record->setPlacename(xml.readElementText()); break;
					case 1:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_pbf);
							if(!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					case 2:
						temp = xml.readElementText();
						if (temp != "[missing]") 
						{
							record->setFormateId(formatID_shape);
							if (!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					case 3:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_bz2);
							if (!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					}
					counter++;
				}
			}
		}
	}
	delete record;
	return SUCCEEDED;
}


QStringRef ParserGeofabrik::translate(const QString & text)
{
	return QStringRef();
}


bool ParserGeofabrik::separateTable(QByteArray& ba)
{
	// Проверить, есть ли таблица с подрегионами subregions
	if ( ba.indexOf("No sub regions are defined for this region") > -1 )
			return false;

	// Вырезать таблицу:
	const QString splitter1 = QString("<table id=\"subregions\">");
	int pos1 = ba.lastIndexOf(splitter1);

	const QString splitter2 = QString("</table>");
	int pos2 = ba.lastIndexOf(splitter2) + splitter2.length();

	ba = ba.mid(pos1, pos2 - pos1);

	// Удалеть фрагменты таблицы, приводящие к ошибкам чтения xml:
	const QString errorPronePart = QString("&nbsp");
	ba.remove(ba.indexOf(errorPronePart), errorPronePart.length()+1);
	ba.replace("<img src=\"/img/cross.png\">",			
		"<a href=\"no\">[missing]</a>");		// <img> - непарный тег, заменить
	
	return true;
}