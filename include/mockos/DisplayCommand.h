#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class DisplayCommand : public AbstractCommand {
    AbstractFileSystem * systemPtr;
public:
    DisplayCommand(AbstractFileSystem *);
    virtual int execute(std::string);
    virtual void displayInfo();
    ~DisplayCommand() =default;
};

