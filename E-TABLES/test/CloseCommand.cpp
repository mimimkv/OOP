#include "CloseCommand.h"

CloseCommand::CloseCommand()
{

}


void CloseCommand::execute(System& receiver)
{
    receiver.close();
}