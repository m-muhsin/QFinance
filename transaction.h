#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include "dbconn.h"

class Transaction
{
public:
    Transaction();

public slots:
    virtual bool insertTransaction(QString date, int amount, QString party, QString category, QString description) = 0;
    QSqlTableModel* viewTransaction(QString type);
    void deleteTransaction(QModelIndexList list);

private:
    DbConn *dbConn;
    QSqlTableModel *model;

    QString date;
    int amount;
    QString category;
    QString description;
};

#endif // TRANSACTION_H
