#include "Files.h"
#include "Database.h"

#include <QBrush>
#include <QDebug>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


Files::~Files() {};

Files::Files() {
};

int Files::columnCount() const {
	return 4;
};

void Files::removeChild(BaseItem* child) {
	if (!m_children.contains(child))
		return;

	Files* geodata = dynamic_cast<Files*>(child);
	if (geodata == NULL)
		return;

		//Geodata_record::deleteRecord(geodata->m_id);
	m_children.removeOne(child);
};

QVariant Files::data(int column, int role) const{
	if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTipRole) {
		if (column == 0)
			return m_id;
		if (column == 1)
			return m_name;
		if (column == 2)
			return m_ftype;
		if (column == 3)
			return m_date;	
	}

	if (role == Qt::UserRole) {
		
		return m_id;
	}

	/*if (role == Qt::BackgroundRole) {
		QBrush brush(Qt::cyan);
		return brush;
	}

	if (role == Qt::DecorationRole && !isValid()) {
		QPixmap pixmap(":/./images/error_small.png");
		if (column == 0)
			if (m_code.isNull() || m_code.isEmpty())
				return pixmap;
		if (column == 1)
			if (m_name.isNull() || m_name.isEmpty())
				return pixmap;
	}*/
	return QVariant();
};

bool Files::setData(int column, const QVariant& value, int role) {
	qDebug() << "setData Files";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_id=value.toInt();
		if (column == 1)
			m_name=value.toString();
		if (column == 2)
			m_ftype = value.toString();
		if (column == 3)
			m_date= value.toString();
		}
	
	return true;
};

QVariant Files::headerData(int section, int role) const {
	
	if (role == Qt::DisplayRole) {
		if(section==0)
			return ("ID");
		if (section == 1) 
			return "Название";
		if (section == 2)
			return "Расширение";
		if (section == 3)
			return "Дата";
	}

	return QVariant();
};

bool Files::isValid() const {
	
	if (m_name.isNull() || m_name.isEmpty())
		return false;
	if (m_ftype.isNull() || m_ftype.isEmpty())
		return false;
		
	return true;
};

bool Files::isNew() const {
	return m_id == 0;
};

bool Files::hasChildren() const {
	return false;
};

bool Files::save() {

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
	//	Files_record* ngdr = new Files_record(m_site_id, m_format_id, m_place_name,  Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	qDebug() << ngdr->insertIntoDatabase();
	//	m_id = ngdr->id();
	//	delete ngdr;


	//}
	//else {
	//	// Изменение 
	//	Files_record *ngdr = new Files_record( m_site_id, m_format_id, m_place_name, Database::currentSessionId(), m_state_id, m_scale_id, m_url, m_comment );
	//	ngdr->setRecordId(m_id);
	//	ngdr->updateRecord();
	//	m_id = ngdr->id();
	//	delete ngdr;
	//}

	return true;
};

bool Files::cancel() {
	if (isNew())
		return true;

	//QSqlDatabase db = Database::database();
	//QSqlQuery query(db);
	//query.prepare(
	//	"SELECT record_id, place_name, site_name,  format_name, description, state_name,  date, type_name, Files_records.url, Files_records.comment\
	//	FROM Files_records\
	//	JOIN sites ON Files_records.site_id=sites.site_id\
	//	JOIN formats ON Files_records.format_id=formats.format_id\
	//	JOIN scales ON scales.scale_id=Files_records.scale_id\
	//	JOIN states ON states.state_id=Files_records.state_id\
	//	JOIN sessions ON sessions.session_id=Files_records.session_id\
	//	JOIN users ON sessions.user_id=users.user_id\
	//	JOIN usertypes ON users.type_id=usertypes.type_id\
	//	WHERE record_id = :id "
	//);
	//query.bindValue(":id", m_id);

	//// Добавить ошибку
	//query.exec();
	//query.next();

	//m_place_name=query.value(1).toString();
	//m_site_name= query.value(2).toString();
	//m_format_name = query.value(3).toString();
	//m_description = query.value(4).toString();
	//m_state_name = query.value(5).toString();
	//m_date= QDateTime::fromTime_t(query.value(6).toInt()).toString("dd.MM.yy");
	//m_user_type = query.value(7).toString();
	//m_url = query.value(8).toString();
	//m_comment = query.value(9).toString();
	////m_all = m_place_name + m_site_name + m_format_name;
	
	return true;
};

QList<BaseItem*> Files::loadItemsFromDb(QVariant id) {
	/*qDebug() << "loadItemsFromDb Files";
	QList<BaseItem*> list;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);

	if (!query.exec(
		"SELECT Files_records.id, place_name, sites.name,  formats.name, scales.description, states.name,  sessions.date, type_name, Files_records.url, geodata_records.comment\
		FROM geodata_records\
		JOIN sites ON geodata_records.site_id=sites.id\
		JOIN formats ON geodata_records.format_id=formats.id\
		JOIN scales ON scales.id=geodata_records.id\
		JOIN states ON states.id=geodata_records.id\
		JOIN sessions ON sessions.id=geodata_records.id\
		JOIN users ON sessions.user_id=users.id\
		JOIN usertypes ON users.type_id=usertypes.id"
		))
	{
		qDebug() << "ERRRRRRORRRR";
		qDebug() << query.lastError().text();
	}
*/
	/*while (query.next()) {*/
	//	Geodata* geo = new Geodata();
	//	geo->m_id = query.value(0).toInt(); // id
	//	geo->m_place_name = query.value(1).toString();
	//	geo->m_site_name = query.value(2).toString(); // 
	//	geo->m_format_name = query.value(3).toString();
	//	geo->m_description = query.value(4).toString();
	//	geo->m_state_name = query.value(5).toString();
	//	geo->m_date =QDateTime::fromTime_t(query.value(6).toInt()).toString("dd.MM.yy");
	//	geo->m_user_type = query.value(7).toString();
	//	geo->m_url = query.value(8).toString();
	//	geo->m_comment = query.value(9).toString();
	//	/*m_all1 = geo->m_place_name + geo->m_site_name;
	//	geo->m_all= m_all1 + geo->m_format_name;*/
	//	list << geo;

	//}

	return QList<BaseItem*>();
};

