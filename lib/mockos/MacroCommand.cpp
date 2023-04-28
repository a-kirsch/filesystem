#include "../../include/mockos/MacroCommand.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include <iostream>
#include <memory>

using namespace std;

MacroCommand::MacroCommand() {};

int MacroCommand::addCommmand(AbstractCommand * command)
{
    if (command != nullptr)
    {
        commandList.push_back(command);
        return pass;
    }
    return nullptr_error;
}

int MacroCommand::setParsingStrategy(AbstractParsingStrategy * strategy)
{
    if (strategy != nullptr)
    {
        parsingStrategy = strategy;
        return pass;
    }
    return nullptr_error;
}

int MacroCommand::execute(std::string commands)
{
    vector<string> commandInputs = parsingStrategy->parse(commands);

    for (int i = 0; i < commandList.size(); ++i)
    {
        if (commandList[i]->execute(commandInputs[i]) != pass)
        {
            return failed_execution;
        }
    }
    return pass;
}



