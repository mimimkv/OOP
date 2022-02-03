#include "SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(const std::vector<std::string>& arguments)
{
    this->arguments = arguments;
}


void SaveAsCommand::execute(System& receiver)
{
    receiver.saveas(arguments[0]);
}