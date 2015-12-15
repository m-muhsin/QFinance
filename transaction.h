#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include <QStandardItemModel>
#include <QStandardItem>
#include "dbconn.h"

class Transaction
{
public:
    Transaction();

public slots:
    virtual bool insertTransaction(QString date, int amount, QString party, QString category, QString description) = 0;
    QSqlTableModel* viewTransaction(QString type);
    QSqlQueryModel* getTransaction(QString type, int id);
    void deleteTransaction(QModelIndexList list);
    QStandardItemModel* getCategory(QString type);

private:
    DbConn *dbConn;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    QStandardItemModel *itemModel;

    QString date;
    int amount;
    QString category;
    QString description;
};

#endif // TRANSACTION_H
