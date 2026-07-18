#include "../include/application.h"

#include "../include/parser.h"

#include <iostream>

void Application::run(int argc, char** argv)
{   
    try
    { 
    Task tasks = parser.parse(argc, argv);

    calculator.calculate(tasks);
    if(tasks.getStatus() == 0 && tasks.getOperation() != "!")
    {
        std::cout << tasks.getVal_1() << ' ' << tasks.getOperation() << ' ' << tasks.getVal_2().value() << " = " << tasks.getResult() << std::endl;

    }else if(tasks.getStatus() == -1){
        std::cout << "Devision by zero!" << std::endl;
    }else if(tasks.getStatus() == 1)
    {
        std::cout << "Unknow error!" << std::endl;
    }else if(tasks.getStatus() == 2)
    {
        std::cout << "Overflow type!" << std::endl;
    }else if(tasks.getOperation() == "!")
    {
        std::cout << tasks.getVal_1() << ' ' << tasks.getOperation() << " = " << tasks.getResult() << std::endl;
    }

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}