#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include<string>

class LSCommand : public AbstractCommand
{
    AbstractFileSystem * systemPtr;
public:
    LSCommand(AbstractFileSystem * );
    virtual int execute(std::string);
    virtual void displayInfo();
    ~LSCommand() =default;
};

enum ls_command {
    failure = 1,
    commandsPerLine = 2,
    incorrectArguments
};

