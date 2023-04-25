#pragma once
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class TouchCommand : public AbstractCommand {
    AbstractFileFactory * factoryPtr;
    AbstractFileSystem * systemPtr;
public:
    virtual int execute(std::string);
    virtual void displayInfo();
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    ~TouchCommand() =default;

};

enum add_file {
    success,
    failed_creation,
    repeat_file,
    passed_a_nullptr
};