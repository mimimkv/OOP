#pragma once
#include "ICommand.h"

class SaveAsCommand : public ICommand
{
public:
    SaveAsCommand(const std::vector<std::string>& arguments);
    void execute(System& receiver) override;
};