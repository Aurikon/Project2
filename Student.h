#pragma once
#include <string>
#include "cereal/access.hpp"
#include "cereal/archives/json.hpp"
class Student
{
private:
	friend class cereal::access;
	std::string firstName;
	std::string lastName;
	std::string course;
	std::string section;

public:
	Student();
	Student(std::string firstName, std::string lastName, std::string course, std::string section);

	template<class Archive>
	void save(Archive& archive) const
	{
		archive(CEREAL_NVP(firstName), CEREAL_NVP(lastName), CEREAL_NVP(course), CEREAL_NVP(section));
	}
	template<class Archive>
	void load(Archive& archive)
	{
		archive(CEREAL_NVP(firstName), CEREAL_NVP(lastName), CEREAL_NVP(course), CEREAL_NVP(section));
	}
	
};