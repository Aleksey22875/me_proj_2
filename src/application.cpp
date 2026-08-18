#include "../include/application.h"

#include <iostream>
#include <stdexcept>

void Application::run(int argc, char** argv)
{
    try
    {
        Task task = parser.parse(argc, argv);

        calculator.calculate(task);

        if (task.getOperation() == "!")
        {
            std::cout << task.getVal_1() << " " << task.getOperation() << " = "
                      << task.getResult() << std::endl;
        }
        else
        {
            std::cout << task.getVal_1() << " " << task.getOperation() << " "
                      << task.getVal_2().value() << " = " << task.getResult()
                      << std::endl;
        }
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "Overflow: " << e.what() << std::endl;
    }
    catch (const std::domain_error& e)
    {
        std::cout << "Domain error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
}