#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class CatCommand : public AbstractCommand {
    AbstractFileSystem * systemPtr;
public:
    CatCommand(AbstractFileSystem *);
    virtual int execute(std::string);
    virtual void displayInfo();
    ~CatCommand() =default;
};

