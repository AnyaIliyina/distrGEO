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
	virtual int columnCount() const Q_DECL_OVERRIDE;

	//int rowCount() const Q_DECL_OVERRIDE;

	void removeChild(BaseItem* child) Q_DECL_OVERRIDE;

	virtual QVariant data(int column, int role) const Q_DECL_OVERRIDE;

	virtual bool setData(int column, const QVariant& value, int role);
	QVariant headerData(int section, int role) const Q_DECL_OVERRIDE;
	
	bool isValid() const Q_DECL_OVERRIDE;
	bool isNew() const Q_DECL_OVERRIDE;
	//bool hasChildren() const Q_DECL_OVERRIDE;

	bool save() Q_DECL_OVERRIDE;
	bool cancel() Q_DECL_OVERRIDE;

	virtual QList<BaseItem*> loadItemsFromDb(QVariant id = QVariant()) Q_DECL_OVERRIDE;

protected:

	int m_id=0;
	QString m_name;
	QString m_comment="";
	int m_type = 3;
};