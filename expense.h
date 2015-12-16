#ifndef EXPENSE_H
#define EXPENSE_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"

class Expense: public Transaction
{

public slots:
    bool insertTransaction(Transaction* expense);
    bool updateTransaction(Transaction* expense);

};

#endif // EXPENSE_H
