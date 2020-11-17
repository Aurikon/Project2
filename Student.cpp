#include "Student.h"

Student::Student() = default;

Student::Student(unsigned int ID, std::string firstName, std::string lastName, std::string course, std::string section):
	ID(ID),
	firstName(firstName),
	lastName(lastName),
	course(course),
	section(section)
{
}

unsigned int Student::GetID()
{
	return ID;
}
std::string Student::GetFirstName()
{
	return firstName;
}
std::string Student::GetLastName()
{
	return lastName;
}
std::string Student::GetCourse()
{
	return course;
}
std::string Student::GetSection()
{
	return section;
}


void Student::SetID(unsigned int ID)
{
	this->ID = ID;
}
void Student::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Student::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Student::SetCourse(std::string course)
{
	this->course = course;
}
void Student::SetSection(std::string section)
{
	this->section = section;
}

std::ostream& operator<<(std::ostream& out, const Student& s)
{
	out << s.ID << " " << s.firstName << " " << s.lastName << " " << s.course << " " << s.section << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Student& s)
{
	std::cout << "Enter First Name : ";
	in >> s.firstName;

	std::cout << "Enter Last Name  : ";
	in >> s.lastName;

	std::cout << "Enter course     : ";
	in >> s.course;

	std::cout << "Enter section    : ";
	in >> s.section;

	return in;
}

bool operator==(const Student& s, unsigned int elem)
{
	return s.ID == elem;
}