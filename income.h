#ifndef INCOME_H
#define INCOME_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include "dbconn.h"

namespace Ui {
class Income;
}

class Income : public QWidget
{
    Q_OBJECT

public:
    explicit Income(QWidget *parent = 0);
    ~Income();

private slots:
    void on_btnSave_clicked();

    void on_Cancel_clicked();

public slots:
    void addIncome();

private:
    Ui::Income *ui;
    DbConn *dbConn;

    QString date;
    int amount;
    QString payer;
    QString category;
    QString description;
};

#endif // INCOME_H
