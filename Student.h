#pragma once
#include <string>
#include "cereal/access.hpp"
#include "cereal/archives/json.hpp"
#include <ostream>
class Student
{
private:
	friend class cereal::access;
	unsigned int ID;
	std::string firstName;
	std::string lastName;
	std::string course;
	std::string section;

public:
	Student();
	Student(unsigned int ID, std::string firstName, std::string lastName, std::string course, std::string section);

	unsigned int GetID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetCourse();
	std::string GetSection();
	

	void SetID(unsigned int ID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetCourse(std::string course);
	void SetSection(std::string section);

	friend std::ostream& operator<<(std::ostream& out, const Student& s);
	friend bool operator==(const Student& s, unsigned int elem);


	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(cereal::make_nvp("Student ID: ", ID),
			cereal::make_nvp("Student " + std::to_string(ID) + " First Name:", firstName),
			cereal::make_nvp("Student " + std::to_string(ID) + " Last Name:", lastName),
			cereal::make_nvp("Student " + std::to_string(ID) + " Course:", course),
			cereal::make_nvp("Student " + std::to_string(ID) + " Section:", section));

	}

};