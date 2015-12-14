#include "addincome.h"
#include "ui_addincome.h"

#include <QMessageBox>

AddIncome::AddIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddIncome)
{
    ui->setupUi(this);
    income = new Income;
    calculator = new Calculator;
    ui->txtDate->setDate(QDate::currentDate());

    connect(calculator, SIGNAL(btnEqual_clicked(QString)), this, SLOT(equalsClicked(QString)));

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

    bool inserted = income->insertTransaction(date, amount, payer, category, description);
    if(inserted) {
        QMessageBox::information(this, "Income","Income saved Successfully");
        on_Cancel_clicked();
    }
    else {
        QMessageBox::warning(this, "Income", "An error has occured. Please contact developer");
    }
}

void AddIncome::on_Cancel_clicked()
{
    ui->txtDate->setDate(QDate::currentDate());
    ui->txtAmount->clear();
    ui->txtCategory->clear();
    ui->txtDescription->clear();
    ui->txtPayer->clear();
}

void AddIncome::on_btnOpenCalculator_clicked()
{
    calculator->show();
}

void AddIncome::equalsClicked(QString amount)
{
    ui->txtAmount->setText(amount);

}
