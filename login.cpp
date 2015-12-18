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

    connect(ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(w, SIGNAL(on_actionLog_out_triggered()), this, SLOT(logout()));
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnExit_clicked()
{
    w->~MainWindow();
    qApp->exit();
}

void Login::login()
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
