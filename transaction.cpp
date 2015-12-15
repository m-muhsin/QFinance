#include "transaction.h"

Transaction::Transaction()
{

}

QSqlTableModel* Transaction::viewTransaction(QString type)
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tbl"+type);
    tableModel->select();
    return tableModel;
}

QSqlQueryModel* Transaction::getTransaction(QString type, int id)
{
    QString in = QString::number(id);
    queryModel = new QSqlQueryModel;
    queryModel->setQuery(QString
                         ("SELECT * FROM '%1' WHERE id = '%2'")
                         .arg("tbl"+type).arg(in));

    return queryModel;
}

void Transaction::deleteTransaction(QModelIndexList list)
{
    qDebug() << "inside deleteTransaction";
    while (!list.isEmpty()) {
        tableModel->removeRows(list.last().row(), 1);
        list.removeLast();
        qDebug() << tableModel->submitAll();
    }
}

QStandardItemModel* Transaction::getCategory(QString type)
{
    itemModel = new QStandardItemModel;
    QSqlQuery query;
    QString sql = "select * from tbl"+type+"cat";
    if(query.exec(sql)) {
        int index = 0;
        while (query.next()) {
            QString cat = query.value(1).toString();
            QStandardItem *item = new QStandardItem(cat);
            itemModel->setItem(index++, item);
        }
    } else {
        qDebug() << "Error loading Category: " << query.lastError();
    }
    return itemModel;
}

