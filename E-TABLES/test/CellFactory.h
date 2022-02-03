#pragma once

#include <string>
#include <vector>
#include "Cell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"

class CellFactory
{
private:
    static void removeWhiteSpaceInBeg(std::string& type); // removes whitespaces in the beginning
    static bool isString(const std::string& type);
    static bool isFormula(const std::string& type);
public:
    static Cell* make(std::string& type, std::vector<std::vector<Cell*>>& table);
};