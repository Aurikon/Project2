#ifndef JSONDATABASE_H
#define JSONDATABASE_H

#include "FileInputOutput.h"
#include "Student.h"
#include "DatabaseAccessInterface.h"
#include <vector>

class JSONDatabase : public DatabaseAccessInterface
{
private:

	std::vector<Student> students{};

	void IDCorrectionAfterDelete();
	bool IsIDAviable(unsigned int ID);
public:

	void ToFile() override;
	void FromFile() override;

	void Add() override;
	void List() override;
	void Modify() override;
	void Delete() override;
};

#endif
