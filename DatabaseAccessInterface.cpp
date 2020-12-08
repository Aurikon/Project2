#include "DatabaseAccessInterface.h"

void DatabaseAccessInterface::ClearFile(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

bool DatabaseAccessInterface::IsFileEmpty(std::ifstream& is)
{
    return is.peek() == std::ifstream::traits_type::eof();
}