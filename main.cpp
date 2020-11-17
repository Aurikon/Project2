#include "functions.h"


int main()
{
	DatabaseAccess database;	
	database.Menu();
	database.FromJSON();

	int choice{};
	while (choice !=5)
	{
		choice = database.Input();
		switch (choice)
		{
		case 1:
			database.Add();
			database.Menu();
			break;
		case 2:
			database.List();
			database.Menu();
			break;
		case 3:
			database.Modify();
			database.Menu();
			break;
		case 4:
			database.Delete();
			database.Menu();
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong choice. Please, enter number 1-5 \n";
		}
	}
	
	database.ToJSON();

	return 0;
}
