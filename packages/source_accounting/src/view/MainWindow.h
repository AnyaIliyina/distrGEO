#pragma once 
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include "LoginDialog.h"
#include "ui_MainWindow.h"
#include "ViewSites.h"
#include "ViewDepartments.h"
#include "RegionItemChecked.h"
#include "TreeRegions.h"
#include "Item_model.h"
#include "ViewContent.h"
#include "ViewFiles.h"

/*!
	\file
	\brief Описывает конфигурацию основного окна приложения
	\author Ильина А., Козырева О.
	\date март 2016г.
*/
class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	/*! 
	Конструктор 
	\param QMainWindow *parent - родительский виджет
	*/
	explicit MainWindow(QMainWindow *parent = 0);
	
	/*! Деструктор*/
	~MainWindow();

private:
	/*!
	Выводит основное окно и начинает работу модуля поиска
	*/
	void showMW();
	
	Ui::MainWindow *ui;
	ViewDepartments *m_vd;
	ViewSites *m_vs;
	TreeRegions *m_tr;
	ViewContent *m_vc;
	ViewFiles *m_vf;
	QTreeView *treeSites;
	QTreeView *treeDepartments;
	QTreeView *treeSearch;
	QTableView *tableSites;
	QTableView *tableDepartments;
	QHBoxLayout *vslayout;
	QHBoxLayout *vdlayout;
	QWidget *search;
	QWidget *sites;
	QWidget *departaments;
	QWidget *content;
	ItemModel *m_res_model;
	
	ItemModel *m_dep_model;
	//ItemModel *m_regions;
	ItemModel *m_regionsChecked=nullptr;
	
	QMap<int, RegionItemChecked*> map;	// id регионов и указатели на регионы
	void setContentView();
	void setSearchResources();
	void setResourcesView();
	void setDepartamentView();
	void setupModelSite(int id);
	void setupModelDepartment(int id);

private slots:
	/*!
	Выводит сообщение на панель StatusBar
	\param const QString &str - текст сообщения
	*/
	void slotShowStatus(const QString &status);
	
	/*!
	Закрывает основное окно
	*/
	void slotCloseMW();

	/*! Создает модель из экземпляров RegionItemChecked*/
	void slotSetupRegionsModel();
	
	/*!
	"Собирает" основное окно из виджетов
	\param int type - тип пользователя
	*/
	void slotConfigure();

	void slotForSearch(const QItemSelection &, const QItemSelection &);
	/*!
	Начинает сессию для пользователя user_id
	\param  user_id - идентификатор пользователя */
	void slotStartSession(int user_id);

	void slotSelectRegion(int i);

	void slotSelectDepartment(int i);

	void slotOpenUrl(const QModelIndex &index);
	
	void slotGetCheckSite();

	void slotMakeCheckEditble(const QItemSelection &, const QItemSelection &);

	void slotEditCheck(int id, bool save);

	void slotGetCheckDepartment();

	void slotEditCheckDepartment(int id, bool saveChanges);


};


