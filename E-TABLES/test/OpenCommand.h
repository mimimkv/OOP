#pragma once
#include "ICommand.h"

class OpenCommand : public ICommand
{
public:
    OpenCommand(const std::vector<std::string>& arguments);
    void execute(System& receiver) override;
};