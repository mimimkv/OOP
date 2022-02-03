#pragma once

#include <string>
#include <vector>
#include "Cell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"

/**
 * Factory method is a creational design pattern, i.e., related to object creation. 
 * In Factory pattern, we create object without exposing the creation logic to client 
 * and the client use the same common interface to create new type of object.
 * The idea is to use a static member-function (static factory method) which creates & 
 * returns instances, hiding the details of class modules from user. 
 * A factory pattern is one of the core design principles to create an object, allowing 
 * clients to create objects of a library(explained below) in a way such that it doesn’t have 
 * tight coupling with the class hierarchy of the library.
 **/
class CellFactory
{
private:
    static void removeWhiteSpaceInBeg(std::string& type); /// removes whitespaces in the beginning
    static bool isString(const std::string& type);
    static bool isFormula(const std::string& type);
public:
    static Cell* make(std::string& type, std::vector<std::vector<Cell*>>& table);
};