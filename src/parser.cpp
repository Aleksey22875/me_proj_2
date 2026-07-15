#include "../include/parser.h"

#include <stdexcept>
#include <string>

void Parser::print_help()
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

Task Parser::parse(int argc, char** argv)
{
    if(argc == 3)
    {
        return Task(std::stoi(argv[1]), argv[2][0]);

    }
    if(argc == 2 && std::string(argv[1]) == "-h")
    {
        Parser::print_help();
        std::exit(0); 
    }
    if (argc < 3 || argc > 4)
    {
        throw std::invalid_argument("Wrong argument count");
    }
    
    return Task(std::stoi(argv[1]), argv[2][0], std::stoi(argv[3]));
}
