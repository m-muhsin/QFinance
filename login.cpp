#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    user = new User;
    w = new MainWindow;

    connect(this, SIGNAL(btnLogin_clicked()), this, SLOT(checkLogin()));
    connect(w, SIGNAL(triggerLogOut()), this, SLOT(logout()));
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnExit_clicked()
{
    qApp->exit();
}

void Login::on_btnLogin_clicked()
{
    emit btnLogin_clicked();
}

void Login::checkLogin()
{
    bool success = user->loginUser(ui->txtUsername->text(), ui->txtPassword->text());
    if (success) {
        w->show();
        this->hide();

    }
    else {
        QMessageBox::warning(this, "Login failed", "Username and/or Paswword incorrect");
    }
}

void Login::logout()
{
    qDebug() << "in logout";
    w->hide();
    ui->txtUsername->clear();
    ui->txtPassword->clear();
    ui->txtUsername->setFocus();
    this->show();
}
