#include "app.h"
#include "libmath.h"
#include <iostream>

namespace
{
    struct Task
    {
        int val_1;
        char operation;
        int val_2;
        int status;
        int result;
    };
    Task task;
    void parse(int argc, char **argv, Task &task)
    {
        task.val_1 = std::atoi(argv[1]);
        task.operation = *(argv[2]);
        task.val_2 = std::atoi(argv[3]);
    }

    void calculate(Task &task)
    {
        task.status = 0;
        switch (task.operation)
        {
        case '+':
            task.result = libmath::addition(task.val_1, task.val_2);
            break;
        case '-':
            task.result = libmath::subtraction(task.val_1, task.val_2);
            break;
        case '*':
            task.result = libmath::multiplication(task.val_1, task.val_2);
            break;
        case '/':
            task.status = libmath::division(task.val_1, task.val_2, task.result);
            break;
        case '^':
            task.result = libmath::power(task.val_1, task.val_2);
            break;

        default:
            task.status = 1;
        }
    }

    void output(Task &task)
    {
        if (task.status == 0)
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
        }
    }
}
namespace app
{
    void run(int argc, char** argv)
    {
        Task task;
        parse(argc, argv, task);
        calculate(task);
        output(task);
    }
}