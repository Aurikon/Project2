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

Student JSONDatabase::GetStudentByID(unsigned int ID)
{
    return students[ID];
}
void JSONDatabase::Add(Student& s)
{
    s.SetID(students.size());
    students.push_back(s);
    ToFile();
}

std::vector<Student> JSONDatabase::List()
{
    return students;
}

void JSONDatabase::Modify(unsigned int ID, std::string firstName, std::string lastName, std::string course, std::string section)
{
    students[ID].SetFirstName(firstName);
    students[ID].SetLastName(lastName);
    students[ID].SetCourse(course);
    students[ID].SetSection(section);
    ToFile();
}

void JSONDatabase::Delete(unsigned int ID)
{
    auto it = students.begin() + ID;
    students.erase(it);
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

