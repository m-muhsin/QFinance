#include "income.h"

bool Income::insertTransaction(QString date, int amount, QString payer, QString category, QString description)
{
    //Prepare query
    QSqlQuery query;
    QString sql = "INSERT INTO tblincome(date, amount, payer, category, description) "
                 "VALUES(:date, :amount, :payer, :category, :description)";
    query.prepare(sql);

    query.bindValue(":date", date);
    query.bindValue(":amount", amount);
    query.bindValue(":payer", payer);
    query.bindValue(":category", category);
    query.bindValue(":description", description);

    //Execute query
    bool isSaved = query.exec();

    qDebug() << "Date saved: " << isSaved;
    qDebug() << "Last Error: " << query.lastError();

    query.finish();

    return isSaved;

}

bool Income::updateTransaction(QString date, int amount, QString payer, QString category, QString description)
{
    //Prepare query
//    QSqlQuery query;
//    QString sql = "UPDATE tblincome SET date = :date, amount = :amount, payer = :payer,"
//                  " category = :category, description = :description) WHERE";
//    query.prepare(sql);

//    query.bindValue(":date", date);
//    query.bindValue(":amount", amount);
//    query.bindValue(":payer", payer);
//    query.bindValue(":category", category);
//    query.bindValue(":description", description);

//    //Execute query
//    bool isSaved = query.exec();

//    qDebug() << "Date saved: " << isSaved;
//    qDebug() << "Last Error: " << query.lastError();

//    query.finish();

//    return isSaved;
}
