#include "dbconn.h"
#include <QDir>

DbConn::DbConn()
{
    qDebug() << "Connecting to db ...";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Qt Projects/QFinance/QFinance.sqlite");
}

bool DbConn::connectDb()
{
    bool isConnected = false;

    //opening connection
    if(!isConnected) {
        isConnected = db.open();
    }

    if(db.isOpen())
        qDebug() << "Connected to db ...";

    return isConnected;

}

void DbConn::closeDb()
{
    if(db.isOpen())
        db.close();
    qDebug() << "Closed dbConn ...";
}

