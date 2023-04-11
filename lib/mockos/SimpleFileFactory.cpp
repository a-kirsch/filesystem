#include "../../include/mockos/SimpleFileFactory.h"
#include "../../include/mockos/SimpleFileSystem.h"
//Not sure if the two below are the correct includes statements
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/TextFile.h"
#include <iostream>

using namespace std;

AbstractFile * SimpleFileFactory::createFile(string fileName) {
    string extensionType = fileName.substr(fileName.find('.') ); //Do I need to account for when non-file type is passed?

    if (extensionType == ".txt" )
    {
        AbstractFile * file = new TextFile(fileName);
        return file;
    }
    else if (extensionType == ".img")
    {
        AbstractFile * file = new ImageFile(fileName);
        return file;
    }
    return nullptr;

};