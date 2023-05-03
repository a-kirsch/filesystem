#include "../../include/mockos/CatCommand.h"
#include "../../include/mockos/SimpleFileFactory.h"
#include "../../include/mockos/SimpleFileSystem.h"
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
            cout << "Please input data to override the file. Type ':wq' to save and quit or ':q' to quit "
                    "without saving.";
            string input;
            string total;
            while (input != ":q" && input != ":wq")
            {
                total += input;
                total += "\n";
                getline(cin, input);
            }
            if (input == ":q")
            {
                systemPtr->closeFile(file);
                return pass;
            }
            else
            {
                vector<char> fileChanges;
                for(int i = 0; i < total.length(); ++i)
                {
                    fileChanges.push_back(total.at(i));
                }
                if (file->write(fileChanges) == pass)
                {
                    systemPtr->closeFile(file);
                    return pass;
                }
                else
                {
                    systemPtr->closeFile(file);
                    return failed_addition;
                }
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
            string fileName = command.substr(0, spaceIndex);
            AbstractFile * file = systemPtr->openFile(fileName);
            if (file != nullptr)
            {
                cout << "Please input data to be appended to the file. Type ':wq' to save and quit or ':q' to quit"
                        "without saving.";
                vector<char> fileContents = file->read(); //Display the current file contents
                for (char character: fileContents)
                {
                    cout << character;
                }
                cout << endl;
                string input;
                string total;
                while (input != ":q" && input != ":wq")
                {
                    total += input;
                    total += "\n";
                    getline(cin, input);
                }
                if (input == ":q")
                {
                    systemPtr->closeFile(file);
                    return pass;
                }
                else
                {
                    vector<char> fileChanges;
                    for(int i = 0; i < total.length(); ++i)
                    {
                        fileChanges.push_back(total.at(i));
                    }
                    if (file->append(fileChanges) == pass)
                    {
                        systemPtr->closeFile(file);
                        return pass;
                    }
                    else
                    {
                        systemPtr->closeFile(file);
                        return failed_addition;
                    }
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