#pragma once
#include <QString>
#include <QStringList>
class Mark {
QString m_name;
QString m_country;
double m_year;
double m_copies;
public:
static const QStringList SQL_IDS;
enum Columns {
Name,
Country,
Year,
Copies,
Count,
};
Mark(QString name,
QString country,
double year,
double copies);
const QString& name() const;
void name(QString name);
const QString& country() const; void country(QString);
double year() const; void year(double); double copies() const;
void copies(double);};






