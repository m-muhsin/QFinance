#include "loginmodel.h"
#include <QDebug>
LoginModel::LoginModel()
{
    qDebug() << "Calling connectDb ... ";
    dbConn = new DbConn();
    dbConn->connectDb();
}

LoginModel::~LoginModel()
{
    qDebug() << "~LoginModel() called. Closing DB";
    dbConn->closeDb();
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

