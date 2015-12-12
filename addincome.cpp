#include "addincome.h"
#include "ui_addincome.h"

#include <QMessageBox>

AddIncome::AddIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddIncome)
{
    ui->setupUi(this);
    income = new Income;

    QDate date = QDate::currentDate();
    ui->txtDate->setDate(date);
}

AddIncome::~AddIncome()
{
    delete ui;
}

void AddIncome::on_btnSave_clicked()
{
    //fetch data from form
    QString date = ui->txtDate->text();
    int amount = ui->txtAmount->text().toInt();
    QString payer = ui->txtPayer->text();
    QString category = ui->txtCategory->text();
    QString description = ui->txtDescription->toPlainText();

    bool inserted = income->insertIncome(date, amount, payer, category, description);
    if(inserted) {
        QMessageBox::information(this, "Income","Income saved Successfully");
    }
    else {
        QMessageBox::warning(this, "Income", "An error has occured. Please contact developer");
    }
}

void AddIncome::on_Cancel_clicked()
{

}
