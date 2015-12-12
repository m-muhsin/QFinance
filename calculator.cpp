#include "calculator.h"
#include "ui_calculator.h"

#include "addincome.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    cm = new CalculatorModel;
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Calculator::btnNum_clicked(QString num)
{
    QString s = ui->lblDisplay->text();
    s.append(num);
    ui->lblDisplay->setText(s);
}

void Calculator::on_btnNum1_clicked(){btnNum_clicked(ui->btnNum1->text());}
void Calculator::on_btnNum2_clicked(){btnNum_clicked("2");}
void Calculator::on_btnNum3_clicked(){btnNum_clicked("3");}
void Calculator::on_btnNum4_clicked(){btnNum_clicked("4");}
void Calculator::on_btnNum5_clicked(){btnNum_clicked("5");}
void Calculator::on_btnNum6_clicked(){btnNum_clicked("6");}
void Calculator::on_btnNum7_clicked(){btnNum_clicked("7");}
void Calculator::on_btnNum8_clicked(){btnNum_clicked("8");}
void Calculator::on_btnNum9_clicked(){btnNum_clicked("9");}
void Calculator::on_btnNum0_clicked(){btnNum_clicked("0");}


void Calculator::on_btnClear_clicked(){
    ui->lblDisplay->clear();
    cm->clear();
}

void Calculator::on_btnPlus_clicked(){
    QString numStr = ui->lblDisplay->text();
    int n = numStr.toInt();
    cm->firstNumEntered(n);
    cm->additionMode();
    ui->lblDisplay->clear();
}

void Calculator::on_btnMinus_clicked(){
    QString numStr = ui->lblDisplay->text();
    int n = numStr.toInt();
    cm->firstNumEntered(n);
    cm->subtractionMode();
    ui->lblDisplay->clear();
}

void Calculator::on_btnEqual_clicked(){
    qDebug() << "inside on_btnEqual_clicked";
    QString numStr = ui->lblDisplay->text();
    int n = numStr.toInt();
    cm->secondNumEntered(n);
    int res = cm->calculate();
    ui->lblDisplay->setText(QString("%1").arg(res));

    emit btnEqual_clicked(QString("%1").arg(res));
}


void Calculator::on_btnMultiply_clicked()
{
    QString numStr = ui->lblDisplay->text();
    int n = numStr.toInt();
    cm->firstNumEntered(n);
    cm->multiplicationMode();
    ui->lblDisplay->clear();
}

void Calculator::on_btnDivide_clicked()
{
    QString numStr = ui->lblDisplay->text();
    int n = numStr.toInt();
    cm->firstNumEntered(n);
    cm->divisionMode();
    ui->lblDisplay->clear();
}
