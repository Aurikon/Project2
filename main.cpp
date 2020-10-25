#include "functions.h";

int main()
{
	std::vector<Student> studentList{};
	StudentListFill(studentList);
	Menu();

	int choice{};
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			Add(studentList);
			Menu();
			std::cin >> choice;
			break;
		case 2:
			List(studentList);
			Menu();
			std::cin >> choice;
			break;
		case 3:
			Modify(studentList);
			Menu();
			std::cin >> choice;
			break;
		case 4:
			Delete(studentList);
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
	
	ToJSON(studentList);

	return 0;
}