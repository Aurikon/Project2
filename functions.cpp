#include "functions.h"


void databaseAccess::ToJSON()
{
    std::ofstream os("data.json");
    cereal::JSONOutputArchive oarchive(os);
    oarchive.setNextName("Size");
    oarchive(students.size());
    for (std::size_t i = 0; i < students.size(); ++i)
    {
        std::string tmp = "Student " + std::to_string(students[i].GetID());
        oarchive.setNextName(tmp.c_str());
        oarchive(students[i]);
    }
}

void databaseAccess::List()
{
    system("clear");
    for (auto& elem : students)
    {
        std::cout << elem << "\n";
    }
    char c{};
    std::cout << "Press any key to return menu ";
    std::cin >> c;
    system("clear");
}

void databaseAccess::StudentsFill()
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
    catch (std::runtime_error& e)
    {
        size = 0;
    }
}

void databaseAccess::Delete()
{
    system("clear");

    std::cout << "Enter student ID for delete: ";
    unsigned int ID{};
    std::cin >> ID;
    if (ID > students.size())
    {
        std::cout << "No such student with ID " << ID << "\n";
        return;
    }
    auto it = students.begin() + ID;

    students.erase(it);
    for (std::size_t i = 0; i < students.size(); ++i)
    {
        students[i].SetID(i);
    }
    ToJSON();

    system("clear");
}

void databaseAccess::Add()
{
    system("clear");
    bool adding = true;
    while (adding)
    {
        unsigned long int ID = students.size();
        std::string firstName{};
        std::string lastName{};
        std::string course{};
        std::string section{};


        std::cout << "Enter First Name : ";
        std::cin >> firstName;

        std::cout << "Enter Last Name  : ";
        std::cin >> lastName;

        std::cout << "Enter course     : ";
        std::cin >> course;

        std::cout << "Enter section    : ";
        std::cin >> section;

        students.push_back(Student(ID, firstName, lastName, course, section));
        ToJSON();
        while (1)
        {
            char c;
            std::cout << "Add Another Record <Y/N> ";
            std::cin >> c;
            if (c == 'N' || c == 'n')
            {
                adding = false;
                break;
            }
            else if (c == 'y' || c == 'Y')
            {
                break;
            }
        }
    }
    system("clear");
}

void databaseAccess::Modify()
{
    system("clear");

    std::cout << "Enter student ID for modify: ";
    unsigned int ID{};
    std::cin >> ID;


    std::cout << "Current First Name: " << students[ID].GetFirstName() << "\n";
    std::cout << "Current Last  Name: " << students[ID].GetLastName() << "\n";
    std::cout << "Current Course    : " << students[ID].GetCourse() << "\n";
    std::cout << "Current Section   : " << students[ID].GetSection() << "\n\n";

    std::string firstName{};
    std::string lastName{};
    std::string course{};
    std::string section{};

    std::cout << "Enter First Name : ";
    std::cin >> firstName;
    students[ID].SetFirstName(firstName);

    std::cout << "Enter Last Name  : ";
    std::cin >> lastName;
    students[ID].SetLastName(lastName);

    std::cout << "Enter course     : ";
    std::cin >> course;
    students[ID].SetCourse(course);

    std::cout << "Enter section    : ";
    std::cin >> section;
    students[ID].SetSection(section);
    ToJSON();

    system("clear");
}