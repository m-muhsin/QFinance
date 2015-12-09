#ifndef VIEWEXPENSE_H
#define VIEWEXPENSE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class ViewExpense;
}

class ViewExpense : public QWidget
{
    Q_OBJECT

public:
    explicit ViewExpense(QWidget *parent = 0);
    ~ViewExpense();

private slots:
    void on_btnDelete_clicked();

private:
    Ui::ViewExpense *ui;
    QSqlTableModel *model;

    void deleteExpense();
    void setupTable();
};

#endif // VIEWEXPENSE_H
