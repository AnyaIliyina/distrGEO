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


class Format: public QObject {
	Q_OBJECT
private:
	int m_format_id;
	QString m_format_name;
	
public:
	/*!
	Возвращает название формата
	\return QString& format_name - название формата
	*/
	const QString& format_name() const;

	/*!
	Возвращает id формата
	\return int format_id - id формата
	*/
	static int format_id(QString format_name);
	
	/*!
	Создает формат с заданным названием
	\param const QString &format_name - название создаваемого формата
	*/
	Format(const QString& format_name);
	
	/*!
	Конструирует объект, используя информацию в базе
	\param int formatId- id формата
	*/
	Format(int id);
	
	~Format();
	
	/*!
	Записывает информацию о формате в таблицу БД "formats"
	\return true - если информация записана
	*/
	bool insertIntoDatabase();

	/*!
	Записывает в базу данных список форматов
	\param QStringList formatNames - список названий форматов
	\return true - форматы записаны в БД
	\return false - возникли ошибки*/
	static bool insert(QStringList formatNames);
	
	/*!
	Создает таблицу "formats" в базе.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "formats" начальными значениями
	\return true - если записи успешно созданы
	*/
	static bool completeTable();

	/*!
	Возращает список форматов
	\return QStringList listFormat - список названий форматов
	*/
	static QStringList getFormatNames();
};
