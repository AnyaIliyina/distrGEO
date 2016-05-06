#pragma once

#include <QItemDelegate>
#include <QLabel>

/*!
	\file
	\brief   
	\author   Козырева О.
	\date     
*/

class Url_delegate : public QItemDelegate
{
	Q_OBJECT
public:
	~Url_delegate();
	Url_delegate(QObject* parent = NULL);

	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
	QList<QString> m_list;
};