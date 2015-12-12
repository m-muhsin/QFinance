#ifndef EXPENSE_H
#define EXPENSE_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include "dbconn.h"

class Expense
{
public:
    Expense();

public slots:
    bool insertTransaction(QString date, int amount, QString payee, QString category, QString description);
    QSqlTableModel* viewTransaction();
    void deleteTransaction(QModelIndexList list);

private:
    DbConn *dbConn;
    QSqlTableModel *model;

    QString date;
    int amount;
    QString payee;
    QString category;
    QString description;
};

#endif // EXPENSE_H
