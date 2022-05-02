#include "marklist.h"
#include "mark.h"
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
using std::move;
using VSC = Mark::Columns;
auto& SQL_IDS = Mark::SQL_IDS;


MarkList::MarkList()
: m_database(QSqlDatabase::addDatabase("QSQLITE")) { m_database.setDatabaseName("qtlab.sqlite");
if (!m_database.open()) return;
QSqlQuery(m_database)
.exec(
"CREATE TABLE mark ("
+ SQL_IDS[VSC::Name] + " VARCHAR(255) PRIMARY KEY NOT NULL, "
+ SQL_IDS[VSC::Country] + " VARCHAR(255) NOT NULL, "
+ SQL_IDS[VSC::Year] + " DOUBLE NOT NULL, "
+ SQL_IDS[VSC::Copies] + " DOUBLE NOT NULL)");

auto query = QSqlQuery(m_database);
if (query.exec("SELECT * FROM mark")) {
beginInsertRows({}, 0, query.size());
while (query.next())
m_marks.append(Mark(
query.value(SQL_IDS[VSC::Name]).toString(),
query.value(SQL_IDS[VSC::Country]).toString(),
query.value(SQL_IDS[VSC::Year]).toDouble(),
query.value(SQL_IDS[VSC::Copies]).toDouble()));
endInsertRows();
}
}

void MarkList::add(const Mark& mark) {
auto new_row = rowCount({});
   if (QSqlQuery(m_database)
    .exec(
   (QString()
+ "INSERT INTO mark("
+ SQL_IDS[VSC::Name] + ", "
+ SQL_IDS[VSC::Country] + ", "
+ SQL_IDS[VSC::Year] + ", "
+ SQL_IDS[VSC::Copies] + ") "
+ "VALUES ('%1','%2','%3','%4')")
.arg(mark.name())
.arg(mark.country())
.arg(mark.year())
.arg(mark.copies()))){

beginInsertRows({}, new_row, new_row);
m_marks.append(mark);
endInsertRows();
}
}

void MarkList::add(QString name,
QString country,
double year,
double copies) {
add(Mark(move(name), move(country), year, copies)); }
void MarkList::remove(int index) {
auto& mark = m_marks[index];
if (QSqlQuery(m_database)
.exec(
(QString()
+ "DELETE FROM mark WHERE "
+ SQL_IDS[VSC::Name] + " = '%1'")
.arg(mark.name()))) {
beginRemoveRows({}, index, index);
m_marks.removeAt(index);
endRemoveRows();
}
}
QVariant MarkList::get(int row, int col) { return
MarkList::data(QAbstractTableModel::index(row, col), Qt::DisplayRole);
}
int MarkList::rowCount(const QModelIndex& parent) const {
return static_cast<int>(m_marks.size());
}
int MarkList::columnCount(const QModelIndex& parent) const {
return VSC::Count;
}
QVariant MarkList::headerData(int section, Qt::Orientation orientation, int role) const {
if (orientation != Qt::Horizontal
|| role != Qt::DisplayRole)
return {};
switch (section) {
case VSC::Name:
return "Название марки";
case VSC::Country:
return "Страна";
case VSC::Year:
return "Год выпуска";
case VSC::Copies:
return "Тираж";
default:
return {};
}
}
QVariant MarkList::data(const QModelIndex& index, int role) const {
auto col = index.column();
const auto start = Qt::UserRole + 1;
if (role >= start
&& role < start + VSC::Count) {
col = role - start;
role = Qt::DisplayRole;
}
if (!index.isValid()
|| index.row() >= m_marks.size()
|| role != Qt::DisplayRole && role != Qt::EditRole)
return {};
auto& mark = m_marks[index.row()];
switch (col) {
case VSC::Name:
return mark.name();
case VSC::Country:
return mark.country();
case VSC::Year:
return mark.year();
case VSC::Copies:
return mark.copies();
default:
return {};
}
}
Qt::ItemFlags MarkList::flags(const QModelIndex& index) const {
if (!index.isValid())
return Qt::ItemIsEnabled;
return QAbstractTableModel::flags(index) | Qt::ItemIsEditable; }
bool MarkList::setData(const QModelIndex& index, const QVariant& value, int role) {
auto col = index.column();
const auto start = Qt::UserRole + 1;
if (role >= start
&& role < start + VSC::Count) {
col = role - start;
role = Qt::EditRole;
}
if (!index.isValid()
|| role != Qt::EditRole)
return false;
auto& mark = m_marks[index.row()];
if (!QSqlQuery(m_database)
.exec(
(QString()
+ "UPDATE mark SET "
+ SQL_IDS[col] + " = '%1' WHERE "
+ SQL_IDS[VSC::Name] + " = '%2'")
.arg(value.toString())
.arg(mark.name())))
return false;
switch (col) {
case VSC::Name:
mark.name(value.toString());
break;
case VSC::Country:
mark.country(value.toString());
break;
case VSC::Year:
mark.year(value.toDouble());
break;
case VSC::Copies:
mark.copies(value.toDouble());
break;
default:
return false;
}
emit dataChanged(index, index, {role});
return true;
}
QString roleName(int i) {
switch (i) {
case VSC::Name:
return "name";
case VSC::Country:
return "country";
case VSC::Year:
return "year";
case VSC::Copies:
return "copies";
default:
return {};
}
}
QHash<int, QByteArray> MarkList::roleNames() const { auto roles = QHash<int, QByteArray>();
for (auto i = 0; i < VSC::Count; i++)
roles.insert(
Qt::UserRole + i + 1,
roleName(i).toUtf8());
return roles;
}

