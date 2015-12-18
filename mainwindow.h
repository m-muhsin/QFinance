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
/**
 * @brief The MainWindow class is a child of QMainWindow and it acts as a Controller
 * and container for all the other QWidgets of this application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief The contructor sets up the UI, removes the close button of the current tab,
     * calls the showSummary method to calculate the brief summary to be displayed and
     * performs many SIGNAL - SLOT connections.
     * @param parent refers to the object that called this constructor.
     */
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow(); //!< The Destructor of this class deletes the UI and closes the Database connection.

signals:
    void on_actionLog_out_triggered();

private slots:

    void onAddIncome(); //!< Opens a new tab and sets up the UI for New Income

    void onAddExpense(); //!< Opens a new tab and sets up the UI for New Expense

    void onViewIncome(); //!< Opens a new tab and sets up the UI for View Income

    void onViewExpense(); //!< Opens a new tab and sets up the UI for View Expense

    /**
     * @brief Closes the current tab.
     * @param index refers to the index of the current tab.
     */
    void closeTab(int index);

    /**
     * @brief Checks if a certain tab exists and if so, moves to that tab.
     * @param label refers to the label of the tab that we want to check for existence.
     * @return true if given tab exists, false otherwise.
     */
    bool tabExists(QString label);

    /**
     * @brief Recalculates the brief summary show on the main tab. Only works if the index is 0.
     * @param index refers to the index of the tab.
     */
    void showSummary(int index);

    void showAbout(); //!< Opens a new About tab if not already open.

    void showAboutQt(); //!< Opens a dialog with a brief description of Qt.

    void showSettings(); //!< Opens the Settings tab if not already open.

    /**
     * @brief Opens a new tab and sets up the screen for a transaction to be edited.
     * @param type refers to whether Income or Expense transacion.
     * @param tableModel is a single of record of the data to be edited.
     */
    void editTransaction(QString type, QSqlTableModel* tableModel);

    void quitApp(); //!< Called when Quit Applicaion is triggered.

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
