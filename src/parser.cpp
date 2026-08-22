#include "../include/parser.h"

#include <stdexcept>
#include <iostream>
#include <string>

void Parser::print_help()
{
    std::cout << "Calculator usage:\n";
    std::cout << "  calculator '<json>'\n\n";

    std::cout << "JSON format:\n";
    std::cout << "  {\n";
    std::cout << "    \"first\": <number>,\n";
    std::cout << "    \"second\": <number>,\n";
    std::cout << "    \"operation\": \"<op>\"\n";
    std::cout << "  }\n\n";

    std::cout << "Operations:\n";
    std::cout << "  +  addition\n";
    std::cout << "  -  subtraction\n";
    std::cout << "  *  multiplication\n";
    std::cout << "  /  division\n";
    std::cout << "  ^  power\n";
    std::cout << "  !  factorial\n\n";

    std::cout << "Examples:\n";
    std::cout
        << "  calculator '{\"first\":5,\"second\":10,\"operation\":\"+\"}'\n";
    std::cout << "  calculator '{\"first\":5,\"operation\":\"!\"}'\n\n";

    std::cout << "Help:\n";
    std::cout << "  calculator -h\n";
    std::cout << "  calculator --h\n";
}

Task Parser::parse(int argc, char** argv)
{

    if (argc != 2)
    {
        throw std::invalid_argument("Wrong argument count");
    }

    if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--h" || std::string(argv[1]) == "--help")
    {
        print_help();
        exit(0);
    }
    json data = json::parse(argv[1]);
    std::optional<int> second = std::nullopt;

    if (data.contains("second"))
    {
        second = data["second"].get<int>();
    }

    return Task(data["first"].get<int>(), data["operation"].get<std::string>(),
                second);
}
