#include "../../include/mockos/CommandPrompt.h"
#include <iostream>

using namespace std;

CommandPrompt::CommandPrompt(): systemPtr(nullptr), factoryPtr(nullptr) {};

void CommandPrompt::setFileSystem(AbstractFileSystem * fileSystem)
{
    systemPtr = fileSystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * fileFactory)
{
    factoryPtr = fileFactory;
}

int CommandPrompt::addCommand(std::string commandName, AbstractCommand * command)
{
    if (map.find(commandName) == map.end())
    {
        std::pair <string ,AbstractCommand * > commandPair;
        commandPair = make_pair(commandName, command);
        map.insert(commandPair);
    }
    else
    {
        return commandTaken;
    }
}

void CommandPrompt::listCommands()
{
   for (auto i: map)
   {
       cout << i.first << endl;
   }
}

string CommandPrompt::prompt()
{
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command" << endl;
    cout << "$   ";
    string userInput;
    getline(cin, userInput);
    return userInput;
}

int CommandPrompt::run()
{
    while (true)
    {
        string input = prompt();

    }
}
