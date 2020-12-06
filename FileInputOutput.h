#ifndef FILEINPUTOUTPUT_H
#define FILEINPUTOUTPUT_H

#include <fstream>
#include <string>

class FileInputOutput
{
public:
	virtual void ToFile() = 0;
	virtual void FromFile() = 0;

protected:
	virtual void ClearFile(std::string fileName);
	virtual bool IsFileEmpty(std::ifstream& is);
};

#endif 
