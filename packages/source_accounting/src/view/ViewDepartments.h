#pragma once
#include "ui_ViewDepartments.h"
#include "Item_model.h"
#include "Geodata.h"
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSortFilterProxyModel>

/*!
	 \file
	 \brief  Вывод результатов поиска и работа с ними
	 \author Козырева О.
	 \date   апрель 2016
*/

class ViewDepartments: public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewDepartments(QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewDepartments();
		
	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	 void setupModel();

private:
	Ui::ViewDepartments *ui;
	ItemModel* m_model=nullptr;
	bool m_editMode = false;
	

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
	 ///*!
	 //Слот фильтрации данных в таблице
	 //\param QString text - искомая строка
	 //*/
	 //void slotFilterChanged(QString text);

	
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

	 void signalEditSite();

	 void signalSave(int, bool);
};