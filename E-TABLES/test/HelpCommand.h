#pragma once
#include "ICommand.h"

class HelpCommand : public ICommand
{
public:
    HelpCommand();
    void execute(System& receiver) override;
};