#include "Resources.h"
#include "Database.h"
#include "State.h"
#include "Site.h"
#include "Language.h"
#include "GeodataType.h"
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

	Resources* resource = dynamic_cast<Resources*>(child);
	if (resource == NULL)
		return;

		Site::deleteRecord(resource->m_id);
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
			if (Site::urlFromString(value.toString()))
			{
				m_url = value.toString();
			}
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
			return "Адрес интернет ресурса (URL)";
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

	
	//	getSiteId();
	//	getFormatId();
	//getScaleId();
	//getStateId();
	if (m_id == 0) {
		//Создание
		Site* ns = new Site(m_url, m_name,1, m_comment );
		qDebug() << ns->insertIntoDatabase();
		m_id = ns->id();
		delete ns;


	}
	else {
		// Изменение 
		Site *ns = new Site(m_url, m_name, 1, m_comment);
		ns->setId(m_id);
		/*ns->updateRecord();
		m_id = ngdr->id();
		delete ngdr;*/
	}

	return true;
};

bool Resources::cancel() {
	if (isNew())
		return true;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare(" SELECT id, name, url, comment FROM sites WHERE id=:id");
	query.bindValue(":id", m_id);
	if (!query.exec())
	{
		qDebug() << "ERRRRRRORRRR";
		qDebug() << query.lastError().text();
	}
	query.next();
	m_name = query.value(1).toString();
	m_url = query.value(2).toString();
	m_language = Language::getList(m_id).join(", ");
	m_gpi = GeodataType::getList(m_id).join(", ");
	m_comment = query.value(3).toString();
	return true;
}
	
	


QList<BaseItem*> Resources::loadItemsFromDb() {
	qDebug() << "loadItemsFromDb Resources";
	QList<BaseItem*> list;

	QSqlDatabase db = Database::database();
	QSqlQuery query(db);

	if (!query.exec(" SELECT id, name, url, comment FROM sites"))
	{
		qDebug() << "ERRRRRRORRRR";
		qDebug() << query.lastError().text();
	}
	while (query.next())
	{
		Resources *res = new Resources();
		res->m_id = query.value(0).toInt();
		res->m_name = query.value(1).toString();
		res->m_url = query.value(2).toString();
		res->m_language = Language::getList(res->m_id).join(", ");
		res->m_gpi = GeodataType::getList(res->m_id).join(", ");
		res->m_comment = query.value(3).toString();
		list << res;
	}
	return list;
};
	



