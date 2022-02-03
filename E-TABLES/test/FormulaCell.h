#pragma once
#include "Cell.h"
#include <vector>

//works with reference to a table, bacause in order to calculate its value, we have to know the others
class FormulaCell : public Cell
{
private:
    std::vector<std::vector<Cell*>>& table;
    std::string expression;

    double calculate() const; // calculates the value of the expression
    double getNum(const std::string&); // returns a particular num from the table

    bool isValid = true;
    bool isRecursive();
    bool noDivByZero(); // check if divides by zero
public:
    FormulaCell(std::vector<std::vector<Cell*>>& table, const std::string& expression);
    void print(std::ostream& out) const override;
    void save(std::ostream& out) const override;
    double getValue() const override;
    Cell* clone(std::vector<std::vector<Cell*>>& table) override;

};


