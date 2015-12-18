#ifndef ADDINCOME_H
#define ADDINCOME_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include "income.h"
#include "calculator.h"

namespace Ui {
class AddIncome;
}
/**
 * @brief The AddIncome class is a child of QWidget and it is essentially the screen used
 * to add a New Income or Edit a previous Income record.
 */
class AddIncome : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Sets up the UI, initiliazes an instance of Income class and sets up connectors
     * @param parent refers to the QWidget that calls this constructor
     */
    explicit AddIncome(QWidget *parent = 0);

    ~AddIncome(); //!< The Destructor of this class deletes the UI

    /**
     * @brief This method sets up the screen to perform an Income Edit.
     * @param tableModel contains a single existing record which will be set to the fields
     * of this screen
     */
    void setupEdit(QSqlTableModel* tableModel);

private slots:
    /**
     * @brief This method picks the fields on the screen and stores it in an Income object.
     * It saves this object to the database after performing validation.
     */
    void save();

    void clear(); //!< Clears the fields on the screen

    void openCalculator(); //!< Shows the Calculator.

    /**
     * @brief
     * @brief Called when the Equals button on the Calculator is clicked.
     * Picks the number entered on the Calculator screens and feeds to the Amount field.
     * @param answer which appears on the Calculator screen
     */
    void onEqualsClicked(QString);

private:
    Ui::AddIncome *ui;
    Transaction *income; //polymorphism
    Calculator *calculator;
    int tempId;
};

#endif // ADDINCOME_H
