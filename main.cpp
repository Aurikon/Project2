#include "functions.h"

void Menu()
{
        system("clear");

        std::cout << "====== STUDENT DATABASE MANAGMENT SYSTEM ====== \n\n\n\n\n";
        std::cout << "\t 1.Add          Records \n";
        std::cout << "\t 2.List         Records \n";
        std::cout << "\t 3.Modify       Records \n";
        std::cout << "\t 4.Delete       Records \n";
        std::cout << "\t 5.Exit         Records \n";
        std::cout << "\t Select Your Choice :=> ";
}

int main()
{
	databaseAccess database;	
	Menu();
	
	int choice{};
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			database.Add();
			Menu();
			std::cin >> choice;
			break;
		case 2:
			database.List();
			Menu();
			std::cin >> choice;
			break;
		case 3:
			database.Modify();
			Menu();
			std::cin >> choice;
			break;
		case 4:
			database.Delete();
			Menu();
			std::cin >> choice;
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong choice. Please, choice number 1-5";
			break;
		}
	}
	
	database.ToJSON();

	return 0;
}
