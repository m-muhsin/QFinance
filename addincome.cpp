#include "addincome.h"
#include "ui_addincome.h"

AddIncome::AddIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddIncome)
{
    ui->setupUi(this);
    income = new Income;
    tempId = -1;
    calculator = new Calculator;
    ui->txtDate->setDate(QDate::currentDate());
    ui->cmbCategory->setModel(income->getCategoriesList("income"));

    qDebug() << "cmb model: " << ui->cmbCategory->model();

    connect(ui->btnSave, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->btnClear, SIGNAL(clicked(bool)), this, SLOT(clear()));
    connect(ui->btnOpenCalculator, SIGNAL(clicked(bool)), this, SLOT(openCalculator()));
    connect(calculator, SIGNAL(equalsClicked(QString)), this, SLOT(onEqualsClicked(QString)));

}

AddIncome::~AddIncome()
{
    delete ui;
}

void AddIncome::setupEdit(QSqlTableModel *tableModel)
{
    ui->lblHeader->setText("Edit Income");
    QString format = "dd/MM/yyyy";
    this->tempId = tableModel->record(0).value(0).toInt();
    ui->txtDate->setDate(QDate::fromString(tableModel->record(0).value(1).toString(), format));
    ui->txtAmount->setText(tableModel->record(0).value(2).toString());
    ui->txtPayer->setText(tableModel->record(0).value(3).toString());
    ui->cmbCategory->setCurrentText(tableModel->record(0).value(4).toString());
    ui->txtDescription->setText(tableModel->record(0).value(5).toString());
}

void AddIncome::save()
{
    Transaction* income = new Income;
    income->setId(this->tempId);
    income->setDate(ui->txtDate->text());
    income->setAmount(ui->txtAmount->text().toInt());
    income->setParty(ui->txtPayer->text());
    income->setCategory(ui->cmbCategory->currentText());
    income->setDescription(ui->txtDescription->toPlainText());

    if(income->getParty() == NULL || income->getDescription() == NULL) {
        QMessageBox::warning(this, "Fields empty", "Please make sure all fields are entered");
        return;
    }
    else if(income->getAmount() <= 0) {
        QMessageBox::warning(this, "Wrong amount", "Amount must be a valid number");
        return;
    }

    if(this->tempId == -1) {
        bool inserted = income->insertTransaction(income);
        if(inserted) {
            QMessageBox::information(this, "Income", "Income saved Successfully");
            clear();
        }
        else
            QMessageBox::warning(this, "Income", "An error has occured. Please try again or contact developer");
    }
    else {
        bool inserted = income->updateTransaction(income);
        if(inserted) {
            QMessageBox::information(this, "Income", "Income updated Successfully");
            clear();
        }
        else
            QMessageBox::warning(this, "Income", "An error has occured. Please try again or contact developer");
    }
}

void AddIncome::clear()
{
    ui->txtDate->setDate(QDate::currentDate());
    ui->txtAmount->clear();
    ui->txtDescription->clear();
    ui->txtPayer->clear();
}

void AddIncome::openCalculator()
{
    calculator->show();
}

void AddIncome::onEqualsClicked(QString answer)
{
    ui->txtAmount->setText(answer);
}
