#pragma once
#include <QDockWidget>
#include "ui_EditSites.h"
/*!
\brief 
\author �������� �.
\date ������ 2016�.
*/

class EditSites : public QWidget {
	Q_OBJECT
private:
	Ui::EditSites *ui;
	QString m_place_name;
	QString m_url;
	QString m_site_name;
	QString m_format_name;
	QString m_comment;
	int m_format_id;
	int m_site_id;
	int m_session_id = -1;
public:
	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit EditSites(int session_id, QWidget *ptr = 0);
	
	/*!
	����������
	*/
	~EditSites();
private:
	/*!
	��������� ������ �� �����
	*/
	void textRead();
	/*!
	�������� id �����
	*/
	void getSiteId();
	/*!
	�������� id �������
	*/
	void getFormatId();
	/*!
	������� ����� ������ � ������� geodata_records
	*/
	void addNewRecord();
	/*!
	�������� �� ���������� �����
	*/
	bool emptyLine();
	/*!
	������� ��������� � �������� ����� ������
	*/
	void addMessage();
private slots:
	/*!
	
	*/
	void slotCheck();
public slots:
	/*!
	���������� ������
	*/
	void slotShowNDW();
signals:
	void signalAdded();
};