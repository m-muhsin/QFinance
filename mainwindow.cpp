#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Calling connectDb ... ";
    dbConn = new DbConn();
    dbConn->connectDb();

    showSummary();

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)),this, SLOT(closeTab(int)));

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

void MainWindow::showSummary()
{
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

}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionAdd_Income_triggered()
{
    addIncome = new AddIncome(this);
    ui->tabWidget->insertTab(ui->tabWidget->count() + 1, addIncome, "New Income");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_actionAdd_Expense_triggered()
{
    addExpense = new AddExpense(this);
    ui->tabWidget->insertTab(ui->tabWidget->count() + 1, addExpense, "New Expense");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_actionView_Income_triggered()
{
    vIncome = new ViewIncome(this);
    ui->tabWidget->insertTab(ui->tabWidget->count() + 1, vIncome, "View Income");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_actionView_Expense_triggered()
{
    vExpense = new ViewExpense(this);
    ui->tabWidget->insertTab(ui->tabWidget->count() + 1, vExpense, "View Expense");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_actionAbout_triggered()
{
    about = new About(this);
    ui->tabWidget->insertTab(ui->tabWidget->count() + 1, about, "About QFinance");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}
