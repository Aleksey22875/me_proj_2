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
};
