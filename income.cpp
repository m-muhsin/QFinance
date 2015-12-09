#include "income.h"
#include "ui_income.h"

#include <QMessageBox>

Income::Income(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Income)
{
    ui->setupUi(this);

    QDate date = QDate::currentDate();
    ui->txtDate->setDate(date);
}

Income::~Income()
{
    delete ui;
}

void Income::on_btnSave_clicked()
{
    addIncome();
}

void Income::on_Cancel_clicked()
{

}

void Income::addIncome()
{
    //fetch data from form
    date = ui->txtDate->text();
    amount = ui->txtAmount->text().toInt();
    payer = ui->txtPayer->text();
    category = ui->txtCategory->text();
    description = ui->txtDescription->toPlainText();

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

    if(isSaved) {
        QMessageBox::information(this, "Income","Saved Income Successfully");
    }
    else {
        QMessageBox::warning(this, "Income", query.lastError().text());
    }

}
