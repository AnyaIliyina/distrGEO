#include "SM_Session.h"
#include "Parser.h"
#include <QDebug>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


/*!
\file
\brief 
*/

const QString & Parser::url()
{
	return m_url;
}




void Parser::setUrl(const QString & url)
{
	m_url = url;
}


QByteArray * Parser::getReply()
{
	return getReply(m_url);
}


QByteArray * Parser::getReply(const QString & url)
{
	QEventLoop eventLoop;
	QNetworkAccessManager mgr;
	QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
		// eventLoop после exec() заблокирует все действия - до тех пор пока ответ QNetworkReply не получен
	QUrl myUrl(url);
	QNetworkRequest request(myUrl);
	QNetworkReply *reply = mgr.get(request);
	eventLoop.exec();
	QByteArray *result;
	if (reply->error() == QNetworkReply::NoError)		
		result = new QByteArray(reply->readAll());		// успех		
	else
		result = new QByteArray(nullptr);				// ошибка
		
	delete reply;
	return result;
}
