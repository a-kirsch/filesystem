#include "../../include/mockos/DisplayCommand.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include "../../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <memory>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem * afs)
{
    systemPtr = afs;
}

void DisplayCommand::displayInfo()
{
    cout << "display opens a file and displays its contents, display can be invoked with the command: 'ds <filename> -d' to "
            "display just the data of a file or 'ds <filename>' to display the formatted contents of a file." << endl;
}

int DisplayCommand::execute(std::string input)
{
    int spaceIndex = input.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {
        AbstractFile * file = systemPtr->openFile(input);
        if (file != nullptr)
        {
            BasicDisplayVisitor * visitor = new BasicDisplayVisitor();
            file->accept(visitor);
            systemPtr->closeFile(file);
            return pass;
        }
        else
        {
            return nullptr_error;
        }
    }
    else
    {
        string secondCommand = input.substr(spaceIndex + 1);
        if (secondCommand == "-d")
        {
            string fileName = input.substr(0, spaceIndex);
            AbstractFile * file = systemPtr->openFile(fileName);
            if (file != nullptr)
            {
                vector<char> contents = file->read();
                for (char character: contents)
                {
                    cout << character;
                }
                cout << endl;
                systemPtr->closeFile(file);
                return pass;
            }
            else
            {
                return nullptr_error;
            }
        }
        else
        {
            return invalid_arguments;
        }
    }
}
