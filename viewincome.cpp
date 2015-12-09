#include "viewincome.h"
#include "ui_viewincome.h"

ViewIncome::ViewIncome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewIncome)
{
    ui->setupUi(this);
    setupTable();
//    model = new QSqlTableModel(this);
//    model->setTable("tblincome");
//    model->select();
//    ui->tblIncome->setModel(model);
}

ViewIncome::~ViewIncome()
{
    delete ui;
}

void ViewIncome::on_btnDelete_clicked()
{
    deleteIncome();
}

void ViewIncome::deleteIncome()
{
    QModelIndexList list = ui->tblIncome->selectionModel()->selectedRows();
    qDebug() << list.count();
    while (!list.isEmpty()) {
        model->removeRows(list.last().row(), 1);
        list.removeLast();
        qDebug() << model->submitAll();
    }
    setupTable();
}

void ViewIncome::setupTable()
{
    model = new QSqlTableModel(this);
    model->setTable("tblincome");
    model->select();
    ui->tblIncome->setModel(model);
    ui->tblIncome->setColumnHidden(0, true);
}
