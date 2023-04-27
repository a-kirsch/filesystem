#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class CopyCommand : public AbstractCommand {
    AbstractFileSystem * systemPtr;
public:
    CopyCommand(AbstractFileSystem *);
    virtual int execute(std::string);
    virtual void displayInfo();
    ~CopyCommand() =default;
};

