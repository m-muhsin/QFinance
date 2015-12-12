#include "viewexpense.h"
#include "ui_viewexpense.h"

ViewExpense::ViewExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewExpense)
{
    ui->setupUi(this);
    expense = new Expense;
    setupTable();
}

ViewExpense::~ViewExpense()
{
    delete ui;
}

void ViewExpense::on_btnDelete_clicked()
{
    QModelIndexList list = ui->tblExpense->selectionModel()->selectedRows();
    qDebug() << list.count();
    expense->deleteTransaction(list);
    setupTable();
}

void ViewExpense::setupTable()
{
    ui->tblExpense->setModel(expense->viewTransaction("expense"));
    ui->tblExpense->setColumnHidden(0, true);
}
