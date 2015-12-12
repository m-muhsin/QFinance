#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "addincome.h"
#include "addexpense.h"
#include "dbconn.h"

#include "viewincome.h"
#include "viewexpense.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void closeTab(int);

    void on_actionQuit_triggered();

    void on_actionAdd_Income_triggered();

    void on_actionAdd_Expense_triggered();

    void on_actionView_Income_triggered();

    void on_actionView_Expense_triggered();

private:
    Ui::MainWindow *ui;
    AddIncome *addIncome;
    AddExpense *addExpense;
    DbConn *dbConn;

    ViewIncome *vIncome;
    ViewExpense *vExpense;
};

#endif // MAINWINDOW_H
