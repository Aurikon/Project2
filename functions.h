#pragma once
#include <vector>
#include "Student.h"
#include <iostream>
#include "Student.h"
#include <fstream>
#include <exception>



class databaseAccess
{
private:
	std::vector<Student> students{};

public:
	
	void ToJSON();
	
	void List();
	
	void Add();
	
	void StudentsFill();
	
	void Modify();
	
	void Delete();
	
};
