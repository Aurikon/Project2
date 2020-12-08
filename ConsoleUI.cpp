#include "ConsoleUI.h"
#include <iostream>

#ifdef __linux__ 
#define CONSOLE_CLEAR_SYSTEM_ARG "clear"
#elif _WIN32
#define CONSOLE_CLEAR_SYSTEM_ARG "cls"
#else 
#error "OS not supported!"
#endif

void ConsoleUI::UIMenu()
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

void ConsoleUI::UIAdd(DatabaseAccessInterface& db)
{
    ClearConsole();

    Student inputStudent;
    std::cin >> inputStudent;
    db.Add(inputStudent);

    while (true)
    {
        std::cout << "Add Another Record <Y/N> \n";
        std::string in;
        std::getline(std::cin, in);

        if (in == "Y" || in == "y")
        {
            std::cin >> inputStudent;
            db.Add(inputStudent);
            break;
        }
        else if (in == "N" || in == "n")
        {
            break;
        }
    }

    std::cout << "Students added successfully \nPress any key to return menu ";
    ExitInput();
    ClearConsole();
}

void ConsoleUI::UIList(DatabaseAccessInterface& db)
{
    ClearConsole();

    std::vector<Student> students = db.List();
    for (auto& student : students)
    {
        std::cout << student << "\n";
    }
    std::cout << "Press any key to return menu ";
    ExitInput();
    ClearConsole();
}

void ConsoleUI::UIModify(DatabaseAccessInterface& db)
{
    ClearConsole();

    std::cout << "Enter student ID for modify: ";
    unsigned int ID = NubmerInput();

    if (db.IsIDAviable(ID))
    {
        Student studentForModify = db.GetStudentByID(ID);
        std::cout << studentForModify;

        std::cout << "Current First Name: " << studentForModify.GetFirstName() << "\n";
        std::cout << "Current Last  Name: " << studentForModify.GetLastName() << "\n";
        std::cout << "Current Course    : " << studentForModify.GetCourse() << "\n";
        std::cout << "Current Section   : " << studentForModify.GetSection() << "\n\n";

        std::cout << "Enter new values << \n";

        std::string firstName;
        std::string lastName;
        std::string course;
        std::string section;
        std::getline(std::cin, firstName);
        std::getline(std::cin, lastName);
        std::getline(std::cin, course);
        std::getline(std::cin, section);
        db.Modify(ID, firstName, lastName, course, section);
        std::cout << "Changes made successfully \nPress any key to return menu ";
        ExitInput();
    }
    else
    {
        std::cout << "ID not found \n Please, try again \n";
        ExitInput();
    }
}

void ConsoleUI::UIDelete(DatabaseAccessInterface& db)
{
    ClearConsole();

    std::cout << "Enter student ID for delete: ";
    unsigned int ID =NubmerInput();

    if (db.IsIDAviable(ID))
    {
        db.Delete(ID);

        std::cout << "Student removed from database \nPress any key to return menu ";
        ExitInput();
    }
    else
    {
        std::cout << "ID not found \nPlease, try again \n";
        ExitInput();
    }

    ClearConsole();
}

void ConsoleUI::ClearConsole()
{
    if (system(CONSOLE_CLEAR_SYSTEM_ARG))
    {
        std::cout << "Something is wrong in function ClearConsole()\n";
    }
}

int ConsoleUI::NubmerInput()
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

void ConsoleUI::ExitInput()
{
    std::string exit;
    std::getline(std::cin, exit);
}