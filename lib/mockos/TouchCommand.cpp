#include "../../include/mockos/TouchCommand.h"
#include "../../include/mockos/SimpleFileFactory.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include <iostream>
#include <memory>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * afs, AbstractFileFactory * aff) {
    factoryPtr = aff;
    systemPtr = afs;
}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>, or "
            "touch <filename> -p to create a password protected file" << endl;
}

int TouchCommand::execute(string input) {
    int spaceIndex = input.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {
        AbstractFile * af = factoryPtr->createFile(input);
        if(af==nullptr)
        {
            cout << "Failed to create file :(" << endl;
            return failed_creation;
        }
        else
        {
            int added = systemPtr->addFile(input, af);

            if(added == file_already_exists)
            {
                cout << "The file you tried to add already exists in the file system :(" << endl;
                systemPtr->deleteFile(input);
                return file_already_exists;
            }
            else if(added == nullptr_error)
            {
                cout << "Couldn't add file because a null pointer was passed :(" << endl;
                return nullptr_error;
            }
            return pass;
        }
    }
    else
    {
        string command = input.substr(spaceIndex + 1);
        if (command == "-m")
        {
            AbstractFile * af = factoryPtr->createFile(input);
            if(af==nullptr)
            {
                cout << "Failed to create file :(" << endl;
                return failed_creation;
            }
            else
            {
                cout << "What do you want password for your file to be?";
                string password;
                cin >> password;
                PasswordProxy * proxy = new PasswordProxy(af, password);
                int added = systemPtr->addFile(input, proxy);
                if(added == file_already_exists)
                {
                    cout << "The file you tried to add already exists in the file system :(" << endl;
                    systemPtr->deleteFile(input);
                    return file_already_exists;
                }
                else if(added == nullptr_error)
                {
                    cout << "Couldn't add file because a null pointer was passed :(" << endl;
                    return nullptr_error;
                }
                return pass;
            }
        }
        else
        {
            return invalid_arguments;
        }
    }
}