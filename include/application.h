#pragma once

#include "../include/parser.h"
#include "../include/calculator.h"

class Application
{
  private:
  Parser parser;

  public:
    void run(int argc, char** argv);
    void print_help();
};
