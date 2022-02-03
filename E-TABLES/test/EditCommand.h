#pragma once
#include "ICommand.h"

class EditCommand : public ICommand
{
public:
    EditCommand(const std::vector<std::string>& arguments);
    void execute(System& receiver) override;
};