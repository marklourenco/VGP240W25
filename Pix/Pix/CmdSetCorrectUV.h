#pragma once

#include "Command.h"

class CmdSetCorrectUV : public Command
{
public:
    const char* GetName() override
    {
        return "SetCorrectUV";
    }

    const char* GetDescription() override
    {
        return
            "SetCorrectUV(enable)\n"
            "\n"
            "- sets the correct UV coordinates for the object";
    }

    bool Execute(const std::vector<std::string>& params) override;
};