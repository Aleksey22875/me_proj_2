#pragma once

#include <optional>
#include <string>

class Task
{
  private:
    int value_1;
    std::string operation;
    std::optional<int> value_2;
    int result;
    int status;

  public:
    Task(int val_1, std::string operation, std::optional<int> val_2 = std::nullopt);

    int getVal_1() const;

    std::optional<int> getVal_2() const;

    void setStatus(int status);

    void setResult(int res);

    void setVal_1(int res);

    void setVal_2(int res);

    void setOperation(std::string& res);

    int getResult() const;

    int getStatus() const;

    std::string getOperation() const;
};
