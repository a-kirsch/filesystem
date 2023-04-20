#include "../../include/mockos/CommandPrompt.h"
#include <iostream>
#include <sstream>

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
        if (input == "q")
        {
            return quit;
        }
        else if (input == "help")
        {
            listCommands();
        }
        else
        {
            if (input.find(" ") == string::npos)
            {
                if (map.find(input) != map.end() )
                {
                    //"Execute" the command, whatever that means
                }
                else
                {
                    cout << "Command does not exist." << endl;
                }
            }
            else
            {
                istringstream iss (input);
                string firstWord;
                string secondWord;
                if (iss >> firstWord)
                {
                    if (firstWord == "help")
                    {
                        if (iss >> secondWord)
                        {
                            if (map.find(secondWord) != map.end() )
                            {
                                //Call display info on it
                            }
                            else
                            {
                                cout << "Command does not exist." << endl;
                            }
                        }
                    }
                    else
                    {
                        if (map.find(firstWord) != map.end() )
                        {
                            //"Execute" the command, with the second word as the input.
                        }
                        else
                        {
                            cout << "Command does not exist.";
                        }
                    }
                }
            }

        }


    }
}
