#include "user.h"
#include <QDebug>

bool User::loginUser(QString username, QString password)
{
    QSqlQuery query;

    if(query.exec("select * from tbluser where username = '"+username+"' and password = '"+password+"'")) {
        while (query.next()) {
            return true;
        }
    }
    return false;

}
