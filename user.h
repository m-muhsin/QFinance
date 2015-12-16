#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlQuery>
#include "dbconn.h"

class User
{
public:
    User();
    bool loginUser(QString, QString);

private:
    QString username;
    QString password;

};

#endif // USER_H
