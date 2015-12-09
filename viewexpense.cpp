#include "viewexpense.h"
#include "ui_viewexpense.h"

ViewExpense::ViewExpense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewExpense)
{
    ui->setupUi(this);

    setupTable();
}

ViewExpense::~ViewExpense()
{
    delete ui;
}

void ViewExpense::deleteExpense()
{
    QModelIndexList list = ui->tblExpense->selectionModel()->selectedRows();
    while (!list.isEmpty()) {
        model->removeRows(list.last().row(), 1);
        list.removeLast();
        qDebug() << model->submitAll();
    }
    setupTable();
}

void ViewExpense::setupTable()
{
    model = new QSqlTableModel(this);
    model->setTable("tblexpense");
    model->select();
    ui->tblExpense->setModel(model);
    ui->tblExpense->setColumnHidden(0, true);
}

void ViewExpense::on_btnDelete_clicked()
{
    deleteExpense();
}
