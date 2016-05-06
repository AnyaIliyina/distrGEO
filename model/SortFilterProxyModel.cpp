#include "SortFilterProxyModel.h"

SortFilterProxyModel::SortFilterProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
}

bool SortFilterProxyModel::filterAcceptsRow(int sourceRow,
	const QModelIndex &sourceParent) const
{
	QModelIndex index0 = sourceModel()->index(sourceRow, 1, sourceParent);
	QModelIndex index1 = sourceModel()->index(sourceRow, 2 , sourceParent);
	QModelIndex index2 = sourceModel()->index(sourceRow, 3, sourceParent);

	return (sourceModel()->data(index0).toString().contains(filterRegExp())
		|| sourceModel()->data(index1).toString().contains(filterRegExp())
		||sourceModel()->data(index2).toString().contains(filterRegExp()));
}