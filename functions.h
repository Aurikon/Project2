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
	std::vector<Student> studentList{};

public:
	
	void ToJSON();
	
	void List();
	
	void Add();
	
	void StudentListFill();
	
	void Modify();
	
	void Delete();
	
};
