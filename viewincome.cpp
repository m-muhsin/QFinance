#include "viewincome.h"
#include "ui_viewincome.h"
#include<QSqlRecord>

ViewIncome::ViewIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewIncome)
{
    ui->setupUi(this);
    income = new Income;
    setupTable();
}

ViewIncome::~ViewIncome()
{
    delete ui;
}

void ViewIncome::on_btnDelete_clicked()
{
    QModelIndexList list = ui->tblIncome->selectionModel()->selectedRows();
    qDebug() << list.count();
    income->deleteTransaction(list);
    setupTable();
}

void ViewIncome::setupTable()
{
    ui->tblIncome->setModel(income->viewTransaction("income")); //model
    ui->tblIncome->setColumnHidden(0, true);
}

void ViewIncome::on_btnEdit_clicked()
{
    qDebug() << "inside on_btnEdit_clicked()";
    QModelIndexList selectedRow = ui->tblIncome->selectionModel()->selectedRows();
    QModelIndex index = selectedRow.takeFirst();
    int in = index.data().toInt();
    queryModel = income->getTransaction("income", in);
    emit editTransactionClicked("income", queryModel);

}
