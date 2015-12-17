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

class DbConn
{
public:
    DbConn();
    QString getDbPath();
    bool connectDb();
    void closeDb();

private:
    QSqlDatabase db;
};

#endif // DBCONN_H
