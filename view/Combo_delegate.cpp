#include "Combo_delegate.h"

#include <QComboBox>

ComboDelegate::~ComboDelegate() {
};

ComboDelegate::ComboDelegate(const QList<QString>& list, QObject* parent) {
	m_list = list;
};

QWidget* ComboDelegate::createEditor(
	QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {

	// Возвращаем QComboBox
	auto cBox = new QComboBox(parent);

	for (int i = 0; i < m_list.count(); i++) {
		cBox->addItem(m_list[i]);
	}

	return cBox;
};