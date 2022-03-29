#ifndef MARK_H
#define MARK_H

#include "QString"
#include <QObject>

class Mark: public QObject
{
    Q_OBJECT

public:
    Mark(QString ID, QString Name, QString Country, QString Issue_date, QString Number, QObject *parent = nullptr );
    virtual ~Mark();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetCountry(QString Country);
    void SetIssue_date(QString Issue_date);
    void SetNumber(QString Number);

    QString ID();
    QString Name();
    QString Country();
    QString Issue_date();
    QString Number();
private:
    QString id;
    QString name;
    QString country;
    QString issue_date;
    QString number;
};
#endif // MARK_H
