#pragma once
#include "ui_ViewSites.h"
#include "Item_model.h"
#include "Geodata.h"
#include "Combo_delegate.h"
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSortFilterProxyModel>

/*!
	 \file
	 \brief  Таблица интернет-ресурсов и работа с ней
	 \author Козырева О.
	 \date   апрель 2016
*/

class ViewSites : public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewSites(QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewSites();
		
	/*!
	Устанавливает модель в таблицу
	*/
	 void setupModel();

	
private:
	Ui::ViewSites *ui;
	ItemModel* m_model=nullptr;
	bool m_editMode = false;
	ComboDelegate *comboDelegateLanguage;
	ComboDelegate *comboDelegateGPI;

	/*!
	Метод для настройки таблицы 
	*/
	 void createTable();

	 /*!
	 Метод для выключения всех кнопок, исключая кнопку "Добавить"
	 */
	 void setDisabled();
		
private slots:
	/*!
	Слот добавления
	*/
	void slotAdd();
	/*!
	Слот удаления
	*/
	void slotDelete();
	/*
	 Слот редактирования
	 */
	 void slotEdit();
	 /*!
	 Слот применения изменений
	 */
	 void slotSave();
	 /*!
	 Слот отмены изменений
	 */
	 void slotCancel();
	 /*!
	 Слот обновления модели
	 */
	 void slotRefresh();
	 /*!
	 Слоты включения/выключения кнопок 
	 */
     void slotEnableButtons(const QItemSelection &, const QItemSelection &);
	 void slotEnableButtons();

	 /*!
	 Слот открытия ссылки
	 */
	 void slotOpenUrl();

	  
 signals:
	 /*!
	 Сигнал, испускается при редактировании записи, для включения режима редактирования дерева регионов
	 */
	 void signalEditSite();

	 /*!
	 Сигнал, испускается при сохранении записи, для сохранения изменений в дереве регионов
	\param int - id интернет-ресурса
	\param bool 
	*/
	 void signalSave(int, bool);

	 /*!
	 Сигнал для включения/выключения кнопок
	 */
	 void signalChangeEditMode();

	 /*!
	 Сигнал, для выделения элементов дерева регионов, по выделенной записи в таблице интернет-ресурсов
	 \param int !=-1, если выделена одна запись в таблице, отправляем id выделеной записи
	 */
	 void valueSelected(int);
	 
	 /*!
	 Сигнал о том, что данные в модели изменились
	 */
	 void dataChanged();

	
	 
	
};