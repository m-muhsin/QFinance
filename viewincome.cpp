#include "viewincome.h"
#include "ui_viewincome.h"

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
    income->deleteIncome(list);
    setupTable();
}

void ViewIncome::setupTable()
{
    ui->tblIncome->setModel(income->prepareTable()); //model
    ui->tblIncome->setColumnHidden(0, true);
}
