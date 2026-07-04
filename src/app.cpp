#include "app.h"

#include "libmath.hpp"

#include <cstdio>

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
void pars(int x, int y, char op, Task& task)
{
    task.val_1 = x;
    task.operation = op;
    task.val_2 = y;
}

void calculate(Task& task)
{
    task.status = 0;
    switch (task.operation)
    {
        case '+':
            task.status =
                libmath::addition(task.val_1, task.val_2, task.result);
            break;
        case '-':
            task.status =
                libmath::subtraction(task.val_1, task.val_2, task.result);
            break;
        case '*':
            task.status =
                libmath::multiplication(task.val_1, task.val_2, task.result);
            break;
        case '/':
            task.status =
                libmath::division(task.val_1, task.val_2, task.result);
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

void output(Task& task)
{
    if (task.status == 0 && task.operation != '!')
    {
        printf("%d %c %d = %d\n",
            task.val_1,
            task.operation,
            task.val_2,
            task.result);
    }
    else if (task.status == -1)
    {
        printf("division by zero!\n");
    }
    else if (task.status == 1)
    {
        printf("Unknow error!\n");
    }
    else if (task.operation == '!')
    {
        printf("%d %c = %d\n",
            task.val_1,
            task.operation,
            task.result);
    }
    else if (task.status == 2)
    {
        printf("Type overflow!");
    }
}
} // namespace
namespace app
{
void run(int x, int y, char op)
{
    Task task;
    pars(x, y, op, task);
    calculate(task);
    output(task);
}

void print_help()
{
    printf("Calculator usage:\n");
    printf("  -x <number>   first operand\n");
    printf("  -y <number>   second operand\n");
    printf("  -o <op>       operation (+, -, *, /, ^)\n");
    printf("  -h             show help\n\n");

    printf("Examples:\n");
    printf("  calculator -x 5 -y 10 -o +\n");
    printf("  calculator -x 2 -y 3 -o ^\n");
}
} // namespace app