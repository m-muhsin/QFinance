#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QDebug>
#include "calculatormodel.h"

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

protected:
    void changeEvent(QEvent *e);

private slots:
    void btnNum_clicked(QString num);

    void on_btnNum1_clicked();
    void on_btnNum2_clicked();
    void on_btnNum3_clicked();
    void on_btnNum4_clicked();
    void on_btnNum5_clicked();
    void on_btnNum6_clicked();
    void on_btnNum7_clicked();
    void on_btnNum8_clicked();
    void on_btnNum9_clicked();
    void on_btnNum0_clicked();

    void on_btnClear_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnEqual_clicked();

    void on_btnMultiply_clicked();

    void on_btnDivide_clicked();

signals:
    btnEqual_clicked(QString ans);

private:
    Ui::Calculator *ui;
    CalculatorModel *cm;
};

#endif // CALCULATOR_H
