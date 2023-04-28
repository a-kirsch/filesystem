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
    virtual int execute(std::string);
    int addCommmand(AbstractCommand *);
    int setParsingStrategy(AbstractParsingStrategy *);
    ~MacroCommand() =default;
};

enum macro_return_values {
    failed_execution = 1
};