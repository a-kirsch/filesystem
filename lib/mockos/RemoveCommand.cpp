#include "../../include/mockos/RemoveCommand.h"
#include "SimpleFileSystem.cpp"
#include <iostream>
#include <memory>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem * fileSystem)
{
    systemPtr = fileSystem;
}

int RemoveCommand::execute(string fileName)
{
    if(systemPtr->deleteFile(fileName)==success)
    {
        return success;
    }
    else
    {
        return failure_to_remove;
    }
}

void RemoveCommand::displayInfo()
{
    cout << "rm is used to remove files. It can be invoked with the command 'rm <filename>'" << endl;
}

