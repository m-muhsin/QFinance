#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlQuery>
#include "dbconn.h"

/**
 * @brief The User class describes the user object of the application.
 */
class User
{
public:

    /**
     * @brief This method queries the database to check if the credentials entered by the user
     * matches the ones in the database.
     * @return true if credentials match, false otherwise
     */
    bool loginUser(QString, QString);

private:
    QString username;
    QString password;

};

#endif // USER_H
