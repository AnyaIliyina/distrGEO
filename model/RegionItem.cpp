#include "RegionItem.h"


RegionItem::~RegionItem()
{
}

RegionItem::RegionItem()
{
}

int RegionItem::columnCount() const {
	return 2;
};

void RegionItem::removeChild(BaseItem* child) {
	if (!m_children.contains(child))
		return;

	RegionItem* region = dynamic_cast<RegionItem*>(child);
	if (region == NULL)
		return;

	Region::deleteRegion(region->m_id);
	m_children.removeOne(child);
};

QVariant RegionItem::data(int column, int role) const {
	if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::ToolTipRole)
	{
		if (column == 0)
		{
			return m_name;
		}


		return QVariant();
	}
}


RegionItem * RegionItem::itemFromRegion(Region * region)
{
	RegionItem* item = new RegionItem();
	item->m_id = region->id();
	item->m_parent_id = region->parent_id();
	item->m_name = region->name();
	item->m_comment = region->comment();
	return item;
}

bool RegionItem::setData(int column, const QVariant& value, int role) {
	qDebug() << "setData RegionItem";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_name = value.toString();
	}
}

RegionItem* RegionItem::findChildren(QList<RegionItem*> list)
{
	while (!list.isEmpty())
	{
		for (int i = 0; i < list.count(); i++)
		{

			if (list.at(i)->m_parent_id == m_id)
				appendChild(list.at(i));
		}
	}
	return this;
}


	
	

bool RegionItem::isValid() const
{
	if (m_name.isNull() || m_name.isEmpty())
			return false;
	return true;
}


bool RegionItem::isNew() const
{
	return m_id == 0;
};

bool RegionItem::save()
{

	if (isValid())
	{
		m_comment = "";
		//m_parent_id = 
		if (m_id == 0) {
			//Создание
		}
		else
		{
			// Изменение 
		}

		return true;
	}
}

bool RegionItem::cancel() { return true; }

QList<BaseItem*> RegionItem::loadItemsFromDb() {
	qDebug() << "loadItemsFromDb Regions";
	QList<BaseItem*> list;
	RegionItem* r = new RegionItem();
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare(
		"SELECT name\
		FROM regions\
	WHERE id = :id ");
	query.bindValue(":id", m_id);

	while (query.next()) {
		RegionItem* r = new RegionItem();
		r->m_id = id;
		r->m_name = query.value(0).toString();
		list << r;
	}
	/*Region* region = new Region(id);
	while (region->name() != "")
	{
		RegionItem *item = itemFromRegion(region);
		list << item;		
		delete region;
		region = new Region(++id);
	}*/
	/*qDebug() << "got list 1";
	QList<BaseItem*> finalList;
	for (int i = 0; i < list.count(); i++)
	{
		if (list.at(i)->m_parent_id == 0)
		{
			finalList << list.at(i);
			qDebug() << list.at(i)->m_id;
		}
		
	}*/

	return list;
}


QVariant RegionItem::headerData(int section, int role) const {

	if (role == Qt::DisplayRole) {
		if (section == 0)
			return ("Регионы");
		
	}

	return QVariant();
};

