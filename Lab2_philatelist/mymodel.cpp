#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Mark* std1 = new Mark("1","Святой Грааль","США","1868","2",this);
    Mark* std2 = new Mark("2","Черный Пенни","Англия","1840","68 808 000",this);
    Mark* std3 = new Mark("3","Голубой Маврикий","Маврикий","1847","3000",this);
    AddMark(std1);
    AddMark(std2);
    AddMark(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return marks.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Mark* std = marks.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Country();}
        else if (index.column() == 3){Value = std->Issue_date();}
        else if (index.column() == 4){Value = std->Number();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Страна");
            case 3:
                return QString("Год выпуска");
            case 4:
                return QString("Тираж");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Mark* std = marks.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetCountry(value.toString());}
        else if (index.column() == 3){std->SetIssue_date(value.toString());}
        else if (index.column() == 4){std->SetNumber(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddMark(Mark* mark)
{
    beginInsertRows(QModelIndex(),marks.size(),marks.size());
    marks.append(mark);
    endInsertRows();
    //emit layoutChanged();
}

void MyModel::DeleteMark(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    marks.removeAt(row);
    endRemoveRows();
    //emit layoutChanged();
}

