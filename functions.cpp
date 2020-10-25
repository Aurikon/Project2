
#include "functions.h"

void Menu()
{
	std::cout << "====== STUDENT DATABASE MANAGMENT SYSTEM ====== \n\n\n\n\n";
	std::cout << "\t 1.Add		Records \n";
	std::cout << "\t 2.List		Records \n";
	std::cout << "\t 3.Modify	Records \n";
	std::cout << "\t 4.Delete	Records \n";
	std::cout << "\t 5.Exit		Records \n";
	std::cout << "\t Select Your Choice :=> ";


}
void ToJSON(std::vector<Student>& studentList)
{
	std::ofstream os("data.json");
	cereal::JSONOutputArchive oarchive(os);
	oarchive(cereal::make_nvp("Student Count:", studentList.size()));
	for (std::size_t i = 0; i < studentList.size(); ++i)
	{
		oarchive(cereal::make_nvp("Student ID: " + std::to_string(i), studentList[i].GetID()));
		oarchive(cereal::make_nvp("Student " + std::to_string(i) + " First Name:", studentList[i].GetFirstName()));
		oarchive(cereal::make_nvp("Student " + std::to_string(i) + " Last Name:", studentList[i].GetLastName()));
		oarchive(cereal::make_nvp("Student " + std::to_string(i) + " Course:", studentList[i].GetCourse()));
		oarchive(cereal::make_nvp("Student " + std::to_string(i) + " Section:", studentList[i].GetSection()));
	}
}

void List(std::vector<Student>& studentList)
{
	system("cls");
	for (auto& elem : studentList)
	{
		std::cout << elem << "\n";
	}
	char c{};
	std::cout << "Press any key to return menu ";
	std::cin >> c;
	system("cls");
}

void Add(std::vector<Student>& studentList)
{
	system("cls");
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
		ToJSON(studentList);


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
	system("cls");
}

void StudentListFill(std::vector<Student>& studentList)
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

			studentList[i] = Student(ID, firstName, lastName, course, section);
		}
	}
	catch (std::runtime_error& e)
	{
		size = 0;
	}
}

void Delete(std::vector<Student>& studentList)
{
	system("cls");

	std::cout << "Enter student ID for delete: ";
	unsigned int ID{};
	std::cin >> ID;
	auto it = std::find(studentList.begin(), studentList.end(), ID);

	studentList.erase(it);
	for (std::size_t i = 0; i < studentList.size(); ++i)
	{
		studentList[i].SetID(i);
	}
	ToJSON(studentList);

	system("cls");
}

void Modify(std::vector<Student>& studentList)
{
	system("cls");

	std::cout << "Enter student ID for modify: ";
	unsigned int ID{};
	std::cin >> ID;
	auto it = std::find(studentList.begin(), studentList.end(), ID);

	std::cout << "Current First Name: " << it->GetFirstName() << "\n";
	std::cout << "Current Last  Name: " << it->GetLastName() << "\n";
	std::cout << "Current Course    : " << it->GetCourse() << "\n";
	std::cout << "Current Section   : " << it->GetSection() << "\n\n";

	std::string firstName{};
	std::string lastName{};
	std::string course{};
	std::string section{};

	std::cout << "Enter First Name : ";
	std::cin >> firstName;
	it->SetFirstName(firstName);

	std::cout << "Enter Last Name  : ";
	std::cin >> lastName;
	it->SetLastName(lastName);

	std::cout << "Enter course     : ";
	std::cin >> course;
	it->SetCourse(course);

	std::cout << "Enter section    : ";
	std::cin >> section;
	it->SetSection(section);


	ToJSON(studentList);

	system("cls");
}
