#ifndef VIEWINCOME_H
#define VIEWINCOME_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
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

private slots:
    void on_btnDelete_clicked();

private:
    Ui::ViewIncome *ui;
    Transaction *income;
    QSqlTableModel *model;
};

#endif // VIEWINCOME_H
