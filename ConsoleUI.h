#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "UserInterface.h"

class ConsoleUI : public UserInterface
{
private:
	void ExitInput();
public:

	void UIMenu() override;
	void UIAdd(DatabaseAccessInterface& db) override;
	void UIList(DatabaseAccessInterface& db) override;
	void UIModify(DatabaseAccessInterface& db) override;
	void UIDelete(DatabaseAccessInterface& db) override;

	void ClearConsole();
	static int NubmerInput();
};

#endif
