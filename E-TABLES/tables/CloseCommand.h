
#pragma once
#include "ICommand.h"

///Class for the command that closes a file
class CloseCommand : public ICommand
{
public:
    CloseCommand();
    void execute(System& receiver) override;
};