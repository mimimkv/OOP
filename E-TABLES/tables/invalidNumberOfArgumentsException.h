#pragma once
#include <stdexcept>


///This class assures that the number of arguments of a particular command are correct
class InvalidNumberOfArgumentsException : public std::runtime_error
{
public:
    InvalidNumberOfArgumentsException();
};