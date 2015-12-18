#ifndef EXPENSE_H
#define EXPENSE_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"
/**
 * @brief The Expense class is a child of the Transaction class and
 * models the expense object of QFinance.
 */
class Expense: public Transaction
{

public slots:
    /**
     * @brief Implementaion of the bool insertTransaction(Transaction*) which is a pure virtual
     * in the parent class.
     * @param expense is a pointer to an Expense object.
     * @return true if insertion successful, false otherwise.
     */
    bool insertTransaction(Transaction* expense);
    /**
     * @brief Implementaion of the bool updateTransaction(Transaction*) which is a pure virtual
     * in the parent class.
     * @param expense is a pointer to an Expense object.
     * @return true if update successful, false otherwise.
     */
    bool updateTransaction(Transaction* expense);

};

#endif // EXPENSE_H
