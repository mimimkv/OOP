#pragma once
#include "Cell.h"

///Class holding cells with string values
class StringCell : public Cell
{
private:
    std::string value;
    bool isValidNumber() const; /// checks if the string contains a valid number
public:
    StringCell(const std::string& value, size_t length);
    void print(std::ostream& out = std::cout) const override;
    void save(std::ostream& out) const override;

    double getValue() const override; ///Converts string into a double, if it is not possible, returns 0
    Cell *clone(std::vector < std::vector <Cell *>>& table) override;

};