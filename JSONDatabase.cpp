#include "UserInterface.h"
#include "JSONDatabase.h"

#define FileName "data.json"

void JSONDatabase::IDCorrectionAfterDelete()
{
    for (std::size_t i = 0; i < students.size(); ++i)
    {
        students[i].SetID(i);
    }
}

bool JSONDatabase::IsIDAviable(unsigned int ID)
{
    return ID < students.size();
}

void JSONDatabase::Add()
{
    bool adding = true;

    while (adding)
    {
        Student inputStudent;
        std::cin >> inputStudent;
        inputStudent.SetID(students.size());

        students.push_back(inputStudent);
        ToFile();

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
}

void JSONDatabase::List()
{
    for (auto& student : students)
    {
        std::cout << student << "\n";
    }

    std::string in{};
    std::cout << "Press any key to return menu ";
    std::getline(std::cin, in);
}

void JSONDatabase::Modify()
{
    std::cout << "Enter student ID for modify: ";
    unsigned int ID = UserInterface::NubmerInput();

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
   
    ToFile();

}

void JSONDatabase::Delete()
{
    std::cout << "Enter student ID for delete: ";

    unsigned int ID = UserInterface::NubmerInput();
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
    ToFile();

}

void JSONDatabase::FromFile()
{
    std::size_t size{};
    std::ifstream is(FileName);
    if (IsFileEmpty(is))
    {
        students.resize(0);
        ToFile();
    }
    try
    {
        cereal::JSONInputArchive iarchive(is);
        iarchive(size);

        students.resize(size);

        for (std::size_t i = 0; i < students.size(); ++i)
        {
            iarchive(students[i]);
        }
    }
    catch (std::runtime_error& EmptyFile)
    {
        std::cout << "\n The file " << FileName << " is damaged \n Clear this file? <Y/N>";
        std::string in;
        std::getline(std::cin, in);
        if (in == "N" || in == "n")
        {
            exit(0);
        }
        else if (in == "y" || in == "Y")
        {
            ClearFile(FileName);
        }
    }
}

void JSONDatabase::ToFile()
{
    std::ofstream os(FileName);
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
