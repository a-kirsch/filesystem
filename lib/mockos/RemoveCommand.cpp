#include "../../include/mockos/RemoveCommand.h"
#include "SimpleFileSystem.cpp"
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

RemoveCommand::RemoveCommand(string fileName) {
    input = fileName;
}

int RemoveCommand::execute(string fileName) {
    if(deleteFile(input)==success)
    {
        return success;
    }
    else{
        return failure_to_remove;
    }
}

void RemoveCommand::displayInfo() {
    cout << "rm is used to remove files. It can be invoked with the command 'rm <filename>'" << endl;
}

