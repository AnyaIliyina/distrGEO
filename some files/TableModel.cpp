#include "TableModel.h"
#include "State.h"
#include "Database.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>

TableModel::TableModel(QObject *parent) :QAbstractTableModel(parent)
{
	QSqlDatabase db = Database::database();
	QSqlQuery q = QSqlQuery(db);
	q.setForwardOnly(true);
	q.prepare("SELECT record_id, place_name, site_name,  format_name, description, state_name,  date, type_name, geodata_records.url, geodata_records.comment"
		"FROM geodata_records"
		"JOIN sites ON geodata_records.site_id=sites.site_id"
		"JOIN formats ON geodata_records.format_id=formats.format_id"
		"JOIN scales ON scales.scale_id=geodata_records.scale_id"
		"JOIN states ON states.state_id=geodata_records.state_id"
		"JOIN sessions ON sessions.session_id=geodata_records.session_id"
		"JOIN users ON sessions.user_id=users.user_id"
		"JOIN usertypes ON users.type_id=usertypes.type_id");
	if (!q.exec())
	{
		qDebug() << q.lastError().text();
		db.close();
	}
	while (q.next())
	{
		int row = m_geo.count();
		beginInsertRows(QModelIndex(), row, row);
		GeoData g;
		g[ID] = q.value(0).toInt();
		g[PLACE_NAME] = q.value(1).toString();
		g[SITE_NAME] = q.value(2).toString();
		g[FORMAT_NAME] = q.value(3).toString();
		g[DESCRIPTION] = q.value(4).toString();
		g[STATE_NAME] = q.value(5).toString();
		g[DATE] = q.value(6).toString();
		g[USER_TYPE] = q.value(7).toString();
		g[COMMENT] = q.value(8).toString();
		m_geo << g;
		endInsertRows();
	}
}


int TableModel::rowCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return m_geo.count();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return LAST;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid() || m_geo.count() <= index.row() || (role != Qt::DisplayRole&&role != Qt::EditRole))
	{
		return QVariant();
	}
	return m_geo[index.row()][Column(index.column())];
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}
	if (orientation == Qt::Vertical)
	{
		return section;
	}
	switch (section)
	{
	case ID:
		return ("ID");
	case PLACE_NAME:
		return (State::coded("Название местности"));
	case SITE_NAME:
		return (State::coded("Сайт"));
	case FORMAT_NAME:
		return (State::coded("Формат"));
	case DESCRIPTION:
		return (State::coded("Масштаб"));
	case STATE_NAME:
		return (State::coded("Статус"));
	case DATE:
		return (State::coded("Дата"));
	case USER_TYPE:
		return (State::coded("Пользователь"));
	case COMMENT:
		return (State::coded("Комментарии"));
	}
	return QVariant();
}


