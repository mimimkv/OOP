#pragma once
#include "ICommand.h"

class PrintCommand : public ICommand
{
public:
    PrintCommand();
    void execute(System& receiver) override;
};