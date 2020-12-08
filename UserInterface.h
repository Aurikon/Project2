#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "DatabaseAccessInterface.h"

class UserInterface
{
public:
	virtual void UIMenu() = 0;
	virtual void UIAdd(DatabaseAccessInterface& db) = 0;
	virtual void UIList(DatabaseAccessInterface& db) = 0;
	virtual void UIModify(DatabaseAccessInterface& db) = 0;
	virtual void UIDelete(DatabaseAccessInterface& db) = 0;
};

#endif
