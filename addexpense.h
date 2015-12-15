#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include "expense.h"
#include "calculator.h"

namespace Ui {
class AddExpense;
}

class AddExpense : public QWidget
{
    Q_OBJECT

public:
    explicit AddExpense(QWidget *parent = 0);
    ~AddExpense();
    void setupEdit(QSqlQueryModel *rowModel);

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

    void on_btnOpenCalculator_clicked();

    void equalsClicked(QString);

private:
    Ui::AddExpense *ui;
    Transaction *expense; //polymorphism
    Calculator *calculator;
    int tempId = -1;
};

#endif // ADDEXPENSE_H
