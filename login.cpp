#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    loginModel = new LoginModel;

    connect(this, SIGNAL(btnLogin_clicked()), this, SLOT(checkLogin()));
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
    bool success = loginModel->login(ui->txtUsername->text(), ui->txtPassword->text());
    if (success) {
        w.show();
        this->close();
    }
    else {
        QMessageBox::warning(this, "Login failed", "Username and/or Paswword incorrect");
    }
}
