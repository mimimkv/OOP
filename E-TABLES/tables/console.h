#pragma once
#include "ICommand.h"
#include <string>
#include <vector>

///Class Console, has one static method run, which is called by the main function
class Console
{
public:
    static void run(System& receiver, std::istream& in = std::cin);
};