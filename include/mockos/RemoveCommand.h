#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include<string>

class RemoveCommand : public AbstractCommand
{
    AbstractFileSystem * systemPtr;
public:
    RemoveCommand(AbstractFileSystem * );
    virtual int execute(std::string);
    virtual void displayInfo();
    ~RemoveCommand() =default;
};

enum remove_command {
    success = 0,
    failure_to_remove = 1
};
