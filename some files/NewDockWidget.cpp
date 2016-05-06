#include "NewDockWidget.h"
#include <QSqlQuery>
#include "Database.h"
#include "Site.h"
#include "Geodata_record.h"
#include <QMessageBox>
#include "Scale.h"
#include <QComboBox>
#include <QSqlQueryModel>
#include "Format.h"
#include "ViewWindow.h"

NewDockWidget::NewDockWidget(int session_id, QWidget * ptr)
{
	ui = new Ui::NewRecord();
	ui->setupUi(this);
	m_session_id = session_id;
	QStringList listSites = Site::getSiteNames();
	ui->boxSite->addItems(listSites);
	QStringList listFormats = Format::getFormatNames();
	ui->boxFormat->addItems(listFormats);
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(slotCheck()));
}

NewDockWidget::~NewDockWidget()
{
	qDebug() << "newDockWidget destructor";
	delete ui;
}

void NewDockWidget::addNewRecord()
{
	getSiteId();
	getFormatId();
	qDebug() << m_site_id, m_format_id, m_place_name;
	Geodata_record* ngdr= new Geodata_record(m_site_id, m_format_id, m_place_name, m_session_id, 1, 2, m_url, m_comment);
	if (ngdr->insertIntoDatabase())
	{
		int okMsgBox = QMessageBox::information(this, Scale::coded("Успех!"), Scale::coded("Новая запись успешно добавлена"), Scale::coded("Ok"));
		if (okMsgBox == 0)
		{
			ui->btnCancel->click();
			emit signalAdded();
		}
	}
	else
	{
		int okMsgBox = QMessageBox::information(this, Scale::coded("Ошибка"), Scale::coded("Новая запись не добавлена"), Scale::coded("Ok"));
	}
}

void NewDockWidget::slotCheck()
{
	textRead();
	if (emptyLine())
	{
			addMessage();
	}
	else
	{
		ui->lineError->setText(Scale::coded("Заполни поля, выделенные звездочкой, товарищ!"));
	}
}

void NewDockWidget::addMessage()
{	
	int saveMsgBox = QMessageBox::information(this,
			Scale::coded("Создать новую запись?"), Scale::coded("Новая запись будет создана в базе"),
			Scale::coded("Создать"), Scale::coded("Отмена"));
		if (saveMsgBox == 0)
		{
			addNewRecord();
		}
}

void NewDockWidget::getFormatId()
{
	qDebug() << "getting FormatId...";
	 m_format_id = ui->boxFormat->currentIndex() +1;
	qDebug() << "m_formatId = " << m_format_id;
}

void NewDockWidget::getSiteId()
{
	qDebug() << "getting SiteId...";
	m_site_id=Site::site_id(m_site_name);
	qDebug() << m_site_id; // если можно удалять сайты, то раскоментить*/ 
	//m_site_id = ui->boxSite->currentIndex();
		
}

void NewDockWidget::textRead()
{
	m_place_name = ui->linePlace->text();
	m_url = ui->lineUrl->text();
	m_site_name = ui->boxSite->currentText();
	m_format_name = ui->boxFormat->currentText();
	m_comment = ui->textEdit->toPlainText();
	qDebug() << m_comment;
}

bool NewDockWidget::emptyLine()
{
	if ((m_place_name.isEmpty()) || (m_site_name.isEmpty()) ||(m_format_name.isEmpty()))
	{
			 return false;
	}
	else
	{
		return true;
	}
}

void NewDockWidget::slotShowNDW()
{
	this->show();
}
