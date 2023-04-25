#include "../../include/mockos/LSCommand.h"
#include "SimpleFileFactory.cpp"
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
    cout << "ls lists all available commands, ls can be invoked with the command ls " << endl;
}

int LSCommand::execute(string input)
{
    set<string> fileNames = systemPtr->getFileNames();
    if (input == "-m")
    {
        for (string file: fileNames)
        {
            int bufferSpace = 30 - file.length();
            int bufferSpace2 = 0;
            int fileSize = rand()%10+1;
            string fileType;
            string extensionType = file.substr(file.find('.') );
            if (extensionType == ".txt")
            {
                fileType = "text";
                bufferSpace2 = 25;
                cout << file << setw(bufferSpace) << fileType << setw(bufferSpace2) << fileSize << endl;
            }
            else
            {
                fileType = "image";
                bufferSpace2 = 23;
                cout << file << setw(bufferSpace) << fileType << setw(bufferSpace2) << fileSize << endl;
            }
        }
        return pass; //May need to change this so I open and close the file type (use an auto iterator)
    }
    else if (input == "")
    {
        auto outputIter = fileNames.begin();
        for (int i = 0; i < fileNames.size(); ++i)
        {
            if ( i % commandsPerLine == 0)
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
        return pass;
    }
    else
    {
        return incorrectArguments;
    }
}

