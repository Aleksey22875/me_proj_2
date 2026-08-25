#pragma once

#include "../include/parser.h"
#include "../include/calculator.h"

class Application
{
  private:
  Parser parser;
  Calculator calculator;

  public:
    void run(int argc, char** argv);
    void print_help();
};
