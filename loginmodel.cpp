#include "loginmodel.h"
#include <QDebug>
LoginModel::LoginModel()
{

}

bool LoginModel::login(QString username, QString password)
{
    QSqlQuery query;

    if(query.exec("select * from tbluser where username = '"+username+"' and password = '"+password+"'")) {
        while (query.next()) {
            return true;
        }
    }
    return false;

}

