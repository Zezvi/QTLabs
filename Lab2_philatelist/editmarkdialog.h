//#ifndef EDITMARKDIALOG_H
//#define EDITMARKDIALOG_H

//#endif // EDITMARKDIALOG_H
#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "mark.h"

class EditMarkDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editCountry;
    QLineEdit* editIssue_date;
    QLineEdit* editNumber;

public:
    EditMarkDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString country() const;
    QString issue_date() const;
    QString number() const;

    void SetUpDialog(QString id, QString name, QString country, QString issue_date, QString number);
};

#endif // INPUTDIALOG_H
