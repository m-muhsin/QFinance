#ifndef INCOME_H
#define INCOME_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include "dbconn.h"

class Income
{
public:
    Income();

public slots:
    bool insertTransaction(QString date, int amount, QString payer, QString category, QString description);
    QSqlTableModel* viewTransaction();
    void deleteTransaction(QModelIndexList list);

private:
    DbConn *dbConn;
    QSqlTableModel *model;

    QString date;
    int amount;
    QString payer;
    QString category;
    QString description;
};

#endif // INCOME_H
