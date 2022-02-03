#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

/// abstract class for different types of cells
class Cell
{
protected:
    size_t length; ///<Amount of characters needed to print, basically the number of chars, Used for alignment when printing

public:
    Cell(size_t length);
    virtual ~Cell(); 
    virtual void print(std::ostream& out) const = 0; ///<Prints on the console
    virtual void save(std::ostream& file) const = 0;///<Saves in file
    virtual double getValue() const = 0;///<Returns a double number, the value of the cell
    virtual Cell* clone(std::vector<std::vector<Cell*>>& table) = 0; ///<Clones object
    size_t getLength() const; ///> Getter for the private member variable length
};