#include "income.h"

bool Income::insertTransaction(Transaction* income)
{
    //Prepare query
    QSqlQuery query;

    if(income->getId() == -1) {
        qDebug() << "new transaction";
        query.prepare("INSERT INTO tblincome(date, amount, payer, category, description) "
                      "VALUES(:date, :amount, :payer, :category, :description)");
    } else {
        qDebug() << "update transaction";
        query.prepare("UPDATE tblincome SET date = :date, amount = :amount, payer = :payer, category = :category, "
                      "description = :description WHERE id = :id");
        query.bindValue(":id", income->getId());
    }

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
