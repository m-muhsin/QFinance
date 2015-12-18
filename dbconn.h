#ifndef DBCONN_H
#define DBCONN_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QDir>
#include <QMessageBox>
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief The DbConn class represents the Database connectivity part of QFinance.
 */
class DbConn
{
public:

    /**
     * @brief Initializes an instance of QSqlDatabase and sets the path to the database.
     */
    DbConn();

    /**
     * @brief Gets the path of the database which is stored in a text file in the output folder.
     * If the path does not match a valid database, the user is prompted to select the path himself.
     * This path is stored back to the text file.
     * @return The database path as a QString.
     */
    QString getDbPath();

    /**
     * @brief Checks if the database connection is currently open and performs an open
     * databse operation it is not.
     * @return true if connection is open, false otherwise.
     */
    bool connectDb();

    /**
     * @brief Checks if the database connection is currently open and performs a close
     * databse operation it is so.
     */
    void closeDb();

private:
    QSqlDatabase db;
};

#endif // DBCONN_H
