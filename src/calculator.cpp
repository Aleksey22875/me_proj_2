#include "../include/calculator.h"

#include "../include/parser.h"

#include "libmath.hpp"

void Calculator::calculate(Task& task)
{


    if (task.getOperation() == "+")
    {
        task.setResult(libmath::addition(task.getVal_1(),
                                         task.getVal_2().value()));
    }
    else if (task.getOperation() == "-")
    {
        task.setResult(libmath::subtraction(task.getVal_1(),
                                            task.getVal_2().value()));
    }
    else if (task.getOperation() == "*")
    {
        task.setResult(libmath::multiplication(
            task.getVal_1(), task.getVal_2().value()));
    }
    else if (task.getOperation() == "/")
    {
        task.setResult(libmath::division(task.getVal_1(),
                                         task.getVal_2().value()));
    }
    else if (task.getOperation() == "^")
    {
        task.setResult(
            libmath::power(task.getVal_1(), task.getVal_2().value()));
    }
    else if (task.getOperation() == "!")
    {
        task.setResult(libmath::factorial(task.getVal_1()));
    }
}
