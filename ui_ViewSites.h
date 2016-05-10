/********************************************************************************
** Form generated from reading UI file 'ViewSites.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSITES_H
#define UI_VIEWSITES_H

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

class Ui_ViewSites
{
public:
    QAction *action_New;
    QAction *action_Delete;
    QAction *action_Edit;
    QAction *action_Yes;
    QAction *action_No;
    QAction *action_OpenUrl;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ViewSites)
    {
        if (ViewSites->objectName().isEmpty())
            ViewSites->setObjectName(QStringLiteral("ViewSites"));
        ViewSites->resize(670, 387);
        action_New = new QAction(ViewSites);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Delete = new QAction(ViewSites);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon1);
        action_Edit = new QAction(ViewSites);
        action_Edit->setObjectName(QStringLiteral("action_Edit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Edit->setIcon(icon2);
        action_Yes = new QAction(ViewSites);
        action_Yes->setObjectName(QStringLiteral("action_Yes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Yes->setIcon(icon3);
        action_No = new QAction(ViewSites);
        action_No->setObjectName(QStringLiteral("action_No"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_No->setIcon(icon4);
        action_OpenUrl = new QAction(ViewSites);
        action_OpenUrl->setObjectName(QStringLiteral("action_OpenUrl"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/share2.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_OpenUrl->setIcon(icon5);
        centralwidget = new QWidget(ViewSites);
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

        ViewSites->setCentralWidget(centralwidget);
        toolBar = new QToolBar(ViewSites);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        ViewSites->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_New);
        toolBar->addAction(action_Delete);
        toolBar->addSeparator();
        toolBar->addAction(action_OpenUrl);
        toolBar->addSeparator();
        toolBar->addAction(action_Edit);
        toolBar->addSeparator();
        toolBar->addAction(action_Yes);
        toolBar->addAction(action_No);

        retranslateUi(ViewSites);

        QMetaObject::connectSlotsByName(ViewSites);
    } // setupUi

    void retranslateUi(QMainWindow *ViewSites)
    {
        ViewSites->setWindowTitle(QApplication::translate("ViewSites", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        ViewSites->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        action_New->setText(QApplication::translate("ViewSites", "&New", 0));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("ViewSites", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Delete->setText(QApplication::translate("ViewSites", "&Delete", 0));
#ifndef QT_NO_TOOLTIP
        action_Delete->setToolTip(QApplication::translate("ViewSites", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Edit->setText(QApplication::translate("ViewSites", "&Edit", 0));
#ifndef QT_NO_TOOLTIP
        action_Edit->setToolTip(QApplication::translate("ViewSites", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Yes->setText(QApplication::translate("ViewSites", "&Yes", 0));
#ifndef QT_NO_TOOLTIP
        action_Yes->setToolTip(QApplication::translate("ViewSites", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_No->setText(QApplication::translate("ViewSites", "&No", 0));
#ifndef QT_NO_TOOLTIP
        action_No->setToolTip(QApplication::translate("ViewSites", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_OpenUrl->setText(QApplication::translate("ViewSites", "&OpenUrl", 0));
#ifndef QT_NO_TOOLTIP
        action_OpenUrl->setToolTip(QApplication::translate("ViewSites", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\277\320\276 \321\201\321\201\321\213\320\273\320\272\320\265", 0));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("ViewSites", "toolBar", 0));
#ifndef QT_NO_TOOLTIP
        toolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ViewSites: public Ui_ViewSites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSITES_H
