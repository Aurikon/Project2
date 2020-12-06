#include "FileInputOutput.h"

void FileInputOutput::ClearFile(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

bool FileInputOutput::IsFileEmpty(std::ifstream& is)
{
    return is.peek() == std::ifstream::traits_type::eof();
}