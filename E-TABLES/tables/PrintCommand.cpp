#include "PrintCommand.h"

PrintCommand::PrintCommand()
{
	
}

void PrintCommand::execute(System& receiver)
{
    receiver.print();
}