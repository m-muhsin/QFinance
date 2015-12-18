#include "addexpense.h"
#include "ui_addexpense.h"

AddExpense::AddExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddExpense)
{
    ui->setupUi(this);
    expense = new Expense;
    tempId = -1;
    calculator = new Calculator;
    ui->txtDate->setDate(QDate::currentDate());
    ui->cmbCategory->setModel(expense->getCategoriesList("expense"));

    connect(calculator, SIGNAL(btnEqual_clicked(QString)), this, SLOT(equalsClicked(QString)));
}

AddExpense::~AddExpense()
{
    delete ui;
}

void AddExpense::setupEdit(QSqlTableModel *tableModel)
{
    ui->lblHeader->setText("Edit Expense");
    QString format = "dd/MM/yyyy";
    this->tempId = tableModel->record(0).value(0).toInt();
    ui->txtDate->setDate(QDate::fromString(tableModel->record(0).value(1).toString(), format));
    ui->txtAmount->setText(tableModel->record(0).value(2).toString());
    ui->txtPayee->setText(tableModel->record(0).value(3).toString());
    ui->cmbCategory->setCurrentText(tableModel->record(0).value(4).toString());
    ui->txtDescription->setText(tableModel->record(0).value(5).toString());
}

void AddExpense::on_btnSave_clicked()
{
    Transaction* expense = new Expense;
    expense->setId(this->tempId);
    expense->setDate(ui->txtDate->text());
    expense->setAmount(ui->txtAmount->text().toInt());
    expense->setParty(ui->txtPayee->text());
    expense->setCategory(ui->cmbCategory->currentText());
    expense->setDescription(ui->txtDescription->toPlainText());

    if(this->tempId == -1)  {
        bool inserted = expense->insertTransaction(expense);
        if(inserted) {
                QMessageBox::information(this, "Expense","Expense saved Successfully");
            on_btnCancel_clicked();
        }
        else
            QMessageBox::warning(this, "Expense", "An error has occured. Please try again or contact developer");
    }
    else {
        bool inserted = expense->updateTransaction(expense);
        if(inserted) {
            QMessageBox::information(this, "Expense", "Expense updated Successfully");
            on_btnCancel_clicked();
        }
        else
            QMessageBox::warning(this, "Expense", "An error has occured. Please try again or contact developer");
    }

}

void AddExpense::on_btnCancel_clicked()
{
    ui->txtDate->setDate(QDate::currentDate());
    ui->txtAmount->clear();
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
