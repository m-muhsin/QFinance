#ifndef EXPENSE_H
#define EXPENSE_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"

class Expense: public Transaction
{

public slots:
    bool insertTransaction(QString date, int amount, QString payee, QString category, QString description);
    bool updateTransaction(QString date, int amount, QString payer, QString category, QString description);

};

#endif // EXPENSE_H
