#include "SaveCommand.h"

SaveCommand::SaveCommand()
{

}


void SaveCommand::execute(System& receiver)
{
    receiver.save();
}