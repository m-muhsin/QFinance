#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QInputDialog>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QList>
#include "income.h"
#include "expense.h"
#include "user.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

signals:
    void toggleButtons(bool);
    void deleteRecord();

private slots:

    void on_btnIncomeCat_clicked();
    void on_btnExpenseCat_clicked();

    void on_btnAddCat_clicked();
    void on_btnEditCat_clicked();

    void on_btnUser_clicked();
    void on_btnAddUser_clicked();
    void on_btnEditUser_clicked();

    void doToggleButtons(bool);
    void doDeleteRecord();

private:
    Ui::Settings *ui;
    QSqlTableModel *tableModel;
    Transaction *income;
    Transaction *expense;
    User *user;

    void setupCatTable(QString type);
    bool insertUser(QString username, QString password);
    bool updateUser(int rowNumber, int id, QString username, QString password);
};

#endif // SETTINGS_H
