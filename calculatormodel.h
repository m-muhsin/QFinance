#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QDebug>
#include <QSqlQuery>

class CalculatorModel
{
public:
    CalculatorModel();

    void firstNumEntered(int);
    void secondNumEntered(int);
    void additionMode();
    void subtractionMode();
    void multiplicationMode();
    void divisionMode();
    int calculate();
    void clear();

private:
    int firstNumber, secondNumber;
    bool addition;
    bool subtraction;
    bool multiplication;
    bool division;
    int result;

};

#endif // CALCULATORMODEL_H
