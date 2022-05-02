#pragma once
#include <QAbstractListModel>
#include <QSqlDatabase>
#include "mark.h"
class MarkList : public QAbstractTableModel { Q_OBJECT
QList<Mark> m_marks;
QSqlDatabase m_database;
public:
MarkList();
void add(const Mark& mark);
Q_INVOKABLE void add(QString name,
QString country,
double year,
double copies);
Q_INVOKABLE void remove(int index);
Q_INVOKABLE QVariant get(int row, int col);
public:
int rowCount(const QModelIndex&) const override;
int columnCount(const QModelIndex&) const override;
QVariant headerData(int, Qt::Orientation, int) const override; QHash<int, QByteArray> roleNames() const override;
QVariant data(const QModelIndex&, int) const override; Qt::ItemFlags flags(const QModelIndex&) const override;
bool setData(const QModelIndex&, const QVariant&, int) override; };






