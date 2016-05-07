#include "EditSites.h"
#include "Database.h"
#include "Site.h"
#include "Geodata_record.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QComboBox>
#include <QSqlQueryModel>


EditSites::EditSites(int session_id, QWidget * ptr)
{
	ui = new Ui::EditSites();
	ui->setupUi(this);
	m_session_id = session_id;
	
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(slotCheck()));
}

EditSites::~EditSites()
{
	qDebug() << "EditSites destructor";
	delete ui;
}

void EditSites::addNewRecord()
{
	//getSiteId();
	//getFormatId();
	//qDebug() << m_site_id, m_format_id, m_place_name;
	//Geodata_record* ngdr= new Geodata_record(m_site_id, m_format_id, m_place_name, m_session_id, 1, 2, m_url, m_comment);
	//if (ngdr->insertIntoDatabase())
	//{
	//	int okMsgBox = QMessageBox::information(this, Scale::coded("�����!"), Scale::coded("����� ������ ������� ���������"), Scale::coded("Ok"));
	//	if (okMsgBox == 0)
	//	{
	//		ui->btnCancel->click();
	//		emit signalAdded();
	//	}
	//}
	//else
	//{
	//	int okMsgBox = QMessageBox::information(this, Scale::coded("������"), Scale::coded("����� ������ �� ���������"), Scale::coded("Ok"));
	//}
}

void EditSites::slotCheck()
{
	/*textRead();
	if (emptyLine())
	{
			addMessage();
	}
	else
	{
		ui->lineError->setText(Scale::coded("������� ����, ���������� ����������, �������!"));
	}*/
}

void EditSites::addMessage()
{	/*
	int saveMsgBox = QMessageBox::information(this,
			Scale::coded("������� ����� ������?"), Scale::coded("����� ������ ����� ������� � ����"),
			Scale::coded("�������"), Scale::coded("������"));
		if (saveMsgBox == 0)
		{
			addNewRecord();
		}*/
}

void EditSites::getFormatId()
{
	/*qDebug() << "getting FormatId...";
	 m_format_id = ui->boxFormat->currentIndex() +1;
	qDebug() << "m_formatId = " << m_format_id;*/
}

void EditSites::getSiteId()
{
	//qDebug() << "getting SiteId...";
	//m_site_id=Site::site_id(m_site_name);
	//qDebug() << m_site_id; // ���� ����� ������� �����, �� ������������*/ 
	////m_site_id = ui->boxSite->currentIndex();
		
}

void EditSites::textRead()
{
	/*m_place_name = ui->linePlace->text();
	m_url = ui->lineUrl->text();
	m_site_name = ui->boxSite->currentText();
	m_format_name = ui->boxFormat->currentText();
	m_comment = ui->textEdit->toPlainText();
	qDebug() << m_comment;*/
}

bool EditSites::emptyLine()
{
	/*if ((m_place_name.isEmpty()) || (m_site_name.isEmpty()) ||(m_format_name.isEmpty()))
	{
			 return false;
	}
	else
	{*/
		return true;
	
}

void EditSites::slotShowNDW()
{
	//this->show();
}
