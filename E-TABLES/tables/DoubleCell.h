#pragma once
#include "Cell.h"

///Class holding cells with floating values
class DoubleCell : public Cell
{
private:
    double value;
public:
    DoubleCell(double value, size_t length);
    void print(std::ostream& out = std::cout) const override;
    void save(std::ostream& out) const override;
    double getValue() const override;
    Cell *clone(std::vector < std::vector <Cell *> > &_table) override;

};