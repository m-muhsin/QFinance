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
    bool insertIncome(QString date, int amount, QString payer, QString category, QString description);
    QSqlTableModel* prepareTable();
    void deleteIncome(QModelIndexList list);

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
