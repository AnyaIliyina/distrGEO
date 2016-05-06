#pragma once;

#include <QSortFilterProxyModel>

class SortFilterProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	SortFilterProxyModel(QObject *parent = 0);
protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
};