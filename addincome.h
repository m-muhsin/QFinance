#ifndef ADDINCOME_H
#define ADDINCOME_H

#include <QWidget>
#include <QSqlQueryModel>
#include "income.h"
#include "calculator.h"

namespace Ui {
class AddIncome;
}

class AddIncome : public QWidget
{
    Q_OBJECT

public:
    explicit AddIncome(QWidget *parent = 0);
    ~AddIncome();

private slots:
    void on_btnSave_clicked();

    void on_Cancel_clicked();

    void on_btnOpenCalculator_clicked();

    void equalsClicked(QString);

private:
    Ui::AddIncome *ui;
    Transaction *income; //polymorphism
    Calculator *calculator;
};

#endif // ADDINCOME_H
