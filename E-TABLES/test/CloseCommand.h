
#pragma once
#include "ICommand.h"

class CloseCommand : public ICommand
{
public:
    CloseCommand();
    void execute(System& receiver) override;
};