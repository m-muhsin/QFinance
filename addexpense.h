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

private:
    Ui::AddExpense *ui;
    Expense *expense;
};

#endif // ADDEXPENSE_H
