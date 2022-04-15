#include "mark.h"

Mark::Mark(/*QString ID, QString Name, QString Country, QString Year, QString Copies, QObject *parent): QObject(parent*/)
{
    /*id = ID;
    name = Name;
    country = Country;
    year = Year;
    copies = Copies;*/
}

void Mark::SetID(QString ID)
{
    id = ID;
}
void Mark::SetName(QString Name)
{
    name = Name;
}
void Mark::SetCountry(QString Country)
{
    country = Country;
}
void Mark::SetYear(QString Year)
{
    year = Year;
}
void Mark::SetCopies(QString Copies)
{
    copies = Copies;
}

QString Mark::getID() const
{
    return id;
}
QString Mark::getName() const
{
    return name;
}
QString Mark::getCountry() const
{
    return country;
}
QString Mark::getYear() const
{
    return year;
}
QString Mark::getCopies() const
{
    return copies;
}

 Mark::~Mark()
{
}
