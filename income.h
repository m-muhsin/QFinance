#ifndef INCOME_H
#define INCOME_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"

class Income: public Transaction
{

public slots:
    bool insertTransaction(QString date, int amount, QString payer, QString category, QString description);

private:
    QString payer;

};

#endif // INCOME_H
