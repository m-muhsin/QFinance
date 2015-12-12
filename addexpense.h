#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include "expense.h"

namespace Ui {
class AddExpense;
}

class AddExpense : public QWidget
{
    Q_OBJECT

public:
    explicit AddExpense(QWidget *parent = 0);
    ~AddExpense();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::AddExpense *ui;
    Transaction *expense; //polymorphism
};

#endif // ADDEXPENSE_H
