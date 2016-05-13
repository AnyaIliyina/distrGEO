#pragma once

#include "Base_item.h"
#include "RegionItem.h"

/*!

\file
\brief	Наследник Item_model
\author Ильина А.
\date май 2016

*/

class RegionItemChecked : public RegionItem
{

public:
	virtual ~RegionItemChecked();
	RegionItemChecked();
	QVariant data(int column, int role) const Q_DECL_OVERRIDE;
	int columnCount() const Q_DECL_OVERRIDE;
	bool setData(int column, const QVariant& value, int role) Q_DECL_OVERRIDE;
	QList<BaseItem*> loadItemsFromDb(QVariant id = QVariant()) Q_DECL_OVERRIDE;
	QVariant headerData(int section, int role) const Q_DECL_OVERRIDE;
	static QMap<int, RegionItemChecked*> getMap();
	void setChecked(bool checked);
	bool isCheckable() const Q_DECL_OVERRIDE;
private:
	bool m_checked=true;
	static QMap<int, RegionItemChecked*> map;
	
};