#include "addexpense.h"
#include "ui_addexpense.h"

#include <QMessageBox>

AddExpense::AddExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddExpense)
{
    ui->setupUi(this);
    expense = new Expense;

    ui->txtDate->setDate(QDate::currentDate());
}

AddExpense::~AddExpense()
{
    delete ui;
}

void AddExpense::on_btnSave_clicked()
{
    //fetch data from form
    QString date = ui->txtDate->text();
    int amount = ui->txtAmount->text().toInt();
    QString payee = ui->txtPayee->text();
    QString category = ui->txtCategory->text();
    QString description = ui->txtDescription->toPlainText();

    bool inserted = expense->insertTransaction(date, amount, payee, category, description);
    if(inserted) {
        QMessageBox::information(this, "Expense","Expense saved Successfully");
    }
    else {
        QMessageBox::warning(this, "Expense", "An error has occured. Please contact developer");
    }
}

void AddExpense::on_btnCancel_clicked()
{
    ui->txtDate->setDate(QDate::currentDate());
    ui->txtAmount->clear();
    ui->txtCategory->clear();
    ui->txtDescription->clear();
    ui->txtPayee->clear();
}
