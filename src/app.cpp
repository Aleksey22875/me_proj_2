#include "app.h"
#include "libmath.hpp"
#include <iostream>

namespace
{
    struct Task
    {
        int val_1;
        char operation;
        int val_2 = 0;
        int status;
        int result;
    };
    Task task;
    void parse(int x, int y, char op, Task &task)
    {
        task.val_1 = x;
        task.operation = op;
        task.val_2 = y;
    }

    void calculate(Task &task)
    {
        task.status = 0;
        switch (task.operation)
        {
        case '+':
            task.status = libmath::addition(task.val_1, task.val_2, task.result);
            break;
        case '-':
            task.status = libmath::subtraction(task.val_1, task.val_2, task.result);
            break;
        case '*':
            task.status = libmath::multiplication(task.val_1, task.val_2, task.result);
            break;
        case '/':
            task.status = libmath::division(task.val_1, task.val_2, task.result);
            break;
        case '^':
            task.status = libmath::power(task.val_1, task.val_2, task.result);
            break;
        case '!':
            task.status = libmath::factorial(task.val_1, task.result);
            break;

        default:
            task.status = 1;
        }
    }

    void output(Task &task)
    {
        if (task.status == 0 && task.operation != '!')
        {
            std::cout << task.val_1 << ' ' << task.operation << ' ' << task.val_2 << " = " << task.result << std::endl;
        }
        else if (task.status == -1)
        {
            std::cout << "division by zero!" << std::endl;
        }
        else if (task.status == 1)
        {
            std::cout << "Unknow error!" << std::endl;
        }else if(task.operation == '!')
        {
            std::cout << task.val_1 << ' ' << task.operation << ' ' << " = " << task.result << std::endl;

        }else if(task.status == 2)
        {
            std::cout << "Type overflow!" << std::endl;
        }
    }
}
namespace app
{
    void run(int x, int y, char op)
    {
        Task task;
        parse(x, y, op, task);
        calculate(task);
        output(task);
    }
}