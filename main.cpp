#include <iostream>
#include "Student.h"
#include <fstream>
#include "cereal/types/vector.hpp"

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

void Add()
{
	system("cls");
	bool adding = true;
	while (adding)
	{
		std::string firstName;
		std::string lastName;
		std::string course;
		std::string section;


		std::cout << "Enter First Name : ";
		std::cin >> firstName;

		std::cout << "Enter Last Name  : ";
		std::cin >> lastName;

		std::cout << "Enter course     : ";
		std::cin >> course;

		std::cout << "Enter section    : ";
		std::cin >> section;

		
		Student s(firstName, lastName, course, section);
		std::ofstream os("data.json", std::ios_base::app);
		cereal::JSONOutputArchive archive(os);
		//s.serialize(archive);
		archive(s);


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

int main()
{
	/*std::ifstream is("data.json");
	cereal::JSONInputArchive inArchive(is);
	Student s;
	s.load(inArchive);*/

	Menu();

	int choice;
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			Add();
			Menu();
			std::cin >> choice;
			break;
		case 2:
			//List();
			break;
		case 3:
			//Modify();
			break;
		case 4:
			//Delete();
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong choice. Please, choice number 1-5";
			break;
		}
	}
	
	return 0;
}