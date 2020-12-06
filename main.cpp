#include "JSONDatabase.h"
#include "UserInterface.h"

int main()
{
	DatabaseAccessInterface* database = new JSONDatabase();	
	UserInterface UI;
	UI.Menu();
	database->FromFile();

	int choice{};
	while (choice !=5)
	{
		choice = UI.NubmerInput();
		switch (choice)
		{
		case 1:
			UI.ClearConsole();
			database->Add();
			UI.ClearConsole();
			UI.Menu();
			break;
		case 2:
			UI.ClearConsole();
			database->List();
			UI.ClearConsole();
			UI.Menu();
			break;
		case 3:
			UI.ClearConsole();
			database->Modify();
			UI.ClearConsole();
			UI.Menu();
			break;
		case 4:
			UI.ClearConsole();
			database->Delete();
			UI.ClearConsole();
			UI.Menu();
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
