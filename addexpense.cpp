#include "addexpense.h"
#include "ui_addexpense.h"

#include <QMessageBox>

AddExpense::AddExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddExpense)
{
    ui->setupUi(this);

    QDate date = QDate::currentDate();
    ui->txtDate->setDate(date);
}

AddExpense::~AddExpense()
{
    delete ui;
}

void AddExpense::insertExpense()
{
    //fetch data from form
    date = ui->txtDate->text();
    amount = ui->txtAmount->text().toInt();
    payee = ui->txtPayee->text();
    category = ui->txtCategory->text();
    description = ui->txtDescription->toPlainText();

    //prepare query
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

    if(isSaved) {
        QMessageBox::information(this, "Expense", "Expense saved Successfully");
    }
    else {
        QMessageBox::warning(this, "Expense", "An error has occured. Please contact developer");
    }
}

void AddExpense::on_btnSave_clicked()
{
    insertExpense();
}
