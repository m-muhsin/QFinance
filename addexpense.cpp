#include "addexpense.h"
#include "ui_addexpense.h"

AddExpense::AddExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddExpense)
{
    ui->setupUi(this);
    expense = new Expense;
    calculator = new Calculator;
    ui->txtDate->setDate(QDate::currentDate());
    ui->cmbCategory->setModel(expense->getCategory("expense"));

    connect(calculator, SIGNAL(btnEqual_clicked(QString)), this, SLOT(equalsClicked(QString)));
}

AddExpense::~AddExpense()
{
    delete ui;
}

void AddExpense::setupEdit(QSqlQueryModel *rowModel)
{
    ui->lblHeader->setText("Edit Expense");
    QString format = "dd/MM/yyyy";
    ui->txtDate->setDate(QDate::fromString(rowModel->record(0).value(1).toString(), format));
    ui->txtAmount->setText(rowModel->record(0).value(2).toString());
    ui->txtPayee->setText(rowModel->record(0).value(3).toString());
    ui->cmbCategory->setCurrentText(rowModel->record(0).value(4).toString());
    ui->txtDescription->setText(rowModel->record(0).value(5).toString());
}

void AddExpense::on_btnSave_clicked()
{
    //fetch data from form
    QString date = ui->txtDate->text();
    int amount = ui->txtAmount->text().toInt();
    QString payee = ui->txtPayee->text();
    QString category = ui->cmbCategory->currentText();
    QString description = ui->txtDescription->toPlainText();

    bool inserted = expense->insertTransaction(date, amount, payee, category, description);
    if(inserted) {
        QMessageBox::information(this, "Expense","Expense saved Successfully");
        on_btnCancel_clicked();
    }
    else {
        QMessageBox::warning(this, "Expense", "An error has occured. Please contact developer");
    }
}

void AddExpense::on_btnCancel_clicked()
{
    ui->txtDate->setDate(QDate::currentDate());
    ui->txtAmount->clear();
//    ui->txtCategory->clear();
    ui->txtDescription->clear();
    ui->txtPayee->clear();
}

void AddExpense::on_btnOpenCalculator_clicked()
{
    calculator->show();
}

void AddExpense::equalsClicked(QString amount)
{
    ui->txtAmount->setText(amount);
}
