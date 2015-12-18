#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    income = new Income;
    expense = new Expense;

    connect(this, SIGNAL(toggleButtons(bool)), this, SLOT(doToggleButtons(bool)));
    connect(this, SIGNAL(deleteRecord()), this, SLOT(doDeleteRecord()));
    connect(ui->btnDeleteCat, SIGNAL(clicked(bool)), this, SLOT(doDeleteRecord()));
    connect(ui->btnDeleteUser, SIGNAL(clicked(bool)), this, SLOT(doDeleteRecord()));

    ui->btnAddCat->setVisible(false);
    ui->btnEditCat->setVisible(false);
    ui->btnDeleteCat->setVisible(false);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_btnIncomeCat_clicked()
{
    setupViewTable("Income");
}

void Settings::on_btnExpenseCat_clicked()
{
    setupViewTable("Expense");
}

void Settings::on_btnAddCat_clicked()
{
    bool ok;
    QString newCat = QInputDialog::getText(this, tr("New"),
                        tr("Enter New Category name:"), QLineEdit::Normal,"", &ok);
    if (ok && !newCat.isEmpty())
        qDebug() << newCat;

    int lastRecordId = tableModel->record(tableModel->rowCount()-1).value(0).toInt();

    QSqlField field1("id", QVariant::Int);
    field1.setValue(lastRecordId+1);

    QSqlField field2("catname", QVariant::String);
    field2.setValue(QString(newCat));

    QSqlRecord record;

    record.insert(0,field1);
    record.insert(1,field2);

    tableModel->insertRecord(-1, record);
}

void Settings::on_btnEditCat_clicked()
{
    if(ui->tblView->selectionModel()->selectedRows().isEmpty())
        return;

    QModelIndexList selectedRow = ui->tblView->selectionModel()->selectedRows();
    int rowNumber = selectedRow.last().row();

    QSqlRecord oldRecord = tableModel->record(rowNumber);
    qDebug() << oldRecord.value(0);
    qDebug() << oldRecord.value(1);
    qDebug() << rowNumber;

    bool ok;
    QString updatedCat = QInputDialog::getText(this, tr("Edit"),
                        tr("Enter Category name:"), QLineEdit::Normal, oldRecord.value(1).toString(), &ok);
    if (ok && !updatedCat.isEmpty())
        qDebug() << updatedCat;

    int oldRecordId = oldRecord.value(0).toInt();

    QSqlField field1("id", QVariant::Int);
    field1.setValue(oldRecordId);

    QSqlField field2("catname", QVariant::String);
    field2.setValue(QString(updatedCat));

    emit deleteRecord();

    QSqlRecord newRecord;
    newRecord.insert(0,field1);
    newRecord.insert(1,field2);
    tableModel->insertRecord(rowNumber, newRecord);
}

void Settings::setupViewTable(QString type)
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tbl"+type+"cat");
    tableModel->select();
    tableModel->setHeaderData(1, Qt::Horizontal, type+" Categories",0);

    ui->tblView->setModel(tableModel);
    ui->tblView->setColumnHidden(0, true);
    ui->tblView->horizontalHeader()->setStretchLastSection(true);

    doToggleButtons(true);
}

bool Settings::insertUser(QString username, QString password)
{
    qDebug() << "inside newUser";
    int lastRecordId = tableModel->record(tableModel->rowCount()-1).value(0).toInt();

    QSqlField field0("id", QVariant::Int);
    field0.setValue(lastRecordId+1);

    QSqlField field1("username", QVariant::String);
    field1.setValue(username);

    QSqlField field2("password", QVariant::String);
    field2.setValue(password);

    QSqlRecord record;

    record.insert(0,field0);
    record.insert(1,field1);
    record.insert(2,field2);

    bool inserted = tableModel->insertRecord(-1, record);
    qDebug() << "User inserted: " << inserted;

    return inserted;
}

bool Settings::updateUser(int rowNumber, int id, QString username, QString password)
{
    qDebug() << "inside newUser";
    int lastRecordId = id;

    QSqlField field0("id", QVariant::Int);
    field0.setValue(lastRecordId+1);

    QSqlField field1("username", QVariant::String);
    field1.setValue(username);

    QSqlField field2("password", QVariant::String);
    field2.setValue(password);

    QSqlRecord record;

    record.insert(0,field0);
    record.insert(1,field1);
    record.insert(2,field2);

    bool inserted = tableModel->insertRecord(rowNumber, record);
    qDebug() << "User inserted: " << inserted;

    return inserted;
}

void Settings::on_btnUser_clicked()
{
    tableModel = new QSqlTableModel;
    tableModel->setTable("tbluser");
    tableModel->select();
    tableModel->setHeaderData(1, Qt::Horizontal,"Username",0);
    tableModel->setHeaderData(2, Qt::Horizontal,"Password",0);

    ui->tblView->setModel(tableModel);
    ui->tblView->setColumnHidden(0, true);
    ui->tblView->setColumnHidden(2, true);
    ui->tblView->horizontalHeader()->setStretchLastSection(true);

    doToggleButtons(false);
}

void Settings::on_btnAddUser_clicked()
{

    QString username;
    QString password;

    QDialog dialog(this);
    dialog.resize(300,150);

    QFormLayout form(&dialog);

    QLineEdit *txtUsername = new QLineEdit(&dialog);
    QLineEdit *txtPassword = new QLineEdit(&dialog);
    txtPassword->setEchoMode(QLineEdit::Password);

    form.addRow(new QLabel("Username:"));
    form.addRow(txtUsername);
    form.addRow(new QLabel("Password:"));
    form.addRow(txtPassword);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        username = txtUsername->text();
        password = txtPassword->text();

        if(username.isEmpty() || password.isEmpty())
            QMessageBox::warning(this, "Fields missing", "Enter username and password");
        else {

            bool ok = insertUser(username, password);

            if(ok)
                QMessageBox::information(this, "Success", "User Successfully added");
            else
                QMessageBox::warning(this, "Fail", "An error has occured. Please try again or contact developer");
        }
    }
}

void Settings::on_btnEditUser_clicked()
{
    qDebug() << "inside on_btnEditUser_clicked";
    if(ui->tblView->selectionModel()->selectedRows().isEmpty())
        return;

    QModelIndexList selectedRow = ui->tblView->selectionModel()->selectedRows();
    int rowNumber = selectedRow.last().row();

    QSqlRecord oldRecord = tableModel->record(rowNumber);
    qDebug() << "rowNumber" << rowNumber;
    int oldId = oldRecord.value(0).toInt();
    QString oldUsername = oldRecord.value(1).toString();

    QString username;
    QString password;

    QDialog dialog(this);
    dialog.resize(300,150);

    QFormLayout form(&dialog);

    QLineEdit *txtUsername = new QLineEdit(&dialog);
    txtUsername->setText(oldUsername);
    QLineEdit *txtPassword = new QLineEdit(&dialog);
    txtPassword->setEchoMode(QLineEdit::Password);

    form.addRow(new QLabel("Username:"));
    form.addRow(txtUsername);
    form.addRow(new QLabel("Password:"));
    form.addRow(txtPassword);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        username = txtUsername->text();
        password = txtPassword->text();

        if(username.isEmpty() || password.isEmpty())
            QMessageBox::warning(this, "Fields missing", "Enter username and password");
        else {

            emit deleteRecord();
            bool ok = updateUser(rowNumber, oldId, username, password);

            if(ok)
                QMessageBox::information(this, "Success", "User Successfully added");
            else
                QMessageBox::warning(this, "Fail", "An error has occured. Please try again or contact developer");
        }
    }

}

void Settings::doToggleButtons(bool on)
{
    qDebug() << "doToggleButtons: " << on;

    ui->btnAddCat->setVisible(on);
    ui->btnEditCat->setVisible(on);
    ui->btnDeleteCat->setVisible(on);

    ui->btnAddUser->setEnabled(!on);
    ui->btnEditUser->setEnabled(!on);
    ui->btnDeleteUser->setEnabled(!on);

}

void Settings::doDeleteRecord()
{
    qDebug() << "doDeleteRecord()";
    QModelIndexList selectedRow = ui->tblView->selectionModel()->selectedRows();

    while (!selectedRow.isEmpty()) {
        tableModel->removeRows(selectedRow.last().row(), 1);
        selectedRow.removeLast();
        qDebug() << tableModel->submitAll();
    }
    tableModel->select();
}
