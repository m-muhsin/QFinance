#include "income.h"

Income::Income()
{

}

bool Income::insertIncome(QString date, int amount, QString payer, QString category, QString description)
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

QSqlTableModel* Income::prepareTable()
{
    model = new QSqlTableModel;
    model->setTable("tblincome");
    model->select();
    return model;
}

void Income::deleteIncome(QModelIndexList list)
{
    qDebug() << "inside deleteIncome";
    while (!list.isEmpty()) {
        model->removeRows(list.last().row(), 1);
        list.removeLast();
        qDebug() << model->submitAll();
    }
}
