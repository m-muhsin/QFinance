#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QInputDialog>
#include <QDebug>
#include "income.h"
#include "expense.h"
#include "user.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:

    void on_btnIncomeCat_clicked();

    void on_btnExpenseCat_clicked();

    void on_btnIncomeCat_Add_clicked();

    void on_btnDelete_clicked();

    void on_btnExpenseCat_3_clicked();

private:
    Ui::Settings *ui;
    QSqlTableModel *tableModel;
    Transaction *income;
    Transaction *expense;
    User *user;
};

#endif // SETTINGS_H
