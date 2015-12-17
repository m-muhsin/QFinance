#include "dbconn.h"

using namespace std;
DbConn::DbConn()
{
    qDebug() << "Connecting to db ...";
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = getDbPath();

    if(dbPath == NULL) {
        QMessageBox::information(0, "Not Found", "Database Not Found! QFinance will exit now.");
        exit(213);
    }

    db.setDatabaseName(dbPath);
}

QString DbConn::getDbPath()
{
    QFile* dbPathTxt = new QFile(QDir::currentPath()+"/dbpath.txt");
    if(!dbPathTxt->open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        QMessageBox::information(0, "error", dbPathTxt->errorString());
        string txtSPath = (QDir::currentPath() + ("/dbpath.txt")).toUtf8().constData();
        std::ofstream o(txtSPath.c_str());
        o << "D:/Qt Projects/QFinance/QFinance.sqlite" << std::endl;
    }
    QTextStream in(dbPathTxt);
    QString *dbPath = new QString;
    while(!in.atEnd()) {
        *dbPath = in.readLine();
    }
    QFile dbFile(*dbPath);
    QFileDialog fileDialog;
    while(!dbFile.exists()) {
        *dbPath = fileDialog.getOpenFileName(0,"Open database", QDir::currentPath(), "SQLITE Database (*.sqlite)");
        if(dbPath->isEmpty()) {
            dbPathTxt->close();
            return NULL;
        }
        dbFile.setFileName(*dbPath);
        QTextStream newPath(dbPathTxt);
        newPath << *dbPath;
    }
    qDebug() << "fileName is" << dbPath;
    dbPathTxt->close();
    return *dbPath;
}

bool DbConn::connectDb()
{
    bool isConnected = db.isOpen();

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

