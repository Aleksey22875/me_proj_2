#include "../include/calculator.h"

#include "../include/parser.h"

#include "libmath.hpp"

void Calculator::calculate(Task& task)
{

    int result = 0;

    switch (task.getOperation())
    {
        case '+':
            task.setStatus(libmath::addition(task.getVal_1(),
                                             task.getVal_2().value(), result));
            break;
        case '-':
            task.setStatus(libmath::subtraction(
                task.getVal_1(), task.getVal_2().value(), result));
            break;
        case '*':
            task.setStatus(libmath::multiplication(
                task.getVal_1(), task.getVal_2().value(), result));
            break;
        case '/':
            task.setStatus(libmath::division(task.getVal_1(),
                                             task.getVal_2().value(), result));
            break;
        case '^':
            task.setStatus(libmath::power(task.getVal_1(),
                                          task.getVal_2().value(), result));
            break;
        case '!':
            task.setStatus(libmath::factorial(task.getVal_1(), result));
            break;

        default:
            task.setStatus(1);
    }
    task.setResult(result);
}
