#include "../../include/mockos/LSCommand.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include "../../include/mockos/MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * afs)
{
    systemPtr = afs;
};

void LSCommand::displayInfo()
{
    cout << "ls lists all available commands, ls can be invoked with the command 'ls' " << endl;
}

int LSCommand::execute(string input)
{
    set<string> fileNames = systemPtr->getFileNames();
    if (input == "-m")
    {
        for (string file: fileNames)
        {
            string fileType;
            string extensionType = file.substr(file.find('.') );
            if (extensionType == ".txt")
            {
                MetadataDisplayVisitor * visitor = new MetadataDisplayVisitor();
                visitor->visit_TextFile(); //needs parameter
            }
            else
            {
                MetadataDisplayVisitor * visitor = new MetadataDisplayVisitor();
                visitor->visit_ImageFile();
            }
        }
        return pass; //May need to change this so I open and close the file type (use an auto iterator)
    }
    else if (input == "")
    {
        auto outputIter = fileNames.begin();
        for (int i = 0; i < fileNames.size(); ++i)
        {
            if ( i % commands_per_line == 0)
            {
                int bufferSpace = 30 - outputIter->length();
                cout << * outputIter << setw(bufferSpace);
            }
            else
            {
                cout << * outputIter << endl;
            }
            outputIter++;
        }
        cout << endl;
        return pass;
    }
    else
    {
        return invalid_arguments;
    }
}

