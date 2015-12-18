#include "transaction.h"

QSqlTableModel* Transaction::viewTransaction(QString type)
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tbl"+type);
    tableModel->select();
    return tableModel;
}

QSqlTableModel* Transaction::getTransaction(QString type, int id)
{
//    QString in = QString::number(id);
//    queryModel = new QSqlQueryModel;
//    queryModel->setQuery(QString
//                         ("SELECT * FROM '%1' WHERE id = '%2'")
//                         .arg("tbl"+type).arg(in));

//    return queryModel;
    tableModel = new QSqlTableModel;
    tableModel->setTable("tbl"+type);
    tableModel->select();
    tableModel->setFilter("id="+QString::number(id));
    return tableModel;
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

QStandardItemModel* Transaction::getCategoriesList(QString type)
{
    itemModel = new QStandardItemModel;
    QSqlQuery query;
    QString sql = "select DISTINCT catname from tbl"+type+"cat";
    if(query.exec(sql)) {
        int index = 0;
        while (query.next()) {
            QString cat = query.value(0).toString();
            QStandardItem *item = new QStandardItem(cat);
            itemModel->setItem(index++, item);
        }
    } else {
        qDebug() << "Error loading Category: " << query.lastError();
    }
    return itemModel;
}

QString Transaction::getCategory() const
{
    return category;
}

QString Transaction::getDescription() const
{
    return description;
}

void Transaction::setDescription(const QString &value)
{
    description = value;
}

void Transaction::setCategory(const QString &value)
{
    category = value;
}

QString Transaction::getParty() const
{
    return party;
}

void Transaction::setParty(const QString &value)
{
    party = value;
}

int Transaction::getAmount() const
{
    return amount;
}

void Transaction::setAmount(int value)
{
    amount = value;
}

int Transaction::getId() const
{
    return id;
}

void Transaction::setId(int value)
{
    id = value;
}

QString Transaction::getDate() const
{
    return date;
}

void Transaction::setDate(const QString &value)
{
    date = value;
}

