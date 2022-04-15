#include "marklist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

MarkList::MarkList(QObject* parent):QAbstractListModel(parent)
{
    add("Святой Грааль", "США", "1868", "2");
    add("Черный Пенни", "Англия", "1840", "68808800");
    add("Голубой Маврикий", "Маврикий", "1847", "3000");
}

MarkList::~MarkList()
{

}

int MarkList::rowCount(const QModelIndex&) const
{
    return listOfMarks.size();
}


QVariant MarkList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfMarks.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfMarks.at(index.row()).getName());
                case country:
                    return QVariant(listOfMarks.at(index.row()).getCountry());
                case year:
                    return QVariant(listOfMarks.at(index.row()).getYear());
                case copies:
                    return QVariant(listOfMarks.at(index.row()).getCopies());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> MarkList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfMark";
    roles[country] = "countryOfMark";
    roles[year] = "yearOfMark";
    roles[copies] = "copiesOfMark";
       return roles;
}

void MarkList::add(const QString& nameMark, const QString& countryMark, const QString& yearMark, const QString& copiesMark){
     Mark mark;
     mark.SetName(nameMark);
     mark.SetCountry(countryMark);
     mark.SetYear(yearMark);
     mark.SetCopies(copiesMark);

    beginInsertRows(QModelIndex(),listOfMarks.size(),listOfMarks.size());
    listOfMarks.append(mark);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* MarkList::getModel(){
    return this;
}

void MarkList::del(const int index){

     if (index >= 0 && index < listOfMarks.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfMarks.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString MarkList::count(const QString& textSelCopies){
    int count = 0;
    for(int i = 0; i < listOfMarks.size(); i++)
        if(listOfMarks[i].getCopies().toInt()  <= textSelCopies.toInt())
            count++;
    QString c = QString::number(count);
    return c;



    //QMessageBox messBox;
    //messBox.setWindowTitle("Всё подсчиталось!");
    //messBox.setText("Количество марок,  тираж которых не превышает " + textSelArea + ", равно " + c + "!");
}

void MarkList::edit(const QString& nameMark, const QString& countryMark, const QString& yearMark, const QString& copiesMark, const int index) {
     if(index >= 0 && index < listOfMarks.size() )
     {
        auto& currentMark = listOfMarks[index];
        if (currentMark.getName().compare(nameMark)!=0 || currentMark.getCountry() != countryMark || currentMark.getYear() != yearMark
                || currentMark.getCopies() != copiesMark)
        {
            currentMark.SetName(nameMark);
            currentMark.SetCountry(countryMark);
            currentMark.SetYear(yearMark);
            currentMark.SetCopies(copiesMark);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfMarks[index].getCopies();
        }

     }
      else qDebug() << "Error index";
}
