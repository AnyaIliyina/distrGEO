#pragma once 
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include "LoginDialog.h"
#include "ui_MainWindow.h"
#include "ViewSites.h"
#include "ViewDepartments.h"
#include "TreeRegions.h"
#include "Item_model.h"


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
	ItemModel *m_res_model;
	
	ItemModel *m_dep_model;
	

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

	void slotOpenUrl(const QModelIndex &index);
	

};


