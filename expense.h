#ifndef EXPENSE_H
#define EXPENSE_H

#include <QWidget>
#include <QDebug>
#include <QSqlQuery>
#include "dbconn.h"

namespace Ui {
class Expense;
}

class Expense : public QWidget
{
    Q_OBJECT

public:
    explicit Expense(QWidget *parent = 0);
    ~Expense();

public slots:
    void addExpense();

private slots:
    void on_btnSave_clicked();

private:
    Ui::Expense *ui;
    DbConn *dbConn;

    QString date;
    int amount;
    QString payee;
    QString category;
    QString description;
};

#endif // EXPENSE_H
