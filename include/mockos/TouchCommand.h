#pragma once
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "PasswordProxy.h"

class TouchCommand : public AbstractCommand {
    AbstractFileFactory * factoryPtr;
    AbstractFileSystem * systemPtr;
public:
    virtual int execute(std::string);
    virtual void displayInfo();
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    ~TouchCommand() =default;

};

enum add_return_values {
    failed_creation = 1
};