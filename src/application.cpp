#include "../include/application.h"

#include <logger.h>

#include <iostream>
#include <stdexcept>
void Application::print_help()
{
    std::cout << "Calculator usage:\n";
    std::cout << "  calculator '<json>'\n\n";

    std::cout << "JSON format:\n";
    std::cout << "  {\n";
    std::cout << "    \"first\": <number>,\n";
    std::cout << "    \"second\": <number>,\n";
    std::cout << "    \"operation\": \"<op>\"\n";
    std::cout << "  }\n\n";

    std::cout << "Operations:\n";
    std::cout << "  +  addition\n";
    std::cout << "  -  subtraction\n";
    std::cout << "  *  multiplication\n";
    std::cout << "  /  division\n";
    std::cout << "  ^  power\n";
    std::cout << "  !  factorial\n\n";

    std::cout << "Examples:\n";
    std::cout
        << "  calculator '{\"first\":5,\"second\":10,\"operation\":\"+\"}'\n";
    std::cout << "  calculator '{\"first\":5,\"operation\":\"!\"}'\n\n";

    std::cout << "Help:\n";
    std::cout << "  calculator -h\n";
    std::cout << "  calculator --h\n";
}

void Application::run(int argc, char** argv)
{

    try
    {
        Logger::instance().info("Appliction started");

        Task task = parser.parse(argc, argv);

        Logger::instance().info("Operation parsed: " + task.operation.value());

        calculator.calculate(task);

        Logger::instance().info("Calculation completed, result: " +
                                std::to_string(task.result));

        if(task.operation == 'h')
        {
            print_help();
            exit(0);
        }

        if (task.operation == '!')
        {
            std::cout << task.value_1.value() << " " << task.operation.value() << " = "
                      << task.result << std::endl;
        }
        else
        {
            std::cout << task.value_1.value() << " " << task.operation.value() << " "
                      << task.value_2.value() << " = " << task.result
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
        Logger::instance().error("Error: " + std::string(e.what()));

        std::cout << "Error: " << e.what() << std::endl;
    }
}