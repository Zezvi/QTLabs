#include "marklist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

MarkList::MarkList(QObject* parent):QAbstractListModel(parent)
{
    add("Святой Грааль", "США", "1868", "2");
    add("Черный Пенни", "Англия", "1840", "68 808 800");
    add("Голубой Маврикий", "Маврикий", "1847", "3000");
}

MarkList::~MarkList()
{

}

int MarkList::rowCount(const QModelIndex&) const
{
    return listOfRivers.size();
}


QVariant MarkList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfRivers.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfRivers.at(index.row()).getName());
                case lenght:
                    return QVariant(listOfRivers.at(index.row()).getLenght());
                case flow:
                    return QVariant(listOfRivers.at(index.row()).getFlow());
                case runoff:
                    return QVariant(listOfRivers.at(index.row()).getRunoff());
                case area:
                    return QVariant(listOfRivers.at(index.row()).getArea());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> MarkList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfRiver";
    roles[lenght] = "lenghtOfRiver";
    roles[flow] = "flowOfRiver";
    roles[runoff] = "runoffOfRiver";
    roles[area] = "areaOfRiver";
       return roles;
}

void MarkList::add(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const QString& areaRiv){
     Mark mark;
     mark.setName(nameMark);
     mark.setCountry(countryMark);
     mark.setYear(yearMark);
     mark.setCopies(copiesMark);

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

QString MarkList::count(const QString& textSelArea){
    int count = 0;
    for(int i = 0; i < listOfRivers.size(); i++)
        if(listOfMarks[i].getCopies().toInt() > textSelCopies.toInt())
            count++;
    QString c = QString::number(count);
    return c;
    //QMessageBox messBox;
    //messBox.setWindowTitle("Всё подсчиталось!");
    //messBox.setText("Количество марок, где тираж превышает " + textSelArea + ", равно " + c + "!");
}

void MarkList::edit(const QString& nameMark, const QString& countryMark, const QString& yearMark, const QString& copiesMark const int index) {
     if(index >= 0 && index < listOfMarks.size() )
     {
        auto& currentMark = listOfMarks[index];
        if (currentMark.getName().compare(nameMark)!=0 || currentMark.getCountry() != countryMark || currentMark.getYear() != yearMark
                || currentMark.getCoppies() != copiesMark)
        {
            currentRiver.setName(nameMark);
            currentRiver.setCountry(countryMark);
            currentRiver.setYear(yearMark);
            currentRiver.setCopies(copiesMark);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfMarks[index].getCopies();
        }

     }
      else qDebug() << "Error index";
}
