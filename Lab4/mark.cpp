
#include "mark.h"
#include <utility>
using std::move;
const QStringList Mark::SQL_IDS = {
QString("name"),
QString("country"),
QString("year"),
QString("copies"),
};
Mark::Mark(QString name,
QString country,
double year,
double copies)
: m_name(move(name)),
m_country(move(country)),
m_year(year),
m_copies(copies) {}
const QString& Mark::name() const {
return m_name;
}
void Mark::name(QString name) {
m_name = move(name);
}
const QString& Mark::country() const { return m_country;
}
void Mark::country(QString country) { m_country = move(country);
}
double Mark::year() const { return m_year;
}
void Mark::year(double year) { m_year = year;
}
double Mark::copies() const { return m_copies;
}
void Mark::copies(double copies) { m_copies = copies;
}

