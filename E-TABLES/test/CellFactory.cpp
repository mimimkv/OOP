#include "CellFactory.h"
#include <sstream>


Cell* CellFactory::make(std::string& type, std::vector<std::vector<Cell*>>& table)
{
    removeWhiteSpaceInBeg(type);
    if (type.size() == 0)
        return nullptr;

    int intNum;
    double doubleNum;

    std::stringstream str(type);

    if (str >> doubleNum) // Double
    {
        return new DoubleCell(doubleNum, type.length());
    }

    str.seekg(0, std::ios::beg); // seek(0) !!!!

    if (str >> intNum) //Integer
    {
        return new IntCell(intNum, type.length());
    }

    if (isFormula(type)) // Formula
    {
        return new FormulaCell(table, type);
    }

    if (isString(type)) // String
    {
        type.erase(type.begin()); // deletes the quotes
        type.erase(type.end() - 1);

        return new StringCell(type, type.length());
    }
    return nullptr; // empty cell is a nullptr
}

bool CellFactory::isString(const std::string& type)
{
    return type[0] == '"' && type.back() == '"';
}

bool CellFactory::isFormula(const std::string& type)
{
    return type[0] == '=';
}

void CellFactory::removeWhiteSpaceInBeg(std::string& type)
{
    while(type[0] == ' ' || type[0] == '\t')
    {
        type.erase(type.begin());
    }
}
