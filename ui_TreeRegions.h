/********************************************************************************
** Form generated from reading UI file 'TreeRegions.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEREGIONS_H
#define UI_TREEREGIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeRegions
{
public:
    QAction *action_New;
    QAction *action_Delete;
    QAction *action_Edit;
    QAction *action_Yes;
    QAction *action_No;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TreeRegions)
    {
        if (TreeRegions->objectName().isEmpty())
            TreeRegions->setObjectName(QStringLiteral("TreeRegions"));
        TreeRegions->resize(670, 389);
        action_New = new QAction(TreeRegions);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Delete = new QAction(TreeRegions);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon1);
        action_Edit = new QAction(TreeRegions);
        action_Edit->setObjectName(QStringLiteral("action_Edit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Edit->setIcon(icon2);
        action_Yes = new QAction(TreeRegions);
        action_Yes->setObjectName(QStringLiteral("action_Yes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Yes->setIcon(icon3);
        action_No = new QAction(TreeRegions);
        action_No->setObjectName(QStringLiteral("action_No"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_No->setIcon(icon4);
        centralwidget = new QWidget(TreeRegions);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        TreeRegions->setCentralWidget(centralwidget);
        toolBar = new QToolBar(TreeRegions);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        TreeRegions->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_New);
        toolBar->addSeparator();
        toolBar->addAction(action_Delete);
        toolBar->addSeparator();
        toolBar->addAction(action_Edit);
        toolBar->addSeparator();
        toolBar->addAction(action_Yes);
        toolBar->addAction(action_No);

        retranslateUi(TreeRegions);

        QMetaObject::connectSlotsByName(TreeRegions);
    } // setupUi

    void retranslateUi(QMainWindow *TreeRegions)
    {
        TreeRegions->setWindowTitle(QApplication::translate("TreeRegions", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        TreeRegions->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        action_New->setText(QApplication::translate("TreeRegions", "&New", 0));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("TreeRegions", "\320\235\320\276\320\262\321\213\320\271 \321\200\320\265\320\263\320\270\320\276\320\275", 0));
#endif // QT_NO_TOOLTIP
        action_Delete->setText(QApplication::translate("TreeRegions", "&Delete", 0));
#ifndef QT_NO_TOOLTIP
        action_Delete->setToolTip(QApplication::translate("TreeRegions", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Edit->setText(QApplication::translate("TreeRegions", "&Edit", 0));
#ifndef QT_NO_TOOLTIP
        action_Edit->setToolTip(QApplication::translate("TreeRegions", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_Yes->setText(QApplication::translate("TreeRegions", "&Yes", 0));
#ifndef QT_NO_TOOLTIP
        action_Yes->setToolTip(QApplication::translate("TreeRegions", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        action_No->setText(QApplication::translate("TreeRegions", "&No", 0));
#ifndef QT_NO_TOOLTIP
        action_No->setToolTip(QApplication::translate("TreeRegions", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TreeRegions", "toolBar", 0));
#ifndef QT_NO_TOOLTIP
        toolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class TreeRegions: public Ui_TreeRegions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEREGIONS_H
