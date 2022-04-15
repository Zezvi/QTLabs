#include "dialogdelegate.h"
#include "QtWidgets"
#include "editmarkdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditMarkDialog* editDialog = new EditMarkDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Country = model->data(model->index(index.row(),2,index)).toString();
        QString Issue_date = model->data(model->index(index.row(),3,index)).toString();
        QString Number = model->data(model->index(index.row(),4,index)).toString();

        editDialog->SetUpDialog(ID, Name, Country, Issue_date, Number);

        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->country());
            model->setData(model->index(index.row(),3,index),editDialog->issue_date());
            model->setData(model->index(index.row(),4,index),editDialog->number());

            editDialog->deleteLater();
        }
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
