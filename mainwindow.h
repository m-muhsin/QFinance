#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "dbconn.h"
#include "addincome.h"
#include "addexpense.h"
#include "viewincome.h"
#include "viewexpense.h"
#include "about.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    triggerLogOut();

private slots:
    void closeTab(int);

    bool tabExists(QString);

    void showSummary(int);

    void editTransaction(QString type, QSqlQueryModel* rowModel);

    void on_actionQuit_triggered();

    void on_actionAdd_Income_triggered();

    void on_actionAdd_Expense_triggered();

    void on_actionView_Income_triggered();

    void on_actionView_Expense_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionSettings_triggered();

    void on_actionLog_out_triggered();

private:
    Ui::MainWindow *ui;
    DbConn *dbConn;

    AddIncome *addIncome;
    AddExpense *addExpense;
    ViewIncome *viewIncome;
    ViewExpense *viewExpense;
    About *about;
    Settings *settings;

};

#endif // MAINWINDOW_H
