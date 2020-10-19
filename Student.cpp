#include "Student.h"

void epilogue(cereal::JSONOutputArchive&, const Student&) {}
void prologue(cereal::JSONOutputArchive&, const Student&) {}
Student::Student() = default;

Student::Student(std::string firstName, std::string lastName, std::string course, std::string section):
	firstName(firstName),
	lastName(lastName),
	course(course),
	section(section)
{
}
