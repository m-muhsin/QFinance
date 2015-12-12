#ifndef ADDINCOME_H
#define ADDINCOME_H

#include <QWidget>
#include "income.h"


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

private:
    Ui::AddIncome *ui;
    Transaction *income; //polymorphism
};

#endif // ADDINCOME_H
