#include "../include/calculator.h"

#include "../include/parser.h"

#include "libmath.hpp"

void Calculator::calculate(Task& task)
{


    if (task.operation == '+')
    {
        task.result = libmath::addition(task.value_1.value(),
                                         task.value_2.value());
    }
    else if (task.operation == '-')
    {
        task.result = libmath::subtraction(task.value_1.value(),
                                            task.value_2.value());
    }
    else if (task.operation == '*')
    {
        task.result = libmath::multiplication(
            task.value_1.value(), task.value_2.value());
    }
    else if (task.operation == '/')
    {
        task.result =  libmath::division(task.value_1.value(),
                                         task.value_2.value());
    }
    else if (task.operation == '^')
    {
        task.result = 
            libmath::power(task.value_1.value(), task.value_2.value());
    }
    else if (task.operation == '!')
    {
        task.result = libmath::factorial(task.value_1.value());
    }
}
