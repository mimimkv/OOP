#pragma once
#include <string>
#include <vector>

#include "Cell.h"
#include <cmath>

///Cell containing formula
/*!
 * Calculates the value of a formula.
 * Works with references to other cells and multiple parameters */
class FormulaCell: public Cell
{
private:
    std::vector<std::vector<Cell*>>& table;
    std::string expression;
    bool isValid = true;
    double value;

    bool isInteger(double n) const;
    double getNum(std::stringstream& str) ; //Get single formatted number
    double firstPriority(std::stringstream& str) ; //Power of number
    double secondPriority(std::stringstream& str) ; //Multiply and divide until possible
    double calculate(std::stringstream& str) ; //Sum and substract until possible. Works with more than 2 parameters
public:
    //Initialize the formula cell with a reference to a table and some expression to be calculated
    FormulaCell(const std::string& _expression, std::vector<std::vector<Cell*>>& _table);
    virtual Cell *clone(std::vector<std::vector<Cell*>>& _table);
    void print(std::ostream& out) const override;

    void save(std::ostream& out) const override;
    double getValue() const override;
};