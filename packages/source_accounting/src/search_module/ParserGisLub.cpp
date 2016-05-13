#include "ParserGisLub.h"
#include <QDebug>
#include <QTextEdit>
#include <QXmlStreamReader>
#include "Scale.h"
/*!
\file
\brief 
*/

#define stateID_actual 2
#define stateID_notActual 3
#define formatID_shape 1
#define statusId_checked 2


int ParserGisLub::parse(int site_id)
{
	QByteArray *reply = getReply();
	if (*reply == "")
		return PAGE_NOT_AVAILABLE;

	separateTableBody(*reply);

	Geodata_record *record = new Geodata_record();
	record->setFormateId(formatID_shape);
	record->setSiteId(site_id);
	record->setSessionId(m_session_id);

	int result = parseTable(*reply, record);
	if (result == 0)
		Site::setStatusId(site_id, statusId_checked);
	return result;	
}


int ParserGisLub::parseTable(QByteArray & content, Geodata_record * record)
{
	int counter = 0;
	QXmlStreamReader xml(content);
	while (xml.readNextStartElement())				// в <tbody>
	{
		if (xml.name() == "tr")
			while (xml.readNextStartElement())		// в <tr>
			{
				while (xml.readNextStartElement())	// в <td>
				{
					if (fmod(counter, 4) == 0)
						record->setUrl(QString("http://beryllium.gis-lab.info").
							append(xml.attributes().at(0).value()));
					QString buffer = xml.readElementText();
					if (fmod(counter, 4) == 0)
						record->setPlacename(buffer.simplified());
					if (fmod(counter - 1, 4) == 0)
					{
						record->setStateId(buffer.contains("Не") ?
							stateID_notActual : stateID_actual);
						qDebug() << record->url();
						if (!record->insertIntoDatabase())
							return ERROR_INSERTING_INTO_DB;
					}
					counter++;
				}
			}
	}
	delete record;
	return SUCCEEDED;
}


ParserGisLub::ParserGisLub()
{
	setUrl("http://beryllium.gis-lab.info/project/osmshp");
}



ParserGisLub::~ParserGisLub()
{
}


/*!
Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца
\param QByteArray& ba - исходный текст
*/
void ParserGisLub::separateTableBody(QByteArray& ba)
{
	const QString splitter1 = QString("<tbody>");
	int pos1 = ba.indexOf(splitter1);
	
	const QString splitter2 = QString("</tbody>");
	int pos2 = ba.indexOf(splitter2) + splitter2.length();
	
	if ((pos1==-1) || (pos2==-1))
		qDebug() << "ParserGisLub :: separateTableBody(QByteArray&) \
error:\n table not found";

	ba = ba.mid(pos1, pos2 - pos1);
}
