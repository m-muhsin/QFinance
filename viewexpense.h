#ifndef VIEWEXPENSE_H
#define VIEWEXPENSE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
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
    void setupTable();

signals:
    void editTransactionClicked(QSqlQueryModel* rowModel);

private slots:
    void on_btnDelete_clicked();

    void on_btnEdit_clicked();

private:
    Ui::ViewExpense *ui;
    Transaction *expense;
    QSqlTableModel *model;
    QSqlQueryModel *queryModel;
};

#endif // VIEWEXPENSE_H
