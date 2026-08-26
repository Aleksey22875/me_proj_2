#include "../include/parser.h"

#include <stdexcept>
#include <iostream>
#include <string>



Task Parser::parse(int argc, char** argv)
{

    if (argc != 2)
    {
        throw std::invalid_argument("Wrong argument count");
    }
    if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--h" || std::string(argv[1]) == "--help")
    {
        return Task{std::nullopt, 'h', std::nullopt};
    } 

    json data = json::parse(argv[1]);
    std::optional<int> second = std::nullopt;

    if (data.contains("second"))
    {
        second = data["second"].get<int>();
    }

    std::string operation = data["operation"].get<std::string>();

    return Task{data["first"].get<int>(), operation[0],
                second};
}
