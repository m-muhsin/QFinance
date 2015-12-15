#ifndef VIEWINCOME_H
#define VIEWINCOME_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include "income.h"

namespace Ui {
class ViewIncome;
}

class ViewIncome : public QWidget
{
    Q_OBJECT

public:
    explicit ViewIncome(QWidget *parent = 0);
    ~ViewIncome();
    void setupTable();

signals:
    void editTransactionClicked(QSqlQueryModel* rowModel);

private slots:
    void on_btnDelete_clicked();

    void on_btnEdit_clicked();

private:
    Ui::ViewIncome *ui;
    Transaction *income;
    QSqlTableModel *model;
    QSqlQueryModel *queryModel;
};

#endif // VIEWINCOME_H
