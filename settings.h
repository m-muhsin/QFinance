#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QInputDialog>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QList>
#include "income.h"
#include "expense.h"
#include "user.h"

namespace Ui {
class Settings;
}

/**
 * @brief The Settings class is a child of QWidget and it is screen used
 * to manage all Settings related to QFinance.
 */
class Settings : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Sets up the UI, initiliazes an instance of Income and Expense class
     * and sets up connectors
     * @param parent refers to the QWidget that calls this constructor
     */
    explicit Settings(QWidget *parent = 0);

    ~Settings(); //!< The Destructor of this class deletes the UI

signals:
    void toggleButtons(bool);
    void deleteRecord();

private slots:

    void on_btnIncomeCat_clicked(); //!< Called when Income Category Button is clicked.
    void on_btnExpenseCat_clicked(); //!< Called when Expense Category Button is clicked.

    void on_btnAddCat_clicked(); //!< Called when Add Income Category Button is clicked.
    void on_btnEditCat_clicked(); //!< Called when Add Expense Category Button is clicked.

    void on_btnUser_clicked(); //!< Called when View All User Button is clicked.
    void on_btnAddUser_clicked(); //!< Called when Add User Button is clicked.
    void on_btnEditUser_clicked(); //!< Called when Edit User Button is clicked.

    /**
     * @brief Called when the tableView is changes and toggles the visibility
     * of the buttons according to what is displayed.
     * @param on is true when tableView is Income/Expense Category, false if User.
     */
    void doToggleButtons(bool on);

    void doDeleteRecord();  //!< Called when Delete Category/User Button is clicked.

private:
    Ui::Settings *ui;
    QSqlTableModel *tableModel;
    Transaction *income;
    Transaction *expense;
    User *user;

    /**
     * @brief Sets up the the QTableView on the right side of the screen.
     * @param type defines what data to fill the table with.
     */
    void setupViewTable(QString type);

    /**
     * @brief Adds a new user to the database.
     * @param username of the record
     * @param password of the record
     * @return true of insertion successful, false otherwise.
     */
    bool insertUser(QString username, QString password);

    /**
     * @brief Updates selected user in the database.
     * @param rowNumber selected row number in the QTableView.
     * @param id of the record.
     * @param username of the record
     * @param password of the record
     * @return true of update successful, false otherwise.
     */
    bool updateUser(int rowNumber, int id, QString username, QString password);

};

#endif // SETTINGS_H
