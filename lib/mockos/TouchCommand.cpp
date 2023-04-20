#include "../../include/mockos/TouchCommand.h"
#include "SimpleFileFactory.cpp"
#include <iostream>
#include <memory>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * afs, AbstractFileFactory * aff) {
    factoryPtr = aff;
    systemPtr = afs;
}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string filename) {
    AbstractFile * af = factoryPtr->createFile(filename);
    if(af==nullptr)
    {
        cout << "Failed to create file :(" << endl;
        return failed_creation;
    }
    else
    {
        int added = systemPtr->addFile(filename, af);

        if(added == file_already_exists)
        {
            cout << "The file you tried to add already exists in the file system :(" << endl;
            systemPtr->deleteFile(filename);
            return repeat_file;
        }
        else if(added == nullptr_error)
        {
            cout << "Couldn't add file because a null pointer was passed :(" << endl;
            return passed_a_nullptr;
        }
            return success;
    }
}