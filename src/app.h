#pragma once

namespace app
{

    struct Task
{
    int val_1;
    char operation;
    int val_2 = 0;
    int status;
    int result;
};

    void run(int argc, char** argv);
    void print_help();
}