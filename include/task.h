#pragma once

#include <optional>
#include <string>

struct Task
{
    std::optional<int> value_1;
    std::optional<char>  operation;
    std::optional<int> value_2;
    int result;
    int status;


    Task(std::optional<int> val_1 = std::nullopt, std::optional<char> op = std::nullopt, std::optional<int> val_2 = std::nullopt)
    : value_1(val_1), operation(op), value_2(val_2), result(0), status(0)
    {
    }

  
};
