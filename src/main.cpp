#include "../include/application.h"
#include <iostream>

int main(int argc, char** argv)
try
{

    Application app;
    app.run(argc, argv);
    return 0;
}
catch (...)
{
    std::cout << "Unknow excption\n";
    return 1;
}
