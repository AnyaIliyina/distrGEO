/*!

	\file
	\brief Делегат ComboBox
	\author Чернышев Д.Р.
	\date Апрель 2016

*/

#pragma once

#include "Multilist.h"
#include <QItemDelegate>
#include <QList>


class ComboDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	~ComboDelegate();
	ComboDelegate(const QList<QString>& list, QObject* parent = NULL);

	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
private:
	QList<QString> m_list;
	QList<int> m_listIDs;
private slots:
	void slotSetListIDs(QList<int>);
};