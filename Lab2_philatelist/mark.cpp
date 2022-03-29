#include "mark.h"

Mark::Mark(QString ID, QString Name, QString Country, QString Issue_date, QString Number, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    country = Country;
    issue_date = Issue_date;
    number = Number;
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
void Mark::SetIssue_date(QString Issue_date)
{
    issue_date = Issue_date;
}
void Mark::SetNumber(QString Number)
{
    number = Number;
}

QString Mark::ID()
{
    return id;
}
QString Mark::Name()
{
    return name;
}
QString Mark::Country()
{
    return country;
}
QString Mark::Issue_date()
{
    return issue_date;
}
QString Mark::Number()
{
    return number;
}

 Mark::~Mark()
{
}
