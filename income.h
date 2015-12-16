#ifndef INCOME_H
#define INCOME_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"

class Income: public Transaction
{

public slots:
    bool insertTransaction(Transaction* income);
    bool updateTransaction(Transaction* income);

};

#endif // INCOME_H
