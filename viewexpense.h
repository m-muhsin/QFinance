#ifndef VIEWEXPENSE_H
#define VIEWEXPENSE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include "expense.h"

namespace Ui {
class ViewExpense;
}

class ViewExpense : public QWidget
{
    Q_OBJECT

public:
    explicit ViewExpense(QWidget *parent = 0);
    ~ViewExpense();

private slots:
    void on_btnDelete_clicked();

private:
    Ui::ViewExpense *ui;
    Transaction *expense;
    QSqlTableModel *model;

    void setupTable();
};

#endif // VIEWEXPENSE_H
