#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QModelIndexList>
#include <QStandardItemModel>
#include <QStandardItem>
#include "dbconn.h"

/**
 * @brief The Transaction class describes the Transaction Object of QFinance. It is an abstract class.
 * This class contains the common members of the two type of transaction: Income and Expense.
 */
class Transaction
{
public:

    /**
     * @brief gets the transaction Id
     * @return id
     */
    int getId() const;

    /**
     * @brief setIds the transaction Id
     * @param value refers to the transaction Id
     */
    void setId(int value);

    /**
     * @brief gets the transaction Date
     * @return date
     */
    QString getDate() const;

    /**
     * @brief sets the transaction Date
     * @param value refers to the transaction Date
     */
    void setDate(const QString &value);

    /**
     * @brief gets the transaction Amount
     * @return amount
     */
    int getAmount() const;

    /**
     * @brief sets the transaction Amount
     * @param value refers to the transaction Amount
     */
    void setAmount(int value);

    /**
     * @brief gets the transaction Party (payer or payee)
     * @return Party (payer or payee)
     */
    QString getParty() const;

    /**
     * @brief sets the transaction Party (payer or payee)
     * @param value refers to the transaction Amount
     */
    void setParty(const QString &value);

    /**
     * @brief sets the transaction Category
     * @param value refers to the transaction Category
     */
    void setCategory(const QString &value);

    /**
     * @brief gets the transaction Category
     * @return the transaction Category
     */
    QString getCategory() const;

    /**
     * @brief gets the transaction Description
     * @return the transaction Description
     */
    QString getDescription() const;

    /**
     * @brief sets the transaction Description
     * @param value refers to the transaction Description
     */
    void setDescription(const QString &value);


public slots:

    /**
     * @brief This is a pure virtual method since different types of Transactions have to be inserted in different
     * ways (persistence.)
     * @param transaction is a pointer to an object of type Transaction
     * @return bool Confirms if the insertion was successful.
     */
    virtual bool insertTransaction(Transaction* transaction) = 0;

    /**
     * @brief This is a pure virtual method since different types of Transactions have to be updated in different
     * ways (persistence.)
     * @param transaction is a pointer to an object of type Transaction
     * @return bool Confirms if the insertion was successful.
     */
    virtual bool updateTransaction(Transaction* transaction) = 0;

    /**
     * @brief Gives a pointer to an QSqlTableModel object which is constructed by querying from a data sets.
     * @param type defines from which data set to query from
     * @return a pointer to an QSqlTableModel
     */
    QSqlTableModel* viewTransaction(QString type);

    /**
     * @brief Gives a pointer to an QSqlTableModel object which is constructed by querying from a data sets.
     * This object contains only one record of data.
     * @param type defines from which data set to query from
     * @param id defines which record to get from
     * @return a pointer to an QSqlTableModel with one record
     */
    QSqlTableModel* getTransaction(QString type, int id);

    /**
     * @brief Deletes a Transaction
     * @param list specifies which items from the QModelIndexList to delete
     */
    void deleteTransaction(QModelIndexList list);

    /**
     * @brief Gets the list of categories according to the transaction type
     * @param type refers to which transaction category you want
     * @return a pointer to a QStandardItemModel object
     */
    QStandardItemModel* getCategoriesList(QString type);

private:
    DbConn *dbConn;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    QStandardItemModel *itemModel;

    int id;
    QString date;
    int amount;
    QString party; //payer | payee
    QString category;
    QString description;
};

#endif // TRANSACTION_H
