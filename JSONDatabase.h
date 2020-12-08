#ifndef JSONDATABASE_H
#define JSONDATABASE_H

#include "DatabaseAccessInterface.h"
#include <vector>

class JSONDatabase : public DatabaseAccessInterface
{
private:

	std::vector<Student> students{};

	void IDCorrectionAfterDelete();
public:
	bool IsIDAviable(unsigned int ID) override;

	Student GetStudentByID(unsigned int ID) override;

	void ToFile() override;
	void FromFile() override;

	void Add(Student& s) override;
	std::vector<Student> List() override;
	void Modify(unsigned int ID, std::string firstName, std::string lastName, std::string course, std::string section) override;
	void Delete(unsigned int ID) override;
};

#endif
