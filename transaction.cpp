#include "transaction.h"

Transaction::Transaction()
{

}

QSqlTableModel* Transaction::viewTransaction(QString type)
{
    model = new QSqlTableModel;
    model->setTable("tbl"+type);
    model->select();
    return model;
}

void Transaction::deleteTransaction(QModelIndexList list)
{
    qDebug() << "inside deleteTransaction";
    while (!list.isEmpty()) {
        model->removeRows(list.last().row(), 1);
        list.removeLast();
        qDebug() << model->submitAll();
    }
}

