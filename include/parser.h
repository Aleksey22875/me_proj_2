#pragma once

#include "../include/task.h"
class Parser
{

  public:
    Task parse(int argc, char** argv);
    void print_help();
};