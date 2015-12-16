#include "settings.h"
#include "ui_settings.h"

#include <QSqlRecord>
#include <QSqlField>

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    income = new Income;
    expense = new Expense;
//    ui->btnDeleteCat->setVisible(false);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_btnIncomeCat_clicked()
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tblincomecat");
    tableModel->select();
    tableModel->setHeaderData(1, Qt::Horizontal,"Income Categories",0);
    ui->tblCategory->setModel(tableModel);
    ui->tblCategory->setColumnHidden(0, true);

    ui->tblCategory->horizontalHeader()->setStretchLastSection(true);
}

void Settings::on_btnExpenseCat_clicked()
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tblexpensecat");
    tableModel->select();
    tableModel->setHeaderData(1, Qt::Horizontal,"Expense Categories",0);
    ui->tblCategory->setModel(tableModel);
    ui->tblCategory->setColumnHidden(0, true);
    ui->tblCategory->horizontalHeader()->setStretchLastSection(true);

}

void Settings::on_btnIncomeCat_Add_clicked()
{
    bool ok;
    QString newCat = QInputDialog::getText(this, tr("New"),
                        tr("Enter New Category name:"), QLineEdit::Normal,"", &ok);
    if (ok && !newCat.isEmpty())
        qDebug() << newCat;

    int lastRecordId = tableModel->record(tableModel->rowCount()-1).value(0).toInt();

    QSqlField field1("id", QVariant::Int);
    field1.setValue(lastRecordId+1);

    QSqlField field2("catname", QVariant::String);
    field2.setValue(QString(newCat));

    QSqlRecord record;

    record.insert(0,field1);
    record.insert(1,field2);

    tableModel->insertRecord(-1, record);

}

void Settings::on_btnDelete_clicked()
{
    QModelIndexList selectedRow = ui->tblCategory->selectionModel()->selectedRows();

    while (!selectedRow.isEmpty()) {
        tableModel->removeRows(selectedRow.last().row(), 1);
        selectedRow.removeLast();
        qDebug() << tableModel->submitAll();
    }
}

void Settings::on_btnExpenseCat_3_clicked()
{

}
