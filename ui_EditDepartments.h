/********************************************************************************
** Form generated from reading UI file 'EditDepartments.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDEPARTMENTS_H
#define UI_EDITDEPARTMENTS_H

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

class Ui_EditDepartments
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label_3;
    QLineEdit *lineCountry;
    QLabel *label_2;
    QLineEdit *lineAddress;
    QLabel *label_4;
    QLineEdit *linePhone;
    QLabel *label_5;
    QLineEdit *lineFax;
    QLabel *label_7;
    QLineEdit *lineEmail;
    QLabel *label_8;
    QLineEdit *lineGPI;
    QLabel *label_6;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lineError;

    void setupUi(QWidget *EditDepartments)
    {
        if (EditDepartments->objectName().isEmpty())
            EditDepartments->setObjectName(QStringLiteral("EditDepartments"));
        EditDepartments->resize(586, 395);
        QFont font;
        font.setPointSize(9);
        EditDepartments->setFont(font);
        gridLayout = new QGridLayout(EditDepartments);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(13);
        formLayout->setContentsMargins(-1, 5, -1, -1);
        label = new QLabel(EditDepartments);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineName = new QLineEdit(EditDepartments);
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

        label_3 = new QLabel(EditDepartments);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineCountry = new QLineEdit(EditDepartments);
        lineCountry->setObjectName(QStringLiteral("lineCountry"));
        lineCountry->setFont(font);
        lineCountry->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineCountry);

        label_2 = new QLabel(EditDepartments);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineAddress = new QLineEdit(EditDepartments);
        lineAddress->setObjectName(QStringLiteral("lineAddress"));
        lineAddress->setFont(font);
        lineAddress->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineAddress);

        label_4 = new QLabel(EditDepartments);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        linePhone = new QLineEdit(EditDepartments);
        linePhone->setObjectName(QStringLiteral("linePhone"));
        linePhone->setFont(font);
        linePhone->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(3, QFormLayout::FieldRole, linePhone);

        label_5 = new QLabel(EditDepartments);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineFax = new QLineEdit(EditDepartments);
        lineFax->setObjectName(QStringLiteral("lineFax"));
        lineFax->setFont(font);
        lineFax->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineFax);

        label_7 = new QLabel(EditDepartments);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lineEmail = new QLineEdit(EditDepartments);
        lineEmail->setObjectName(QStringLiteral("lineEmail"));
        lineEmail->setFont(font);
        lineEmail->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEmail);

        label_8 = new QLabel(EditDepartments);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        lineGPI = new QLineEdit(EditDepartments);
        lineGPI->setObjectName(QStringLiteral("lineGPI"));
        lineGPI->setFont(font);
        lineGPI->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineGPI);

        label_6 = new QLabel(EditDepartments);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        textEdit = new QTextEdit(EditDepartments);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"border-radius:8;\n"
"border-width:1px;\n"
"max-height:70px;\n"
"min-height:70px;\n"
"\n"
"}"));

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(EditDepartments);
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

        btnCancel = new QPushButton(EditDepartments);
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


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        lineError = new QLabel(EditDepartments);
        lineError->setObjectName(QStringLiteral("lineError"));
        lineError->setFont(font);

        gridLayout->addWidget(lineError, 2, 0, 1, 2);


        retranslateUi(EditDepartments);
        QObject::connect(btnCancel, SIGNAL(clicked()), EditDepartments, SLOT(close()));

        QMetaObject::connectSlotsByName(EditDepartments);
    } // setupUi

    void retranslateUi(QWidget *EditDepartments)
    {
        EditDepartments->setWindowTitle(QApplication::translate("EditDepartments", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        label->setText(QApplication::translate("EditDepartments", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\321\201\321\202\320\262\320\260", 0));
        label_3->setText(QApplication::translate("EditDepartments", "\320\241\321\202\321\200\320\260\320\275\320\260", 0));
        label_2->setText(QApplication::translate("EditDepartments", "\320\220\320\264\321\200\320\265\321\201", 0));
        label_4->setText(QApplication::translate("EditDepartments", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        label_5->setText(QApplication::translate("EditDepartments", "\320\244\320\260\320\272\321\201", 0));
        label_7->setText(QApplication::translate("EditDepartments", "\320\220\320\264\321\200\320\265\321\201 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213", 0));
        label_8->setText(QApplication::translate("EditDepartments", "\320\222\320\270\320\264\321\213 \320\223\320\237\320\230, \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\321\217\320\265\320\274\321\213\320\265 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\265\320\271", 0));
        label_6->setText(QApplication::translate("EditDepartments", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270", 0));
        btnCreate->setText(QString());
        btnCancel->setText(QString());
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditDepartments: public Ui_EditDepartments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDEPARTMENTS_H
