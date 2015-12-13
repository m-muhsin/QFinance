#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include <QString>
#include <QSqlQuery>
#include "dbconn.h"

class LoginModel
{
public:
    LoginModel();
    bool login(QString, QString);

private:
    DbConn dbConn;
    QString username;
    QString password;

};

#endif // LOGINMODEL_H
