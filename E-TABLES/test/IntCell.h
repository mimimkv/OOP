#pragma once
#include "Cell.h"

class IntCell : public Cell
{
private:
    int value;

public:
    IntCell(int value, size_t length);
    void print(std::ostream& out = std::cout) const override;
    void save(std::ostream& out) const override;
    double getValue() const override;
    Cell* clone(std::vector<std::vector<Cell*>>& table) override;
};