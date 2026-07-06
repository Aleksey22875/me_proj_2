#include "parser.h"

#include <unistd.h>

#include <cstdlib>

#include <cstdio>
namespace Parser
{
int parse(int argc, char** argv, app::Task& task)
{
    int x = 0;
    int y = 0;
    char op = 0;

    int opt;

    bool hasY = false;

    while ((opt = getopt(argc, argv, "x:y:o:h")) != -1)
    {
        switch (opt)
        {
            case 'x':
                x = atoi(optarg);
                break;
            case 'y':
                y = atoi(optarg);
                hasY = true;
                break;
            case 'o':
                op = optarg[0];
                break;
            case 'h':
                app::print_help();
                return 3;

            default:
                printf("Invalid arguments\n"); 
                return 1;
        }
    }

    if (op != '!' && !hasY)
    {
        printf("Missing second operand\n");
        return 1;
    }
    if (op == '!' && !hasY)
    {
        y = 0;
    }
    task.val_1 = x;
    task.operation = op;
    task.val_2 = y;
    return 0;
}
} // namespace Parser