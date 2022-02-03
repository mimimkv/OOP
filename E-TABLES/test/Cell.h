#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class Cell
{
protected:
    size_t length; /// length of the value in the cell

public:
    Cell(size_t length);
    virtual ~Cell(); 
    virtual void print(std::ostream& out) const = 0;
    virtual void save(std::ostream& file) const = 0;
    virtual double getValue() const = 0;
    virtual Cell* clone(std::vector<std::vector<Cell*>>& table) = 0;
    size_t getLength() const;
};