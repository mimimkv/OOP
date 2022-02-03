#include "commandLineParser.h"
#include "commandNotFoundException.h"
#include "invalidNumberOfArgumentsException.h"
#include "commandLineParser.h"
#include "PrintCommand.h"
#include "EditCommand.h"
#include "CloseCommand.h"
#include "OpenCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "HelpCommand.h"

bool CommandLineParser::isCapitalLetter(const char c)
{
    return c >= 'A' && c <= 'Z';
}

void CommandLineParser::toUpperCase(std::string& word)
{
    for (size_t i = 0; i < word.size(); ++i)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= ('a' - 'A');
    }
}

ICommand* CommandLineParser::parseCommand(std::string& line)
{
    std::vector<std::string> commandParts = split(line, ' ');
    std::string action = commandParts[0];
    CommandLineParser::toUpperCase(action);
    commandParts.erase(commandParts.begin());

    if (action == "OPEN")
    {
        if (commandParts.size() != 1)
            throw InvalidNumberOfArgumentsException();
        
        return new OpenCommand(commandParts);
    }
    else if (action == "CLOSE")
    {
        if (commandParts.size() != 0 && !commandParts[0].empty())
            throw InvalidNumberOfArgumentsException();

        return new CloseCommand();
    }
    else if (action == "EDIT")
    {
        if (commandParts.size() != 2)
            throw InvalidNumberOfArgumentsException();

        return new EditCommand(commandParts);
    }
    else if (action == "PRINT")
    {
        if (commandParts.size() != 0 && !commandParts[0].empty())
            throw InvalidNumberOfArgumentsException();

        return new PrintCommand();
    }
    else if (action == "SAVE")
    {
        if (commandParts.size() != 0 && !commandParts[0].empty())
            throw InvalidNumberOfArgumentsException();
        
        return new SaveCommand();
    }
    else if (action == "SAVEAS")
    {
       if (commandParts.size() != 1)
            throw InvalidNumberOfArgumentsException();

        return new SaveAsCommand(commandParts);
    }
    else if (action == "HELP")
    {
       if (commandParts.size() != 0 && !commandParts[0].empty())
            throw InvalidNumberOfArgumentsException();

        return new HelpCommand();
    }
    else 
    {
        throw CommandNotFoundException();
    }
    return nullptr;
}

std::vector<std::string> CommandLineParser::split(std::string& line, const char delimeter)
{
    std::vector<std::string> result;
    std::string word = "";
    bool openedQuotes = false;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == delimeter)
        {
            if (openedQuotes)
            {
                word.push_back(line[i]);
                continue;
            }
            if (!word.empty() && !openedQuotes)
                result.push_back(word);
            word = "";
        }
        else
        {
            if (line[i] == '"' && !openedQuotes)
                openedQuotes = true;
            else if (line[i] == '"' && openedQuotes)
                openedQuotes = false;
            word.push_back(line[i]);
        }
    }
    result.push_back(word);
    return result;
}
