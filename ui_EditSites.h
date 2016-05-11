/********************************************************************************
** Form generated from reading UI file 'EditSites.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSITES_H
#define UI_EDITSITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditSites
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label_3;
    QLineEdit *lineUrl;
    QLabel *label_2;
    QLineEdit *lineLanguage;
    QLabel *label_4;
    QLineEdit *lineGPI;
    QLabel *label_6;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lineError;

    void setupUi(QWidget *EditSites)
    {
        if (EditSites->objectName().isEmpty())
            EditSites->setObjectName(QStringLiteral("EditSites"));
        EditSites->resize(586, 280);
        QFont font;
        font.setPointSize(9);
        EditSites->setFont(font);
        gridLayout = new QGridLayout(EditSites);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(-1, 5, -1, 0);
        label = new QLabel(EditSites);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineName = new QLineEdit(EditSites);
        lineName->setObjectName(QStringLiteral("lineName"));
        lineName->setFont(font);
        lineName->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineName);

        label_3 = new QLabel(EditSites);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineUrl = new QLineEdit(EditSites);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);
        lineUrl->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineUrl);

        label_2 = new QLabel(EditSites);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineLanguage = new QLineEdit(EditSites);
        lineLanguage->setObjectName(QStringLiteral("lineLanguage"));
        lineLanguage->setFont(font);
        lineLanguage->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineLanguage);

        label_4 = new QLabel(EditSites);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineGPI = new QLineEdit(EditSites);
        lineGPI->setObjectName(QStringLiteral("lineGPI"));
        lineGPI->setFont(font);
        lineGPI->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineGPI);

        label_6 = new QLabel(EditSites);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        textEdit = new QTextEdit(EditSites);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"border-radius:8;\n"
"border-width:1px;\n"
"max-height:70px;\n"
"min-height:70px;\n"
"\n"
"}"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(EditSites);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setFont(font);
        btnCreate->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px\n"
"\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCreate->setIcon(icon);
        btnCreate->setIconSize(QSize(30, 30));
        btnCreate->setFlat(true);

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(EditSites);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setFont(font);
        btnCancel->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        btnCancel->setIconSize(QSize(30, 30));
        btnCancel->setFlat(true);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lineError = new QLabel(EditSites);
        lineError->setObjectName(QStringLiteral("lineError"));
        lineError->setFont(font);

        gridLayout->addWidget(lineError, 2, 0, 1, 1);


        retranslateUi(EditSites);
        QObject::connect(btnCancel, SIGNAL(clicked()), EditSites, SLOT(close()));

        QMetaObject::connectSlotsByName(EditSites);
    } // setupUi

    void retranslateUi(QWidget *EditSites)
    {
        EditSites->setWindowTitle(QApplication::translate("EditSites", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        label->setText(QApplication::translate("EditSites", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\321\201\321\203\321\200\321\201\320\260", 0));
        label_3->setText(QApplication::translate("EditSites", "\320\220\320\264\321\200\320\265\321\201 \320\270\320\275\321\202\320\265\321\200\320\275\320\265\321\202 \321\200\320\265\321\201\321\203\321\200\321\201\320\260 (URL)", 0));
        label_2->setText(QApplication::translate("EditSites", "\320\257\320\267\321\213\320\272/\321\217\320\267\321\213\320\272\320\270 \321\201\320\260\320\271\321\202\320\260", 0));
        label_4->setText(QApplication::translate("EditSites", "\320\222\320\270\320\264\321\213 \320\223\320\237\320\230, \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\321\217\320\265\320\274\321\213\320\265 \320\275\320\260 \321\201\320\260\320\271\321\202\320\265", 0));
        label_6->setText(QApplication::translate("EditSites", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270", 0));
        btnCreate->setText(QString());
        btnCancel->setText(QString());
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditSites: public Ui_EditSites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSITES_H
