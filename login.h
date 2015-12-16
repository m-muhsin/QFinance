#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:

    void on_btnExit_clicked();

    void on_btnLogin_clicked();

    void checkLogin();

signals:
    btnLogin_clicked();

private:
    Ui::Login *ui;
    User *user;
    MainWindow w;

};

#endif // LOGIN_H
