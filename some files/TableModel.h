#pragma once

#include <QAbstractTableModel>

class TableModel :public QAbstractTableModel {
	Q_OBJECT
public:
	TableModel(QObject* parent = 0);

	int rowCount(const QModelIndex& parent) const;
	int columnCount(const QModelIndex& parent) const;
	QVariant data(const QModelIndex& index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	
private:
	enum Column {
		ID = 0,
		PLACE_NAME,
		SITE_NAME,
		FORMAT_NAME,
		DESCRIPTION,
		STATE_NAME,
		DATE,
		USER_TYPE,
		COMMENT,
		LAST
	};

	typedef QHash< Column, QVariant > GeoData;
	typedef QList< GeoData > Geo;
	Geo m_geo;

};

