#pragma once
#include "ICommand.h"

class SaveCommand : public ICommand
{
public:
    SaveCommand();
    void execute(System& receiver) override;
};