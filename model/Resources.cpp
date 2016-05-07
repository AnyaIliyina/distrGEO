#include "Resources.h"
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


Resources::~Resources() {};

Resources::Resources() {
};

int Resources::columnCount() const {
	return 6;
};

void Resources::removeChild(BaseItem* child) {
	if (!m_children.contains(child))
		return;

	Resources* geodata = dynamic_cast<Resources*>(child);
	if (geodata == NULL)
		return;

		//Geodata_record::deleteRecord(geodata->m_id);
	m_children.removeOne(child);
};

QVariant Resources::data(int column, int role) const{
	if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTipRole) {
		if (column == 0)
			return m_id;
		if (column == 1)
			return m_name;
		if (column == 2)
			return m_url;
		if (column == 3)
			return m_language;
		if (column == 4)
			return m_gpi;
		if (column == 5)
			return m_comment;
		
	}

	if (role == Qt::UserRole) {
		
		return m_id;
	}

	return QVariant();
};

bool Resources::setData(int column, const QVariant& value, int role) {
	qDebug() << "setData Resources";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_id = value.toInt();
		if (column == 1)
			m_name = value.toString();
		if (column == 2)
			m_url = value.toString();
		if (column == 3)
			m_language = value.toString();
		if (column == 4)
			m_gpi = value.toString();
		if (column == 5)
			m_comment= value.toString();
		
		}
	
	return true;
};

QVariant Resources::headerData(int section, int role) const {
	
	if (role == Qt::DisplayRole) {
		if (section == 0)
			return ("ID");
		if (section == 1)
			return "Название ресурса";
		if (section == 2)
			return "Адрес интернет ресурса (ULR)";
		if (section == 3)
			return "Язык/языки сайта";
		if (section == 4)
			return "Виды ГПИ, предоставляемые на сайте";
		if (section == 5)
			return "Комментарии";
	
	}

	return QVariant();
};

bool Resources::isValid() const {
	if (m_language.isNull() || m_language.isEmpty())
		return false;
	if (m_name.isNull() || m_name.isEmpty())
		return false;
	if (m_gpi.isNull() || m_gpi.isEmpty())
		return false;
	
	
	return true;
};

bool Resources::isNew() const {
	return m_id == 0;
};

bool Resources::hasChildren() const {
	return false;
};

bool Resources::save() {

	//if (m_comment == NULL)
	//	m_comment = " ";
	//if (m_url == NULL)
	//	m_url = " ";
	//	getSiteId();
	//	getFormatId();
	//getScaleId();
	//getStateId();
	//if (m_id == 0) {
	//	//Создание
	//	Geodata_record* ngdr = new Geodata_record(m_site_id, m_format_id, m_place_name,  Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	qDebug() << ngdr->insertIntoDatabase();
	//	m_id = ngdr->id();
	//	delete ngdr;


	//}
	//else {
	//	// Изменение 
	//	Geodata_record *ngdr = new Geodata_record( m_site_id, m_format_id, m_place_name, Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	ngdr->setRecordId(m_id);
	//	ngdr->updateRecord();
	//	m_id = ngdr->id();
	//	delete ngdr;
	//}

	return true;
};

bool Resources::cancel() {
	if (isNew())
		return true;

	//QSqlDatabase db = Database::database();
	//QSqlQuery query(db);
	//query.prepare(
	//	"SELECT record_id, place_name, site_name,  format_name, description, state_name,  date, type_name, geodata_records.url, geodata_records.comment\
	//	FROM geodata_records\
	//	JOIN sites ON geodata_records.site_id=sites.site_id\
	//	JOIN formats ON geodata_records.format_id=formats.format_id\
	//	JOIN scales ON scales.scale_id=geodata_records.scale_id\
	//	JOIN states ON states.state_id=geodata_records.state_id\
	//	JOIN sessions ON sessions.session_id=geodata_records.session_id\
	//	JOIN users ON sessions.user_id=users.user_id\
	//	JOIN usertypes ON users.type_id=usertypes.type_id\
	//	WHERE record_id = :id "
	//);
	//query.bindValue(":id", m_id);

	//// Добавить ошибку
	//query.exec();
	//query.next();

	//m_name=query.value(1).toString();
	//m_url= query.value(2).toString();
	//m_language = query.value(3).toString();
	//m_gpi = query.value(4).toString();
	//m_comment = query.value(5).toString();

	return true;
};

QList<BaseItem*> Resources::loadItemsFromDb() {
	qDebug() << "loadItemsFromDb Resources";
	QList<BaseItem*> list;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);

	//if (!query.exec(
	//	"SELECT record_id, place_name, site_name,  format_name, description, state_name,  date, type_name, geodata_records.url, geodata_records.comment\
	//	FROM geodata_records\
	//	JOIN sites ON geodata_records.site_id=sites.site_id\
	//	JOIN formats ON geodata_records.format_id=formats.format_id\
	//	JOIN scales ON scales.scale_id=geodata_records.scale_id\
	//	JOIN states ON states.state_id=geodata_records.state_id\
	//	JOIN sessions ON sessions.session_id=geodata_records.session_id\
	//	JOIN users ON sessions.user_id=users.user_id\
	//	JOIN usertypes ON users.type_id=usertypes.type_id"
	//	))
	//{
	//	qDebug() << "ERRRRRRORRRR";
	//	qDebug() << query.lastError().text();
	//}

	//while (query.next()) {
	//	Resources* geo = new Resources();
	//	geo->m_id = query.value(0).toInt(); // id
	//	geo->m_name = query.value(1).toString();
	//	geo->m_url= query.value(2).toString(); // 
	//	geo->m_language = query.value(3).toString();
	//	geo->m_gpi = query.value(4).toString();
	//	geo->m_comment = query.value(5).toString();
	//	list << geo;

	//}

	return list;
};


