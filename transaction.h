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
     * @brief Returns the id value of the object
     * @return Transaction id
     */
    int getId() const;
    /**
     * @brief Sets the id value of the Transaction
     * @param Transaction id
     */
    void setId(int value);

    QString getDate() const;
    void setDate(const QString &value);

    int getAmount() const;
    void setAmount(int value);

    QString getParty() const;
    void setParty(const QString &value);

    void setCategory(const QString &value);
    QString getCategory() const;

    QString getDescription() const;
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
     * @brief getCategoriesList
     * @param type
     * @return
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
