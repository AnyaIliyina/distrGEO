#pragma once

#include "Base_item.h"

/*!

\file
\brief	Наследник Item_model
\author Козырева О.А.
\date Апрель 2016

*/

class Geodata : public BaseItem
{
public:
	int id=0;
	virtual ~Geodata();
	Geodata();

	/*!
	Возвращает количество колонок
	\return int - количество колонок
	*/
	int columnCount() const Q_DECL_OVERRIDE;

	void removeChild(BaseItem* child) Q_DECL_OVERRIDE;

	QVariant data(int column, int role) const Q_DECL_OVERRIDE;

	bool setData(int column, const QVariant& value, int role);

	/*!
	Метод устанавливает названия колонок
	\return QVariant
	*/
	QVariant headerData(int section, int role) const Q_DECL_OVERRIDE;


	bool isValid() const Q_DECL_OVERRIDE;
	bool isNew() const Q_DECL_OVERRIDE;
	bool hasChildren() const Q_DECL_OVERRIDE;

	bool save() Q_DECL_OVERRIDE;
	bool cancel() Q_DECL_OVERRIDE;

	void getFormatId();
	void getSiteId();
	void getScaleId();
	void getStateId();
	QList<BaseItem*> loadItemsFromDb() Q_DECL_OVERRIDE;

private:

	int m_id=0;
	int m_state_id = 0;
	int m_scale_id = 0;
	int m_session_id = 0;
	QString m_place_name;
	QString m_site_name;
	QString m_format_name;
	QString m_description;
	QString m_state_name;
	QString m_date;
	QString m_user_type;
	QString m_url;
	QString m_comment;
	/*QString m_all1;
	QString m_all;*/
	int m_format_id;
	int m_site_id;
	int m_type = 0;

};