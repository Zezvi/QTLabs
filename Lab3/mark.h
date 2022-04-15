#ifndef MARK_H
#define MARK_H

#include "QString"
//#include <QObject>

class Mark
        //: public QObject
{
   // Q_OBJECT

public:
    Mark(/*QString ID, QString Name, QString Country, QString Year, QString Copies, QObject *parent = nullptr*/ );

    virtual ~Mark();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetCountry(QString Country);
    void SetYear(QString Year);
    void SetCopies(QString Copies);

    QString getID() const;
    QString getName() const;
    QString getCountry() const;
    QString getYear() const;
    QString getCopies() const;

private:
    QString id;
    QString name;
    QString country;
    QString year;
    QString copies;
};
#endif // MARK_H



