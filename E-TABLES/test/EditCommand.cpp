#include "EditCommand.h"

EditCommand::EditCommand(const std::vector<std::string>& arguments)
{
    this->arguments = arguments;
}


void EditCommand::execute(System& receiver)
{
    receiver.edit(arguments[0], arguments[1]);
}