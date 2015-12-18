#ifndef INCOME_H
#define INCOME_H

#include <QSqlQuery>
#include <QDebug>
#include "transaction.h"

/**
 * @brief The Income class is a child of the Transaction class and
 * models the income object of QFinance.
 */
class Income: public Transaction
{

public slots:

    /**
     * @brief Implementaion of the bool insertTransaction(Transaction*) which is a pure virtual
     * in the parent class.
     * @param income is a pointer to an Income object.
     * @return true if insertion successful, false otherwise.
     */
    bool insertTransaction(Transaction* income);

    /**
     * @brief Implementaion of the bool updateTransaction(Transaction*) which is a pure virtual
     * in the parent class.
     * @param income is a pointer to an Income object.
     * @return true if update successful, false otherwise.
     */
    bool updateTransaction(Transaction* income);

};

#endif // INCOME_H
