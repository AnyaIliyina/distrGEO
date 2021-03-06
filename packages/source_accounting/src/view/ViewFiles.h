﻿#pragma once
#include "ui_ViewFiles.h"
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
	 \brief  Таблица файлов и работа с ней
	 \author Козырева О.
	 \date   апрель 2016
*/

class ViewFiles : public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewFiles(QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewFiles();
		
	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	 void setupModel();

	
private:
	Ui::ViewFiles *ui;
	ItemModel* m_model=nullptr;
	
	bool m_editMode = false;
	ComboDelegate *comboDelegateLanguage;
	ComboDelegate *comboDelegateGPI;
	/*!
	Метод для установки модели в таблицу и настройки таблицы
	*/
	 void createTable();

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
	 Слот обновления модели
	 */
	 void slotRefresh();
	 /*!
	 Слоты включения/выключения кнопок 
	 */
     void slotEnableButtons(const QItemSelection &, const QItemSelection &);
	 //void slotEnableButtons();

	 /*!
	 Слот открытия ссылки
	 */
	 void slotOpenUrl();

	  
 signals:
	 /*!
	 Сигнал для включения/выключения кнопок
	 */
	 void signalChangeEditMode();

	 /*!
	 Сигнал о том, что данные в модели изменились
	 */
	 void dataChanged();

	 void valueSelected(int);

};