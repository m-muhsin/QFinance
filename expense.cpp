#include "expense.h"

bool Expense::insertTransaction(QString date, int amount, QString payee, QString category, QString description)
{
    //Prepare query
    QSqlQuery query;
    QString sql = "INSERT INTO tblexpense(date, amount, payee, category, description) "
                 "VALUES(:date, :amount, :payee, :category, :description)";
    query.prepare(sql);

    query.bindValue(":date", date);
    query.bindValue(":amount", amount);
    query.bindValue(":payee", payee);
    query.bindValue(":category", category);
    query.bindValue(":description", description);

    //Execute query
    bool isSaved = query.exec();

    qDebug() << "Date saved: " << isSaved;
    qDebug() << "Last Error: " << query.lastError();

    query.finish();

    return isSaved;

}
