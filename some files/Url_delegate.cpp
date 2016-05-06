#include "Url_delegate.h"

#include <QComboBox>

Url_delegate::~Url_delegate() {
};

Url_delegate::Url_delegate(QObject* parent) {
	
};

QWidget* Url_delegate::createEditor(
	QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {

	// Возвращаем QComboBox
	auto label = new QLabel(parent);
	//label->setText("");
	label->setOpenExternalLinks(true);
	
	return label;
};