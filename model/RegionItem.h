#pragma once

#include "Base_item.h"
#include "Region.h"

/*!

\file
\brief	Наследник Item_model
\author Ильина А.
\date май 2016

*/

class RegionItem : public BaseItem
{
public:
	int id=0;
	virtual ~RegionItem();
	RegionItem();

	/*!
	Возвращает количество колонок
	\return int - количество колонок
	*/
	int columnCount() const Q_DECL_OVERRIDE;

	void removeChild(BaseItem* child) Q_DECL_OVERRIDE;

	QVariant data(int column, int role) const Q_DECL_OVERRIDE;

	bool setData(int column, const QVariant& value, int role);
	QVariant headerData(int section, int role) const Q_DECL_OVERRIDE;
	
	bool isValid() const Q_DECL_OVERRIDE;
	bool isNew() const Q_DECL_OVERRIDE;
	//bool hasChildren() const Q_DECL_OVERRIDE;

	bool save() Q_DECL_OVERRIDE;
	bool cancel() Q_DECL_OVERRIDE;

	QList<BaseItem*> loadItemsFromDb() Q_DECL_OVERRIDE;

private:

	int m_id=0;
	int m_parent_id = 0;
	QString m_name;
	QString m_comment;
	/*QString m_all1;
	QString m_all;*/
	int m_type = 0;
	RegionItem* itemFromRegion(Region* region);
	
	/*! Ищет в списке list дочерние элементы (рекурсивно)	*/
	RegionItem* findChildren(QList<RegionItem*>list);
};