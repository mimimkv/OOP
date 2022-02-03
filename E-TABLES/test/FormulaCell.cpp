#include "FormulaCell.h"

FormulaCell::FormulaCell(std::vector<std::vector<Cell*>>& _table, 
                const std::string& expression) : Cell(0), table(_table)
{
    this->expression = expression;
    
}

void FormulaCell::print(std::ostream& out) const
{
    //todo
    if (!isValid)
    {
        out << "ERROR";
    }
}

void FormulaCell::save(std::ostream& out) const
{
    out << expression;
}

double FormulaCell::getValue() const
{
    //todo
    return 0;
}

Cell* FormulaCell::clone(std::vector < std::vector <Cell *>>& table)
{
    return new FormulaCell(table, expression);
}