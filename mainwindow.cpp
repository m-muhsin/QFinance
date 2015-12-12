#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)),this, SLOT(closeTab(int)));

    qDebug() << "Calling connectDb ... ";
    dbConn = new DbConn();
    dbConn->connectDb();
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
