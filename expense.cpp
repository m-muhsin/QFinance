#include "expense.h"
#include "ui_expense.h"

#include <QMessageBox>

Expense::Expense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Expense)
{
    ui->setupUi(this);

    QDate date = QDate::currentDate();
    ui->txtDate->setDate(date);
}

Expense::~Expense()
{
    delete ui;
}

void Expense::addExpense()
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
        QMessageBox::information(this, "Expense","Saved Expense Successfully");
    }
    else {
        QMessageBox::warning(this, "Expense", query.lastError().text());
    }
}

void Expense::on_btnSave_clicked()
{
    addExpense();
}
