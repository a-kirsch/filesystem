#include "../../include/mockos/SimpleFileSystem.h"
//Not sure if the two below are the correct includes statements
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/TextFile.h"
#include <set>
#include <iostream>

using namespace std;

// Commented out for step 5 of studio 18
//int SimpleFileSystem::createFile(string fileName)
//{
//    if (files.find(fileName) != files.end() )
//    {
//        cout << "File already exists." << endl;
//        return file_already_exists;
//    }
//
//    string extensionType = fileName.substr(fileName.find('.') ); //Do I need to account for when non-file type is passed?
//
//    if (extensionType == ".txt" )
//    {
//        AbstractFile * file = new TextFile(fileName);
//        files.insert(std::pair<string, AbstractFile *>(fileName, file) );
//        return pass;
//    }
//    else if (extensionType == ".img")
//    {
//        AbstractFile * file = new ImageFile(fileName);
//        files.insert(std::pair<string, AbstractFile *>(fileName, file) );
//        return pass;
//    }
//    return invalid_file_type;
//
//}


int SimpleFileSystem::addFile(string fileName, AbstractFile * abstractFile)
{
    if (files.find(fileName) != files.end() )
    {
        cout << "File already exists in map." << endl;
        return file_already_exists;
    }
    if (abstractFile == nullptr)
    {
        cout << "Null Pointer Error" << endl;
        return nullptr_error;
    }
    files.insert(std::pair<string, AbstractFile *>(fileName, abstractFile) );
    return pass;
}

AbstractFile * SimpleFileSystem::openFile(string fileName) //Ask TA if opening the file is anything other than placing it in the openFile set
{
    if (files.find(fileName) != files.end() )
    {
       if (openFiles.find(files.at(fileName) ) == openFiles.end() ) //Check if the file is already open (look in openFiles)
       {
            cout << "File open" << endl;
            openFiles.insert(files.at(fileName) );
            return files.at(fileName);
       }
    }
    return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile * file)
{
    if (openFiles.find(file) != openFiles.end() )
    {
        openFiles.erase(file);
        return pass;
    }
    cout << "File is already closed." << endl;
    return file_already_closed;
}

int SimpleFileSystem::deleteFile(string fileName)
{
    if (files.find(fileName) != files.end() )
    {
        if (openFiles.find(files.at(fileName)) == openFiles.end() )
        {
            delete files.at(fileName);
            files.erase(fileName);
            return pass;
        }
        else
        {
            cout << "File is currently open." << endl;
            return file_open;
        }
    }
    else
    {
        cout << "File does not exist."  << endl;
        return file_does_not_exist;
    }
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> names;
    for (auto const &pair: files) {
        names.insert(pair.first);
    }
    return names;
}

