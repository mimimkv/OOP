#include "StringCell.h"

StringCell::StringCell(const std::string& value, size_t length) : Cell(length)
{
    this->value = value;
}

void StringCell::print(std::ostream& out) const
{
    out << value;
}

void StringCell::save(std::ostream& out) const
{
    out << '"' << value << '"';
}

bool StringCell::isValidNumber() const
{
    // check is the string contains chars different from numbers
    int floatingPoint = 0;
    for (size_t i = 0; i < length; ++i)
    {
        if (value[0] == '-')
            continue;

        if (value[i] == '.')
        {
            floatingPoint++;
            continue;
        }

        if (value[i] < '0' || value[i] > '9' )
            return false;
    }

    if (floatingPoint > 1)
        return false;

    return true;
}

double StringCell::getValue() const
{
    double result = 0.0;
    if (isValidNumber())
    {
        result = std::stod(value); // converts string to double
    }
    
    return result;
}

Cell* StringCell::clone(std::vector<std::vector<Cell*>>& table)
{
    return new StringCell(*this);
}