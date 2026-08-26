#pragma once

#include "../include/task.h"

#include <nlohmann/json.hpp>
class Parser
{
  private:
    using json = nlohmann::json;

  public:
    Task parse(int argc, char** argv);
  
};