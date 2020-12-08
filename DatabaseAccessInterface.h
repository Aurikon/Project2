#ifndef DATABASEACCESSINTERFACE_H
#define DATABASEACCESSINTERFACE_H

#include "Student.h"
#include <string>
#include <fstream>


class DatabaseAccessInterface
{
public:
	virtual void Add(Student& s) = 0;
	virtual std::vector<Student> List() = 0;
	virtual void Modify(unsigned int ID, std::string firstName, std::string lastName, std::string course, std::string section) = 0;
	virtual void Delete(unsigned int ID) = 0;

	virtual bool IsIDAviable(unsigned int ID) = 0;

	virtual Student GetStudentByID(unsigned int ID) = 0;

	virtual void ToFile() = 0;
	virtual void FromFile() = 0;

	void ClearFile(std::string fileName);
	bool IsFileEmpty(std::ifstream& is);
};

#endif