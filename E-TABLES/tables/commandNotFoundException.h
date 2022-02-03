#pragma once
#include <exception>
#include <stdexcept>
#include <string>


///Class for exceptions when the command is unknown, inherits std::runtime_error
class CommandNotFoundException : public std::runtime_error
{
public:
    CommandNotFoundException();
};