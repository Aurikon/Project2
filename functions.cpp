#ifdef __linux__ 
#define SYSTEM_ARG "clear"
#elif _WIN32
#define SYSTEM_ARG "cls"
#else 
#error "OS not supported!"
#endif

#include "functions.h"

void ClearConsole()
{
    if (system(SYSTEM_ARG))
    {
        std::cout << "Something is wrong in function ClearConsole()\n";
    }
}

void DatabaseAccess::IDCorrectionAfterDelete()
{
    for (std::size_t i = 0; i < students.size(); ++i)
    {
        students[i].SetID(i);
    }
}

bool DatabaseAccess::IsIDAviable(unsigned int ID)
{
    return ID < students.size();
}

int DatabaseAccess::Input()
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

void DatabaseAccess::Menu()
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

void DatabaseAccess::Add()
{
    ClearConsole();
    bool adding = true;

    while (adding)
    {
        Student inputStudent;
        std::cin >> inputStudent;
        inputStudent.SetID(students.size());

        students.push_back(inputStudent);
        ToJSON();

        while (true)
        {
            std::string in{};
            std::cout << "Add Another Record <Y/N> \n";
            std::getline(std::cin, in);
            if (in == "N" || in == "n" )
            {
                adding = false;
                break;
            }
            else if (in == "y" || in == "Y" )
            {
                break;
            }
         }
    }
    ClearConsole();
}

void DatabaseAccess::List()
{
    ClearConsole();
    for (auto& student : students)
    {
        std::cout << student << "\n";
    }

    std::string in{};
    std::cout << "Press any key to return menu ";
    std::getline(std::cin, in);

    ClearConsole();
}

void DatabaseAccess::Modify()
{
    ClearConsole();

    std::cout << "Enter student ID for modify: ";
    unsigned int ID = Input();

    if (IsIDAviable(ID))
    {
        std::cout << "Current First Name: " << students[ID].GetFirstName() << "\n";
        std::cout << "Current Last  Name: " << students[ID].GetLastName() << "\n";
        std::cout << "Current Course    : " << students[ID].GetCourse() << "\n";
        std::cout << "Current Section   : " << students[ID].GetSection() << "\n\n";
        std::cin >> students[ID];

        std::string in{};
        std::cout << "Changes made successfully\nPress any key to return menu \n";
        std::getline(std::cin, in);
    }
    else
    {
        std::cout << "ID not found\n";
        std::cout << "Press any key to return menu ";
        std::string in{};
        std::getline(std::cin, in);
    }
   
    ToJSON();

    ClearConsole();
}

void DatabaseAccess::Delete()
{
    ClearConsole();

    std::cout << "Enter student ID for delete: ";

    unsigned int ID = Input();
    if (IsIDAviable(ID))
    {
        auto it = students.begin() + ID;
        students.erase(it);
    }
    else
    {
        std::cout << "ID not found. Check students list and choose correct ID \n";
        std::cout << "Press any key to return menu ";
        std::string in{};
        std::getline(std::cin, in);
    }
    IDCorrectionAfterDelete();
    ToJSON();

    ClearConsole();
}

void DatabaseAccess::FromJSON()
{
    std::size_t size{};
    std::ifstream is("data.json");
    try
    {
        cereal::JSONInputArchive iarchive(is);
        iarchive(size);

        students.resize(size);

        for (int i = 0; i < students.size(); ++i)
        {
            iarchive(students[i]);
        }
    }
    catch (std::runtime_error& EmptyFile)
    {
        size = 0;
    }
}

void DatabaseAccess::ToJSON()
{
    std::ofstream os("data.json");
    cereal::JSONOutputArchive oarchive(os);

    oarchive.setNextName("Students_Size");
    oarchive(students.size());

    for (std::size_t i = 0; i < students.size(); ++i)
    {
        std::string StudentValueForJSON = "Student " + std::to_string(students[i].GetID());
        oarchive.setNextName(StudentValueForJSON.c_str());
        oarchive(students[i]);
    }
}