#include "addincome.h"
#include "ui_addincome.h"

AddIncome::AddIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddIncome)
{
    ui->setupUi(this);
    income = new Income;
    calculator = new Calculator;
    ui->txtDate->setDate(QDate::currentDate());
    ui->cmbCategory->setModel(income->getCategory("income"));

    qDebug() << "cmb model: " << ui->cmbCategory->model();
    connect(calculator, SIGNAL(btnEqual_clicked(QString)), this, SLOT(equalsClicked(QString)));

}

AddIncome::~AddIncome()
{
    delete ui;
}

void AddIncome::setupEdit(QSqlQueryModel *rowModel)
{
    ui->lblHeader->setText("Edit Income");
    QString format = "dd/MM/yyyy";
    ui->txtDate->setDate(QDate::fromString(rowModel->record(0).value(1).toString(), format));
    ui->txtAmount->setText(rowModel->record(0).value(2).toString());
    ui->txtPayer->setText(rowModel->record(0).value(3).toString());
    ui->cmbCategory->setCurrentText(rowModel->record(0).value(4).toString());
    ui->txtDescription->setText(rowModel->record(0).value(5).toString());

}

void AddIncome::on_btnSave_clicked()
{
    //fetch data from form
    QString date = ui->txtDate->text();
    int amount = ui->txtAmount->text().toInt();
    QString payer = ui->txtPayer->text();
    QString category = ui->cmbCategory->currentText();
    QString description = ui->txtDescription->toPlainText();

    bool inserted = income->insertTransaction(date, amount, payer, category, description);
    if(inserted) {
        QMessageBox::information(this, "Income", "Income saved Successfully");
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
//    ui->txtCategory->clear();
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
