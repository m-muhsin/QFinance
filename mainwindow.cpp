#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->tabBar()->tabButton(0,QTabBar::RightSide)->hide();

    qDebug() << "Calling connectDb ... ";
    dbConn = new DbConn();
    dbConn->connectDb();

    showSummary(0);

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)),this, SLOT(closeTab(int)));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(showSummary(int)));

}

MainWindow::~MainWindow()
{
    dbConn->closeDb();
    delete ui;
}

void MainWindow::closeTab(int index)
{
    // To close the selected tab
    qDebug() << "Inside closeTab";
    ui->tabWidget->removeTab(index);
}

bool MainWindow::tabExists(QString label)
{
    for (int i = 0; i < ui->tabWidget->count(); i++) {
      if (ui->tabWidget->tabBar()->tabText(i) == label) {
        ui->tabWidget->setCurrentIndex(i);
        return true;
      }
    }
    return false;
}

void MainWindow::showSummary(int index)
{
    qDebug() << "inside showSummary. index: " << index;
    if (index == 0) {
        QString totalIncome;
        QSqlQuery query1;
        query1.prepare("select total(amount) from tblincome");if( !query1.exec() )
            qDebug() << query1.lastError();
          while (query1.next())
              totalIncome = query1.value(0).toString();
          ui->lblIncomeAmount->setText(totalIncome);

        QString totalExpense;
        QSqlQuery query2;
        query2.prepare("select total(amount) from tblexpense");
        if( !query2.exec() )
          qDebug() << query2.lastError();
        while (query2.next())
            totalExpense = query2.value(0).toString();
        ui->lblExpenseAmount->setText(totalExpense);

        int income = totalIncome.toInt();
        int expense = totalExpense.toInt();
        int balance = income - expense;
        ui->lblBalanceAmount->setText(QString::number(balance));

        if(balance > 0)
            ui->lblBalanceAmount->setStyleSheet(ui->lblIncomeAmount->styleSheet());
        else
            ui->lblBalanceAmount->setStyleSheet(ui->lblExpenseAmount->styleSheet());
    }
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionAdd_Income_triggered()
{
    QString label = "New Income";
    if (!tabExists(label)) {
        addIncome = new AddIncome(this);
        ui->tabWidget->insertTab(ui->tabWidget->count() + 1, addIncome, label);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void MainWindow::on_actionAdd_Expense_triggered()
{
    QString label = "New Expense";
    if (!tabExists(label)) {
        addExpense = new AddExpense(this);
        ui->tabWidget->insertTab(ui->tabWidget->count() + 1, addExpense, label);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void MainWindow::on_actionView_Income_triggered()
{
    QString label = "View Income";
    if (!tabExists(label)) {
        vIncome = new ViewIncome(this);
        ui->tabWidget->insertTab(ui->tabWidget->count() + 1, vIncome, label);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void MainWindow::on_actionView_Expense_triggered()
{
    QString label = "View Expense";
    if (!tabExists(label)) {
        vExpense = new ViewExpense(this);
        ui->tabWidget->insertTab(ui->tabWidget->count() + 1, vExpense, label);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QString label = "About QFinance";
    if (!tabExists(label)) {
        about = new About(this);
        ui->tabWidget->insertTab(ui->tabWidget->count() + 1, about, label);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}
