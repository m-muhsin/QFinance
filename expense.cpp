#include "expense.h"

bool Expense::insertTransaction(Transaction* expense)
{
    //Prepare query
    QSqlQuery query;

    if(expense->getId() == -1) {
        qDebug() << "new transaction";
        query.prepare("INSERT INTO tblexpense(date, amount, payee, category, description) "
                      "VALUES(:date, :amount, :payee, :category, :description)");
    } else {
        qDebug() << "update transaction";
        query.prepare("UPDATE tblexpense SET date = :date, amount = :amount, payee = :payee, category = :category, "
                      "description = :description WHERE id = :id");
        query.bindValue(":id", expense->getId());
    }

    query.bindValue(":date", expense->getDate());
    query.bindValue(":amount", expense->getAmount());
    query.bindValue(":payee", expense->getParty());
    query.bindValue(":category", expense->getCategory());
    query.bindValue(":description", expense->getDescription());

    //Execute query
    bool isSaved = query.exec();

    qDebug() << "Date saved: " << isSaved;
    qDebug() << "Last Error: " << query.lastError();

    query.finish();

    return isSaved;

}
