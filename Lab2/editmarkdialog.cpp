#include "editmarkdialog.h"
#include "mark.h"
EditMarkDialog::EditMarkDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editCountry = new QLineEdit();
    editIssue_date = new QLineEdit();
    editNumber = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Страна"),3,1);
    mainLayout->addWidget(editCountry,3,2);
    mainLayout->addWidget(new QLabel("Год выпуска"),4,1);
    mainLayout->addWidget(editIssue_date,4,2);
    mainLayout->addWidget(new QLabel("Тираж"),5,1);
    mainLayout->addWidget(editNumber,5,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Справочник филателиста");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditMarkDialog::id() const
{
    return editID->text();
}
QString EditMarkDialog::name() const
{
    return editName->text();
}
QString EditMarkDialog::country() const
{
    return editCountry->text();
}
QString EditMarkDialog::issue_date() const
{
    return editIssue_date->text();
}
QString EditMarkDialog::number() const
{
    return editNumber->text();
}


void EditMarkDialog::SetUpDialog(QString id, QString name, QString country, QString issue_date, QString number)
{
    editID->setText(id);
    editName->setText(name);
    editCountry->setText(country);
    editIssue_date->setText(issue_date);
    editNumber->setText(number);
}
