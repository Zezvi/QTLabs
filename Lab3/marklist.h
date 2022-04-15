#ifndef MARKLIST_H
#define MARKLIST_H


#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "mark.h"

class MarkList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* markModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Mark> listOfMarks; // непосредственно данные
    QAbstractListModel *getModel();

public:
    MarkList(QObject *parent = nullptr);
    ~MarkList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            country = Qt::DisplayRole + 1,
            year = Qt::DisplayRole + 2,
            copies = Qt::DisplayRole + 3,
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& nameMark, const QString& countryMark, const QString& yearMark, const QString& copiesMark);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE QString count(const QString& textSelCopies);
    Q_INVOKABLE void edit(const QString& nameMark, const QString& countryMark, const QString& yearMark, const QString& copiesMark, const int index);
};

#endif // <MARKLIST_H
