#pragma once
#include <vector>
#include "Student.h"
#include <iostream>
#include "Student.h"
#include <fstream>
#include <exception>

void Menu();

void ToJSON(std::vector<Student>& studentList);

void List(std::vector<Student>& studentList);

void Add(std::vector<Student>& studentList);

void StudentListFill(std::vector<Student>& studentList);

void Modify(std::vector<Student>& studentList);

void Delete(std::vector<Student>& studentList);
