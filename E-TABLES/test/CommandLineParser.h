#pragma once 
#include "ICommand.h"
#include <string>

class CommandLineParser
{
public:
    static bool isCapitalLetter(const char c);
    static void toUpperCase(std::string& word);
    static ICommand* parseCommand(std::string& line);
    static std::vector<std::string> split(std::string& line, const char delimeter);

};