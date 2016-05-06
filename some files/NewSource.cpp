#include "NewSource.h"
#include <QSqlQuery>
#include "Database.h"
#include "Site.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include "Scale.h"
NewSource::NewSource(QWidget * ptr)
{
	ui = new Ui::NewSource();
	ui->setupUi(this);
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(slotCheck()));
}

NewSource::~NewSource()
{
	qDebug() << "newSource destructor";
	delete ui;
}

void NewSource::textRead()
{
	m_site_name = ui->lineSite->text();
	m_url = ui->lineUrl->text();
	m_comment = ui->textEdit->toPlainText();
}

void NewSource::addNewRecord()
{
	Site* ns = new Site(m_url, m_site_name, 0, m_comment);
	if (ns->insertIntoDatabase() != -1)
	{
		int okMsgBox = QMessageBox::information(this, "Успех!", "Новый источник успешно добавлен", "Ok");
		if (okMsgBox == 0)
		{
			ui->btnCancel->click();
		}
	}
	else
	{
		int okMsgBox = QMessageBox::information(this, "Ошибка", "Новый источник не добавлен","Ok");
	}
	
}

void NewSource::slotCheck()
{
	ui->lineError->setText("");
	textRead();
	if (emptyLine())
	{
		if (Site::urlFromString(m_url))
			addMessage();
		else
			ui->lineError->setText("Url не валидный!");
	}
	else
	{
		ui->lineError->setText("Заполни все поля, товарищ!");
	}
}
bool NewSource::emptyLine()
{
	if ((m_url.isEmpty()) || (m_site_name.isEmpty()))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void NewSource::addMessage()
{
	int saveMsgBox = QMessageBox::information(this,
		"Создать новую запись?", "Новая запись будет создана в базе",
		"Создать", "Отмена");
	if (saveMsgBox == 0)
	{
		addNewRecord();
	}
}

void NewSource::slotShowNS()
{
	this->show();
}