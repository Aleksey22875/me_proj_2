#pragma once

#include <optional>
class Task
{
  private:
    int value_1;
    char operation;
    std::optional<int> value_2;
    int result;
    int status;

  public:
    Task(int val_1, char operation, std::optional<int> val_2 = std::nullopt);

    int getVal_1() const;

    std::optional<int> getVal_2() const;

    void setStatus(int status);

    void setResult(int res);

    int getResult() const;

    int getStatus() const;

    char getOperation() const;
};
