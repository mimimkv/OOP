#include "Cell.h"

Cell::Cell(size_t length)
{
    this->length = length;
}

size_t Cell::getLength() const
{
    return length;
}

Cell::~Cell()
{
    
}