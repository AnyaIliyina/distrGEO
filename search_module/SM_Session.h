#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include "Parser.h"

/*!
\file
\brief 
*/

/*! 
 *  \brief     Создает сессию для модуля поиска, запускает его работу.
 *  \details   Search Module session
 *  \author    Ильина А.
 *  \date      март 2016
 */

class SM_Session : public QObject {
Q_OBJECT
public:
	SM_Session();
	~SM_Session();
	
	/*!	Начинает сессию поиска	*/
	void start();

private:
	QList<Parser*> m_parserPool;
	QList<Site> m_sites;

	/*!
	Получает список непроверенных сайтов(со статусом 0); 
	если возможно, производит поиск ГПИ на этих сайтах
	*/
	void search();

	/*!
	Отправляет сигнал основному окну с целью поменять
	сообщение панели QStatusBar
	\param const QString &text - текст нового сообщения
	*/
	void setStatus(const QString &text);

	int parseIfNeeded(Parser *p);

signals:
	void signalStatusOffered(const QString &text);
};
