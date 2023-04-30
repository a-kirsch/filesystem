#include "../../include/mockos/CopyCommand.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include "../../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <memory>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem * afs)
{
    systemPtr = afs;
}

void CopyCommand::displayInfo()
{
    cout << "copy copies a file that currently exists in the file system and adds the new file to the file system, "
            "copy can be invoked with the command: 'cp <file_to_copy> <new_name_with_no_extension>'" << endl;
}

int CopyCommand::execute(std::string input)
{
    int spaceIndex = input.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {
        cout << "Incorrect arguments for the copy command. You must pass in a file to copy and a new name for the copy" << endl;
        return invalid_arguments;
    }
    else
    {
        string newFileName = input.substr(spaceIndex + 1);
        string fileToCopy = input.substr(0, spaceIndex);

        AbstractFile * file = systemPtr->openFile(fileToCopy);

        if (file != nullptr)
        {
            AbstractFile * copy = file->clone("clone");
            return pass;
        }
        else
        {
            cout << "File to copy failed to open." << endl;
            return file_open;
        }
    }
}