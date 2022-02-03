#include "HelpCommand.h"

HelpCommand::HelpCommand()
{

}


void HelpCommand::execute(System& receiver)
{
    receiver.help();
}