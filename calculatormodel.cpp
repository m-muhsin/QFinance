#include "calculatormodel.h"

void CalculatorModel::firstNumEntered(int n) { firstNumber = n; }

void CalculatorModel::secondNumEntered(int n) { secondNumber = n; }

void CalculatorModel::additionMode() { addition = true; }

void CalculatorModel::subtractionMode() { subtraction = true; }

void CalculatorModel::multiplicationMode() { multiplication = true; }

void CalculatorModel::divisionMode() { division = true; }

int CalculatorModel::calculate()
{
    if(addition)
        result = firstNumber + secondNumber;

    if(subtraction)
        result = firstNumber - secondNumber;

    if(multiplication)
        result = firstNumber * secondNumber;

    if(division)
        result = firstNumber / secondNumber;

    return result;
}

void CalculatorModel::clear()
{
    firstNumber = 0;
    secondNumber = 0;
    result = 0;
    addition = false;
    subtraction = false;
    multiplication = false;
    division = false;
}

