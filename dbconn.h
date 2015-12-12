#ifndef DBCONN_H
#define DBCONN_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>

class DbConn
{
public:
    DbConn();
    bool connectDb();
    void closeDb();

private:
    QSqlDatabase db;
};

#endif // DBCONN_H
