#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include "expense.h"
#include "calculator.h"

namespace Ui {
class AddExpense;
}
/**
 * @brief The AddExpense class is a child of QWidget and it is essentially the screen used
 * to add a New Expense or Edit a previous Expense record.
 */
class AddExpense : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Sets up the UI, initiliazes an instance of Expense class and sets up connectors
     * @param parent refers to the QWidget that calls this constructor
     */
    explicit AddExpense(QWidget *parent = 0);

    ~AddExpense(); //!< The Destructor of this class deletes the UI
    /**
     * @brief This method sets up the screen to perform an Expense Edit.
     * @param tableModel contains a single existing record which will be set to the fields
     * of this screen
     */
    void setupEdit(QSqlTableModel *tableModel);

private slots:
    /**
     * @brief This method picks the fields on the screen and stores it in an Expense object.
     * It saves this object to the database after performing validation.
     */
    void save();
    /**
     * @brief Clears the fields on the screen and sets the date to today
     */
    void clear();

    void openCalculator(); //!< Shows the Calculator
    /**
     * @brief
     * @brief Called when the Equals button on the Calculator is clicked.
     * Picks the number entered on the Calculator screens and feeds to the Amount field.
     * @param answer which appears on the Calculator screen
     */
    void onEqualsClicked(QString answer);

private:
    Ui::AddExpense *ui;
    Transaction *expense; //polymorphism
    Calculator *calculator;
    int tempId;
};

#endif // ADDEXPENSE_H
