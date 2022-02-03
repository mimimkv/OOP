#include "IntCell.h"


IntCell::IntCell(int value, size_t length) : Cell(length)
{
    this->value = value;
}

void IntCell::print(std::ostream& out) const
{
    out << value;
}

void IntCell::save(std::ostream& out) const
{
    out << value;
}

double IntCell::getValue() const
{
    return value;
}

Cell* IntCell::clone(std::vector<std::vector<Cell*>>& table) 
{ 
    return new IntCell(*this); 
}