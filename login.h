#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"
#include "mainwindow.h"

namespace Ui {
class Login;

}
/**
 * @brief The Login class is a child of the QDialog class which is called when the application is
 * run. Also called when logout is triggered from the MainWindow.
 * This class describes user login activities.
 */
class Login : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Sets up the UI, initializes the User and MainWindow classes and connects
     * various SIGNALs to SLOTs.
     * @param parent refers to the QWidget that calls this class.
     */
    explicit Login(QWidget *parent = 0);

    ~Login(); //!< The Destructor of this class deletes the UI

private slots:

    void on_btnExit_clicked(); //!< Closes the Database connection and quits the application

    /**
     * @brief Checks with the credentials with the User class.
     * Moves to the MainWindo if login successful. Gives MessageBox otherwise.
     */
    void login();

    /**
     * @brief Hides MainWindow and shows back the Login screen.
     */
    void logout();

signals:
    void loginClicked();

private:
    Ui::Login *ui;
    User *user;
    MainWindow *w;

};

#endif // LOGIN_H
