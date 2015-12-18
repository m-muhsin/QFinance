#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QDebug>
#include <QSqlQuery>

/**
 * @brief The CalculatorModel class is the model of the Calculator
 * that is integrated with QFinance.
 */
class CalculatorModel
{
public:

    /**
     * @brief Called when the first variable of the operations is entered.
     * @param n is the first number variable.
     */
    void firstNumEntered(int n);

    /**
     * @brief Called when the second variable of the operations is entered.
     * @param n is the second number variable.
     */
    void secondNumEntered(int n);

    void additionMode(); //!< Sets operation mode to Addition
    void subtractionMode(); //!< Sets operation mode to Subtraction
    void multiplicationMode(); //!< Sets operation mode to Multiplication
    void divisionMode(); //!< Sets operation mode to Division

    /**
     * @brief Performs calculation between the the first and second numbers
     * according to the operation mode.
     * @return The answer of the calculation.
     */
    int calculate();

    void clear(); //!< Clears the entered fields.

private:
    int firstNumber, secondNumber;
    bool addition;
    bool subtraction;
    bool multiplication;
    bool division;
    int result;

};

#endif // CALCULATORMODEL_H
