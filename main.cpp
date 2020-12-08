#include "JSONDatabase.h"
#include "UserInterface.h"
#include "ConsoleUI.h"

int main()
{
	DatabaseAccessInterface* database = new JSONDatabase();	
	UserInterface* UI = new ConsoleUI();
	database->FromFile();
	int choice{};
	while (choice !=5)
	{
		UI->UIMenu();
		choice =ConsoleUI::NubmerInput();
		switch (choice)
		{
		case 1:
			UI->UIAdd(*database);
			break;
		case 2:
			UI->UIList(*database);
			break;
		case 3:
			UI->UIModify(*database);
			break;
		case 4:
			UI->UIDelete(*database);
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong choice. Please, enter number 1-5 \n";
		}
	}
	
	database->ToFile();

	return 0;
}
