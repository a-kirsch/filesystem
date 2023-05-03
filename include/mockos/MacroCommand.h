#pragma once
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include "AbstractCommand.h"
#include <vector>

class MacroCommand : public AbstractCommand {
    std::vector<AbstractCommand *> commandList;
    AbstractParsingStrategy * parsingStrategy;

public:
    MacroCommand();
    MacroCommand(AbstractFileSystem *a);
    AbstractFileSystem *afs;
    virtual int execute(std::string);
    int addCommand(AbstractCommand *);
    int setParseStrategy(AbstractParsingStrategy *);
    virtual void displayInfo();
    ~MacroCommand() =default;

};

enum macro_return_values {
    failed_execution = 1
};