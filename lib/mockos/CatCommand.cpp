#include "../../include/mockos/CatCommand.h"
#include "SimpleFileFactory.cpp"
#include <iostream>
#include <memory>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem * afs)
{
    systemPtr = afs;
}

void CatCommand::displayInfo()
{
    cout << "cat overwrites or concatenates a file, cat can be invoked with the command: 'cat <filename> -a' to add to "
            "the contents of an existing file or 'cat <filename>' to overwrite the current contents of a file." << endl;
}

int CatCommand::execute(string command)
{
    int spaceIndex = command.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {
        AbstractFile * file = systemPtr->openFile(command);
        if (file != nullptr)
        {
            cout << "Please input data to be appended to the file. Type ':wq' to save and quit or ':q' to quit"
                    "without saving.";
            string input;
            vector<char> fileChanges;
            while (getline(cin, input) )
            {
                if (input == ":q")
                {
                    return pass;
                }
                else if (input == ":wq")
                {
                    file->write(fileChanges);
                    return pass;
                }
                else
                {
                    fileChanges.push_back(input); //Input is a string, how do we write in the contents when fileChanges only accepts a char
                }
                cout << endl; //Is this how we reinsert a new line character?
            }
        }
        else
        {
            return file_does_not_exist;
        }
    }
    else
    {
        string secondCommand = command.substr(spaceIndex + 1);
        if (secondCommand == "-a")
        {
            string fileName = command.substr(0, spaceIndex - 1);
            AbstractFile * file = systemPtr->openFile(fileName);
            if (file != nullptr)
            {
                cout << "Please input data to be appended to the file. Type ':wq' to save and quit or ':q' to quit"
                        "without saving.";
                file->read(); //Is this the correct way to display a file's contents? I forget honestly
                string input;
                vector<char> fileChanges;
                while (getline(cin, input) )
                {
                    if (input == ":q")
                    {
                        return pass;
                    }
                    else if (input == ":wq")
                    {
                        file->append(fileChanges);
                        return pass;
                    }
                    else
                    {
                        fileChanges.push_back(input); //Input is a string, how do we write in the contents when fileChanges only accepts a char
                    }
                    cout << endl; //Is this how we reinsert a new line character?
                }
            }
            else
            {
                return file_does_not_exist;
            }
        }
        else
        {
            return invalid_arguments;
        }
    }
}