#include "DoubleCell.h"

DoubleCell::DoubleCell(double value, size_t length) : Cell(length)
{
    this->value = value;
}

void DoubleCell::print(std::ostream& out) const
{
    out << value;
}

void DoubleCell::save(std::ostream& out) const
{
    out << value;
}

double DoubleCell::getValue() const
{
    return value;
}

Cell* DoubleCell::clone(std::vector<std::vector<Cell*>>& table)
{
    return new DoubleCell(*this);
}