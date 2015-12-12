#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include <QDebug>
#include <QSqlQuery>
#include "dbconn.h"

namespace Ui {
class AddExpense;
}

class AddExpense : public QWidget
{
    Q_OBJECT

public:
    explicit AddExpense(QWidget *parent = 0);
    ~AddExpense();

public slots:
    void insertExpense();

private slots:
    void on_btnSave_clicked();

private:
    Ui::AddExpense *ui;
    DbConn *dbConn;

    QString date;
    int amount;
    QString payee;
    QString category;
    QString description;
};

#endif // ADDEXPENSE_H
