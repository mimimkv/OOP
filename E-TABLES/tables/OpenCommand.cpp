#include "OpenCommand.h"

OpenCommand::OpenCommand(const std::vector<std::string>& arguments)
{
    this->arguments = arguments;
}


void OpenCommand::execute(System& receiver)
{
    receiver.open(arguments[0]);
}