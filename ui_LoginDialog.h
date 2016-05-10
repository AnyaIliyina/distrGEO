/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *lbl_login;
    QLineEdit *line_Login;
    QLabel *lbl_password;
    QLineEdit *line_Pass;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblResult;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(296, 153);
        LoginDialog->setMaximumSize(QSize(300, 153));
        QFont font;
        font.setPointSize(9);
        LoginDialog->setFont(font);
        LoginDialog->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(10);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(-1, 5, -1, 10);
        lbl_login = new QLabel(LoginDialog);
        lbl_login->setObjectName(QStringLiteral("lbl_login"));
        lbl_login->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_login);

        line_Login = new QLineEdit(LoginDialog);
        line_Login->setObjectName(QStringLiteral("line_Login"));
        line_Login->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_Login);

        lbl_password = new QLabel(LoginDialog);
        lbl_password->setObjectName(QStringLiteral("lbl_password"));
        lbl_password->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_password);

        line_Pass = new QLineEdit(LoginDialog);
        line_Pass->setObjectName(QStringLiteral("line_Pass"));
        line_Pass->setFont(font);
        line_Pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_Pass);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_login = new QPushButton(LoginDialog);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setMaximumSize(QSize(16777215, 16777215));
        btn_login->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_login->setIcon(icon);
        btn_login->setIconSize(QSize(30, 30));
        btn_login->setFlat(true);

        horizontalLayout_2->addWidget(btn_login);

        btn_exit = new QPushButton(LoginDialog);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setMaximumSize(QSize(112, 30));
        btn_exit->setStyleSheet(QStringLiteral("QPushButton{border:0px}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_exit->setIcon(icon1);
        btn_exit->setIconSize(QSize(30, 30));
        btn_exit->setFlat(true);

        horizontalLayout_2->addWidget(btn_exit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        lblResult = new QLabel(LoginDialog);
        lblResult->setObjectName(QStringLiteral("lblResult"));

        gridLayout->addWidget(lblResult, 2, 0, 1, 1);


        retranslateUi(LoginDialog);
        QObject::connect(btn_exit, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", 0));
        lbl_login->setText(QApplication::translate("LoginDialog", "\320\233\320\276\320\263\320\270\320\275:", 0));
        lbl_password->setText(QApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
        btn_login->setText(QString());
        btn_exit->setText(QString());
        lblResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
