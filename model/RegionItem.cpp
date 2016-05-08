#include "RegionItem.h"


RegionItem::~RegionItem()
{
}

RegionItem::RegionItem()
{
}

int RegionItem::columnCount() const {
	return 1;
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


bool RegionItem::setData(int column, const QVariant& value, int role)
{
	qDebug() << "setData Regions";
	if (value.isNull() || value.toString().isEmpty())
		return false;

	if (role == Qt::EditRole) {
		if (column == 0)
			m_name = value.toString();
	}
}

RegionItem::RegionItem(Region* region)
{
	m_id = region->id();
	m_parent_id = region->parent_id();
	m_name = region->name();
	m_comment = region->comment();
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
	QList<RegionItem*> list;
	int id = 1;
	Region* region = new Region(id);
	while (region->name() != "")
	{
		RegionItem *item = new RegionItem(region);
		list << item;		
		delete region;
		region = new Region(++id);
	}
	
	QList<BaseItem*> finalList;
	for (int i = 0; i < list.count(); i++)
	{
		if (list.at(i)->m_parent_id == 0)
		{
			finalList << list.at(i);
			qDebug() << list.at(i)->m_id;
		}
		
	}

	return finalList;
}


QVariant RegionItem::headerData(int section, int role) const {

	if (role == Qt::DisplayRole) {
		if (section == 0)
			return ("Регионы");
		
	}

	return QVariant();
};

