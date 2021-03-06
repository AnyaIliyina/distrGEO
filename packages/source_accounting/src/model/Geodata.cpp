#include "Geodata.h"
#include "Database.h"
#include "Geodata_record.h"
#include "State.h"
#include "Site.h"
#include "Format.h"
#include "Scale.h"
#include "State.h"
#include <QBrush>
#include <QDebug>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


Geodata::~Geodata() {};

Geodata::Geodata() {
};

int Geodata::columnCount() const {
	return 10;
};

void Geodata::removeChild(BaseItem* child) {
	if (!m_children.contains(child))
		return;

	Geodata* geodata = dynamic_cast<Geodata*>(child);
	if (geodata == NULL)
		return;

		Geodata_record::deleteRecord(geodata->m_id);
	m_children.removeOne(child);
};

QVariant Geodata::data(int column, int role) const{

	if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTipRole) {
		if (column == 0)
		{
			return m_id;
		}
		if (column == 1)
			return m_place_name;
		if (column == 2)
			return m_site_name;
		if (column == 3)
			return m_format_name;
		if (column == 4)
			return m_description;
		if (column == 5)
			return m_state_name;
		if (column == 6)
			return m_date;
		if (column == 7)
			return m_user_type;
		if (column == 8)
			return m_url;
		if (column == 9)
			return m_comment;
		
	}

	if (role == Qt::UserRole) {
		
		return m_id;
	}
	if (role == Qt::UserRole) {

		return m_id;
	}
	if (role == Qt::BackgroundRole) {
		QBrush brush(Qt::cyan);
		return brush;
	}

	// возвращает индикатор обязательного поля
	if (role == Qt::DecorationRole && !isValid()) {
		QPixmap pixmap(":/./images/error_small.png");
		if (column == 1)
			if (m_place_name.isNull() || m_place_name.isEmpty())
				return pixmap;
		if (column == 8)
			if (m_url.isNull() || m_url.isEmpty())
				return pixmap;
		
		if (column == 3)
			if (m_format_name.isNull() || m_format_name.isEmpty())
				return pixmap;
	}

	return QVariant();
};

bool Geodata::setData(int column, const QVariant& value, int role) {
	qDebug() << "setData Geodata";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_id = value.toInt();
		if (column == 1)
			m_place_name = value.toString();
		if (column == 2)
			m_site_name = value.toString();
		if (column == 3)
			m_format_name = value.toString();
		if (column == 4)
			m_description = value.toString();
		if (column == 5)
			m_state_name = value.toString();
		/*if (column == 6)
		m_date = value.toString();
		if (column == 7)
		m_user_type= value.toString();*/
		if (column == 8)
		{
			if (Site::urlFromString(value.toString()))
			{
				m_url = value.toString();
			}
		}
		if (column == 9)
			m_comment = value.toString();

	}
	return true;
};

QVariant Geodata::headerData(int section, int role) const {
	
	if (role == Qt::DisplayRole) {
		if (section == 0)
			return ("ID");
		if (section == 1)
			return "Название местности";
		if (section == 2)
			return "Сайт";
		if (section == 3)
			return "Формат";
		if (section == 4)
			return "Масштаб";
		if (section == 5)
			return "Статус";
		if (section == 6)
			return "Дата";
		if (section == 7)
			return "Пользователь";
		if (section == 8)
			return "URL";
		if (section == 9)
			return "Комментарии";
		
	}

	return QVariant();
};

bool Geodata::isValid() const {
	if (m_site_name.isNull() || m_site_name.isEmpty())
		return false;
	if (m_place_name.isNull() || m_place_name.isEmpty())
		return false;
	if (m_format_name.isNull() || m_format_name.isEmpty())
		return false;
	if (m_state_name.isNull() || m_state_name.isEmpty())
		return false;
	if (m_user_type.isNull() || m_user_type.isEmpty())
		return false;
	if (m_url.isNull() || m_url.isEmpty())
		return false;
	if (m_comment.isNull() || m_comment.isEmpty())
		return false;
	return true;
};

bool Geodata::isNew() const {
	return m_id == 0;
};

bool Geodata::hasChildren() const {
	return false;
};

bool Geodata::save() {

	if (m_comment == NULL)
		m_comment = " ";
	if (m_url == NULL)
		m_url = " ";
		getSiteId();
		getFormatId();
	getScaleId();
	getStateId();
	if (m_id == 0) {
		//Создание
		Geodata_record* ngdr = new Geodata_record(m_site_id, m_format_id, m_place_name,  Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
		qDebug() << ngdr->insertIntoDatabase();
		m_id = ngdr->id();
		delete ngdr;


	}
	else {
		// Изменение 
		Geodata_record *ngdr = new Geodata_record( m_site_id, m_format_id, m_place_name, Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
		ngdr->setRecordId(m_id);
		ngdr->updateRecord();
		m_id = ngdr->id();
		delete ngdr;
	}

	return true;
};

bool Geodata::cancel() {
	if (isNew())
		return true;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare(
		"SELECT geodata_records.id, geodata_records.place_name, sites.name, formats.name, scales.description, states.name, sessions.date, usertypes.name, geodata_records.url, geodata_records.comment\
		FROM geodata_records\
		JOIN sites ON geodata_records.site_id = sites.id\
		JOIN formats ON geodata_records.format_id = formats.id\
		JOIN scales ON scales.id = geodata_records.scale_id\
		JOIN states ON states.id = geodata_records.state_id\
		JOIN sessions ON sessions.id = geodata_records.session_id\
		JOIN users ON sessions.user_id = users.id\
		JOIN usertypes ON users.type_id = usertypes.id\
		WHERE record_id = :id "
	);
	query.bindValue(":id", m_id);

	// Добавить ошибку
	query.exec();
	query.next();

	m_place_name=query.value(1).toString();
	m_site_name= query.value(2).toString();
	m_format_name = query.value(3).toString();
	m_description = query.value(4).toString();
	m_state_name = query.value(5).toString();
	m_date= QDateTime::fromTime_t(query.value(6).toInt()).toString("dd.MM.yy");
	m_user_type = query.value(7).toString();
	m_url = query.value(8).toString();
	m_comment = query.value(9).toString();
	//m_all = m_place_name + m_site_name + m_format_name;
	
	return true;
};

QList<BaseItem*> Geodata::loadItemsFromDb(QVariant id) {
	qDebug() << "loadItemsFromDb Geodata";
	QList<BaseItem*> list;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);

	if (!query.exec(
		"SELECT geodata_records.id, geodata_records.place_name, sites.name, formats.name, scales.description, states.name, sessions.date, usertypes.name, geodata_records.url, geodata_records.comment\
		FROM geodata_records\
		JOIN sites ON geodata_records.site_id = sites.id\
		JOIN formats ON geodata_records.format_id = formats.id\
		JOIN scales ON scales.id = geodata_records.scale_id\
		JOIN states ON states.id = geodata_records.state_id\
		JOIN sessions ON sessions.id = geodata_records.session_id\
		JOIN users ON sessions.user_id = users.id\
		JOIN usertypes ON users.type_id = usertypes.id"
		))
	{
		qDebug() << "ERRRRRRORRRR";
		qDebug() << query.lastError().text();
	}

	while (query.next()) {
		Geodata* geo = new Geodata();
		geo->m_id = query.value(0).toInt(); // id
		geo->m_place_name = query.value(1).toString();
		geo->m_site_name = query.value(2).toString(); // 
		geo->m_format_name = query.value(3).toString();
		geo->m_description = query.value(4).toString();
		geo->m_state_name = query.value(5).toString();
		geo->m_date =QDateTime::fromTime_t(query.value(6).toInt()).toString("dd.MM.yy");
		geo->m_user_type = query.value(7).toString();
		geo->m_url = query.value(8).toString();
		geo->m_comment = query.value(9).toString();

		list << geo;

	}

	return list;
};

void Geodata::getFormatId()
{
	qDebug() << "getting FormatId...";
	m_format_id = Format::id(m_format_name);
	qDebug() << "m_formatId = " << m_format_id;
}

void Geodata::getSiteId()
{
	qDebug() << "getting SiteId...";
	m_site_id =Site::site_id(m_site_name);
	qDebug() << m_site_id; 

}

void Geodata::getScaleId()
{
	m_scale_id = Scale::scale_id(m_description);
}

void Geodata::getStateId()
{
	m_state_id = State::state_id(m_state_name);
}


