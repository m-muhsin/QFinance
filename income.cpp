#include "income.h"

bool Income::insertTransaction(Transaction* income)
{
    qDebug() << "new transaction";

    //Prepare query
    QSqlQuery query;
    query.prepare("INSERT INTO tblincome(date, amount, payer, category, description) "
                      "VALUES(:date, :amount, :payer, :category, :description)");
    query.bindValue(":date", income->getDate());
    query.bindValue(":amount", income->getAmount());
    query.bindValue(":payer", income->getParty());
    query.bindValue(":category", income->getCategory());
    query.bindValue(":description", income->getDescription());

    //Execute query
    bool isSaved = query.exec();

    qDebug() << "Date saved: " << isSaved;
    qDebug() << "Last Error: " << query.lastError();

    query.finish();

    return isSaved;

}

bool Income::updateTransaction(Transaction *income)
{

    qDebug() << "update transaction";

    //Prepare query
    QSqlQuery query;
    query.prepare("UPDATE tblincome SET date = :date, amount = :amount, payer = :payer, category = :category, "
                  "description = :description WHERE id = :id");

    query.bindValue(":id", income->getId());
    query.bindValue(":date", income->getDate());
    query.bindValue(":amount", income->getAmount());
    query.bindValue(":payer", income->getParty());
    query.bindValue(":category", income->getCategory());
    query.bindValue(":description", income->getDescription());

    //Execute query
    bool isSaved = query.exec();

    qDebug() << "Date saved: " << isSaved;
    qDebug() << "Last Error: " << query.lastError();

    query.finish();

    return isSaved;
}
