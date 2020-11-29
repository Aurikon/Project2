#pragma once
#include <vector>
#include "Student.h"
#include <iostream>
#include "Student.h"
#include <fstream>
#include <exception>

class DatabaseAccess
{
private:
	
	std::vector<Student> students{};

	void IDCorrectionAfterDelete();
	bool IsIDAviable(unsigned int ID);
public:
	
	int Input();

	void Menu();

	void List();
	
	void Add();
	
	void Modify();
	
	void Delete();

	void FromJSON();

	void ToJSON();

	void ClearFile();
	
	bool IsFileEmpty(std::ifstream& is);
};
