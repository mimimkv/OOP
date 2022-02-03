#pragma once
#include "ICommand.h"

///Class that supports the edit command
class EditCommand : public ICommand
{
public:
    EditCommand(const std::vector<std::string>& arguments);
    void execute(System& receiver) override;
};