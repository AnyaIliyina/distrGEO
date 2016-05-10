/********************************************************************************
** Form generated from reading UI file 'ViewDepartments.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDEPARTMENTS_H
#define UI_VIEWDEPARTMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewDepartments
{
public:
    QAction *action_New;
    QAction *action_Delete;
    QAction *action_Edit;
    QAction *action_Yes;
    QAction *action_No;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ViewDepartments)
    {
        if (ViewDepartments->objectName().isEmpty())
            ViewDepartments->setObjectName(QStringLiteral("ViewDepartments"));
        ViewDepartments->resize(670, 389);
        action_New = new QAction(ViewDepartments);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Delete = new QAction(ViewDepartments);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon1);
        action_Edit = new QAction(ViewDepartments);
        action_Edit->setObjectName(QStringLiteral("action_Edit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Edit->setIcon(icon2);
        action_Yes = new QAction(ViewDepartments);
        action_Yes->setObjectName(QStringLiteral("action_Yes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Yes->setIcon(icon3);
        action_No = new QAction(ViewDepartments);
        action_No->setObjectName(QStringLiteral("action_No"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_No->setIcon(icon4);
        centralwidget = new QWidget(ViewDepartments);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(550, 200));
        tableView->setStyleSheet(QLatin1String("QTableView{\n"
"border-width:2px\n"
"}"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        ViewDepartments->setCentralWidget(centralwidget);
        toolBar = new QToolBar(ViewDepartments);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        ViewDepartments->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_New);
        toolBar->addAction(action_Delete);
        toolBar->addSeparator();
        toolBar->addAction(action_Edit);
        toolBar->addSeparator();
        toolBar->addAction(action_Yes);
        toolBar->addAction(action_No);

        retranslateUi(ViewDepartments);

        QMetaObject::connectSlotsByName(ViewDepartments);
    } // setupUi

    void retranslateUi(QMainWindow *ViewDepartments)
    {
        ViewDepartments->setWindowTitle(QApplication::translate("ViewDepartments", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        ViewDepartments->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        action_New->setText(QApplication::translate("ViewDepartments", "&New", 0));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("ViewDepartments", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Delete->setText(QApplication::translate("ViewDepartments", "&Delete", 0));
#ifndef QT_NO_TOOLTIP
        action_Delete->setToolTip(QApplication::translate("ViewDepartments", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Edit->setText(QApplication::translate("ViewDepartments", "&Edit", 0));
#ifndef QT_NO_TOOLTIP
        action_Edit->setToolTip(QApplication::translate("ViewDepartments", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Yes->setText(QApplication::translate("ViewDepartments", "&Yes", 0));
#ifndef QT_NO_TOOLTIP
        action_Yes->setToolTip(QApplication::translate("ViewDepartments", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_No->setText(QApplication::translate("ViewDepartments", "&No", 0));
#ifndef QT_NO_TOOLTIP
        action_No->setToolTip(QApplication::translate("ViewDepartments", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("ViewDepartments", "toolBar", 0));
#ifndef QT_NO_TOOLTIP
        toolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ViewDepartments: public Ui_ViewDepartments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDEPARTMENTS_H
