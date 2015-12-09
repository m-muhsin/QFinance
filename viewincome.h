#ifndef VIEWINCOME_H
#define VIEWINCOME_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class ViewIncome;
}

class ViewIncome : public QWidget
{
    Q_OBJECT

public:
    explicit ViewIncome(QWidget *parent = 0);
    ~ViewIncome();

private slots:
    void on_btnDelete_clicked();

private:
    Ui::ViewIncome *ui;
    QSqlTableModel *model;

    void deleteIncome();
    void setupTable();
};

#endif // VIEWINCOME_H
