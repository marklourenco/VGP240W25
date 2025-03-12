#pragma once

#include "Command.h"

class CmdPostProcessingBeginDraw : public Command
{
public:
    const char* GetName() override
    {
        return "PostProcessingBeginDraw";
    }

    const char* GetDescription() override
    {
        return
            "PostProcessingBeginDraw()"
            "\n"
            "- Initiates rendering to the render tatget instead of the main screen";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdPostProcessingEndDraw : public Command
{
public:
    const char* GetName() override
    {
        return "PostProcessingEndDraw";
    }

    const char* GetDescription() override
    {
        return
            "PosProcessingEndDraw()"
            "\n"
            "- Draws the render target back to the main screen\n"
            "- Applies set effects to the image";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdPostProcessingSetEffectType : public Command
{
public:
    const char* GetName() override
    {
        return "PostProcessingSetEffectType";
    }

    const char* GetDescription() override
    {
        return
            "SetProcessing(effectType)"
            "\n"
            "- Sets the effect to apply to the image\n"
            "- none, monochrome, invert, mirror, blur"
            "- colomaskr, colormaskg, colormaskb"
            "- sepia, wave, fisheye";
    }

    bool Execute(const std::vector<std::string>& params) override;
};