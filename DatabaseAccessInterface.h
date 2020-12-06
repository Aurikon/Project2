#ifndef DATABASEACCESSINTERFACE_H
#define DATABASEACCESSINTERFACE_H

#include "FileInputOutput.h"

class DatabaseAccessInterface : public FileInputOutput
{
public:
	virtual void Add() = 0;
	virtual void List() = 0;
	virtual void Modify() = 0;
	virtual void Delete() = 0;
};

#endif