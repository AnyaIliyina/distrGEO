#include "Departments.h"
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


Departments::~Departments() {};

Departments::Departments() {
};

int Departments::columnCount() const {
	return 9;
};

void Departments::removeChild(BaseItem* child) {
	if (!m_children.contains(child))
		return;

	Departments* department = dynamic_cast<Departments*>(child);
	if (department == NULL)
		return;

		//Geodata_record::deleteRecord(department->m_id);
	m_children.removeOne(child);
};

QVariant Departments::data(int column, int role) const{
	if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTipRole) {
		if (column == 0)
			return m_id;
		if (column == 1)
			return m_name;
		if (column == 2)
			return m_country;
		if (column == 3)
			return m_address;
		if (column == 4)
			return m_phone;
		if (column == 5)
			return m_fax;
		if (column == 6)
			return m_email;
		if (column == 7)
			return m_gpi;
		if (column == 8)
			return m_comment;
	
	}

	if (role == Qt::UserRole) {
		
		return m_id;
	}

	return QVariant();
};

bool Departments::setData(int column, const QVariant& value, int role) {
	qDebug() << "setData Departments";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_id=value.toInt();
		if (column == 1)
			m_name=value.toString();
		if (column == 2)
			m_country = value.toString();
		if (column == 3)
			m_address = value.toString();
		if (column == 4)
			m_phone= value.toString();
		if (column == 5)
			m_fax = value.toString();
		if (column == 6)
			m_email = value.toString();
		if (column == 7)
			m_gpi= value.toString();
		if (column == 8)
			m_comment= value.toString();
		
		}
	
	return true;
};

QVariant Departments::headerData(int section, int role) const {
	
	if (role == Qt::DisplayRole) {
		if(section==0)
			return ("ID");
		if (section == 1) 
			return "Наименование ведомства";
		if (section == 2)
			return "Страна";
		if (section == 3)
			return "Адрес";
		if (section == 4)
			return "Телефон";
		if (section == 5)
			return "Факс";
		if (section == 6)
			return "Адрес электронной почты";
		if (section == 7)
			return "Виды ГПИ, предоставляемые организацией";
		if (section == 8)
			return "Комментарии";
		
	}

	return QVariant();
};

bool Departments::isValid() const {
	if (m_country.isNull() || m_country.isEmpty())
		return false;
	if (m_name.isNull() || m_name.isEmpty())
		return false;
	if (m_address.isNull() || m_address.isEmpty())
		return false;
	if (m_fax.isNull() || m_fax.isEmpty())
		return false;
	if (m_gpi.isNull() || m_gpi.isEmpty())
		return false;
	if (m_url.isNull() || m_url.isEmpty())
		return false;

	
	return true;
};

bool Departments::isNew() const {
	return m_id == 0;
};

bool Departments::hasChildren() const {
	return false;
};

bool Departments::save() {

	//if (m_comment == NULL)
	//	m_comment = " ";
	//if (m_url == NULL)
	//	m_url = " ";
	//	
	//if (m_id == 0) {
	//	//Создание
	//	Geodata_record* ngdr = new Geodata_record(m_site_id, m_format_id, m_name,  Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	qDebug() << ngdr->insertIntoDatabase();
	//	m_id = ngdr->id();
	//	delete ngdr;


	//}
	//else {
	//	// Изменение 
	//	Geodata_record *ngdr = new Geodata_record( m_site_id, m_format_id, m_name, Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	ngdr->setRecordId(m_id);
	//	ngdr->updateRecord();
	//	m_id = ngdr->id();
	//	delete ngdr;
	//}

	return true;
};

bool Departments::cancel() {
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
	//m_country= query.value(2).toString();
	//m_address = query.value(3).toString();
	//m_phone = query.value(4).toString();
	//m_fax = query.value(5).toString();
	//m_email = query.value(6).toString();query.value(6).toString();
	//m_gpi = query.value(7).toString();
	//m_url = query.value(8).toString();
	//m_comment = query.value(9).toString();
	
	
	return true;
};

QList<BaseItem*> Departments::loadItemsFromDb() {
	qDebug() << "loadItemsFromDb Departments";
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
	//	Departments* geo = new Departments();
	//	geo->m_id = query.value(0).toInt(); // id
	//	geo->m_name = query.value(1).toString();
	//	geo->m_country = query.value(2).toString(); // 
	//	geo->m_address = query.value(3).toString();
	//	geo->m_phone = query.value(4).toString();
	//	geo->m_fax = query.value(5).toString();
	//	geo->m_email =query.value(6).toString();
	//	geo->m_gpi = query.value(7).toString();
	//	geo->m_url = query.value(8).toString();
	//	geo->m_comment = query.value(9).toString();
	//	/*m_all1 = geo->m_name + geo->m_country;
	//	geo->m_all= m_all1 + geo->m_address;*/
	//	list << geo;

	//}

	return list;
};



