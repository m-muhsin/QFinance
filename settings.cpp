#include "settings.h"
#include "ui_settings.h"
#include <QDir>
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    income = new Income;
    expense = new Expense;
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
                        tr("Enter Income Category name:"), QLineEdit::Normal,"", &ok);
    if (ok && !newCat.isEmpty())
        qDebug() << newCat;
}

void Settings::on_btnExpenseCat_Add_clicked()
{
    bool ok;
    QString newCat = QInputDialog::getText(this, tr("New"),
                        tr("Enter Expense Category name:"), QLineEdit::Normal,"", &ok);
    if (ok && !newCat.isEmpty())
        qDebug() << newCat;
}
