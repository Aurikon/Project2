#include "UserInterface.h"
#include <iostream>
#include <string>

#ifdef __linux__ 
#define CONSOLE_CLEAR_SYSTEM_ARG "clear"
#elif _WIN32
#define CONSOLE_CLEAR_SYSTEM_ARG "cls"
#else 
#error "OS not supported!"
#endif

void UserInterface::Menu()
{
    ClearConsole();

    std::cout << "====== STUDENT DATABASE MANAGMENT SYSTEM ====== \n\n\n\n\n";
    std::cout << "\t 1.Add          Records \n";
    std::cout << "\t 2.List         Records \n";
    std::cout << "\t 3.Modify       Records \n";
    std::cout << "\t 4.Delete       Records \n";
    std::cout << "\t 5.Exit         Records \n";
    std::cout << "\t Select Your Choice :=> ";
}

void UserInterface::ClearConsole()
{
    if (system(CONSOLE_CLEAR_SYSTEM_ARG))
    {
        std::cout << "Something is wrong in function ClearConsole()\n";
    }
}

int UserInterface::NubmerInput()
{
    std::string inputString{};
    int number{};
    bool isNumber = false;

    while (!isNumber)
    {
        try
        {
            std::getline(std::cin, inputString);
            number = std::stoi(inputString);
            isNumber = true;
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "Invalid input \n";
        }
    }
    return number;
}