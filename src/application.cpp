#include "../include/application.h"

#include <iostream>
#include <stdexcept>
#include <logger.h>

void Application::run(int argc, char** argv)
{
    try
    {
        Logger::instance().info("Appliction started");

        Task task = parser.parse(argc, argv);

        Logger::instance().info("Operation parsed: " + task.getOperation());


        calculator.calculate(task);

        Logger::instance().info("Calculation comleted, result: " + std::to_string(task.getResult()));


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
        Logger::instance().error("Overflow: " + std::string(e.what()));
        
        std::cout << "Overflow: " << e.what() << std::endl;
    }
    catch (const std::domain_error& e)
    {
        Logger::instance().error("Domain_error: " + std::string(e.what()));

        std::cout << "Domain error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        Logger::instance().error("Invalid_argument: " + std::string(e.what()));
        
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}