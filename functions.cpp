#include "functions.h"


void databaseAccess::ToJSON()
{
	std::ofstream os("data.json");
	cereal::JSONOutputArchive oarchive(os);
	oarchive(cereal::make_nvp("Student Count:", studentList.size()));
	for (std::size_t i = 0; i < studentList.size(); ++i)
	{
 		oarchive(cereal::make_nvp("Student ID:", studentList[i].GetID()));
    	oarchive(cereal::make_nvp("Student " + std::to_string(studentList[i].GetID()) + " First Name:", studentList[i].GetFirstName()));
        oarchive(cereal::make_nvp("Student " + std::to_string(studentList[i].GetID()) + " Last Name:", studentList[i].GetLastName()));
        oarchive(cereal::make_nvp("Student " + std::to_string(studentList[i].GetID()) + " Course:", studentList[i].GetCourse()));
        oarchive(cereal::make_nvp("Student " + std::to_string(studentList[i].GetID()) + " Section:", studentList[i].GetSection()));
 	}
}

void databaseAccess::List()
{
	system("clear");
	for (auto& elem : studentList)
	{
	 	 std::cout << elem << "\n";
	}
	char c{};
 	std::cout << "Press any key to return menu ";
 	std::cin >> c;
 	system("clear");
}

void databaseAccess::StudentListFill()
{
	std::size_t size{};
 	std::ifstream is("data.json");
 	try
 	{
 		cereal::JSONInputArchive iarchive(is);
        iarchive(size);
  		studentList.resize(size);
  		for (int i = 0; i < studentList.size(); ++i)
  		{
            unsigned int ID{};
            std::string firstName{};
            std::string lastName{};
            std::string course{};
            std::string section{};

            iarchive(ID);
            iarchive(firstName);
            iarchive(lastName);
            iarchive(course);
            iarchive(section);

            Student s(ID, firstName, lastName, course, section);

            studentList[i] = s;
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
 	if(ID > studentList.size())
 	{
 	 	std::cout << "No such student with ID " << ID << "\n";
 	 	return;
 	}
 	auto it = studentList.begin() + ID;

 	studentList.erase(it);
 	for (std::size_t i = 0; i < studentList.size(); ++i)
	{
  		studentList[i].SetID(i);
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
    	unsigned long int ID = studentList.size();
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

        studentList.push_back(Student(ID, firstName, lastName, course, section));
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
        

        std::cout << "Current First Name: " << studentList[ID].GetFirstName() << "\n";
        std::cout << "Current Last  Name: " << studentList[ID].GetLastName() << "\n";  
        std::cout << "Current Course    : " << studentList[ID].GetCourse() << "\n";    
        std::cout << "Current Section   : " << studentList[ID].GetSection() << "\n\n";

        std::string firstName{};
        std::string lastName{};
        std::string course{};
        std::string section{};

        std::cout << "Enter First Name : ";
        std::cin >> firstName;
        studentList[ID].SetFirstName(firstName);

        std::cout << "Enter Last Name  : ";
        std::cin >> lastName;
        studentList[ID].SetLastName(lastName);

        std::cout << "Enter course     : ";
        std::cin >> course;
        studentList[ID].SetCourse(course);
  		ToJSON();

        system("clear");
}
