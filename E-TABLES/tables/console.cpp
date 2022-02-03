#include "Console.h"
#include "CommandNotFoundException.h"
#include "InvalidNumberOfArgumentsException.h"
#include "CommandLineParser.h"
#include<iostream>

void Console::run(System& receiver, std::istream& in)
{
    std::string input;
    while(true)
    {
        getline(in, input);
        if (!input.compare("exit") || !in)
            return;
        try
        {
            ICommand* cmd = CommandLineParser::parseCommand(input);
            cmd->execute(receiver);

            delete cmd;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}