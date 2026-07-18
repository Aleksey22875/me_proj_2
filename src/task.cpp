#include "../include/task.h"

Task::Task(int val_1, std::string operation, std::optional<int> val_2) :
    value_1(val_1), operation(operation), value_2(val_2)
{}
int Task::getVal_1() const
{
    return this->value_1;
}

std::optional<int> Task::getVal_2() const
{
    return this->value_2;
}

int Task::getResult() const
{
    return result;
}

int Task::getStatus() const
{
    return status;
}

std::string Task::getOperation() const
{
    
    return operation;
}

void Task::setStatus(int stat)
{
    this->status = stat;
}

void Task::setResult(int res)
{
    this->result = res;
}

void Task::setVal_1(int res)
{
    value_1 = res;
}

void Task::setVal_2(int res)
{
    value_2 = res;
}

void Task::setOperation(std::string& res)
{
    operation = res;
}

