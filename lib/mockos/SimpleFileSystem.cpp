#include "../../include/mockos/SimpleFileSystem.h"
//Not sure if the two below are the correct includes statements
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/TextFile.h"
#include <set>
#include <iostream>
using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile * abstractFile)
{
    if (files.find(fileName) != files.end() )
    {
        cout << "File already exists in map." << endl;
        return -1; //Add an enum
    }
    if (abstractFile == nullptr)
    {
        cout << "Null Pointer Error" << endl;
        return -1; //Add an enum
    }
    files.insert(std::pair<string, AbstractFile *>(fileName, abstractFile) );
    return 0; //Add an enum
}

int SimpleFileSystem::createFile(string fileName)
{
    if (files.find(fileName) != files.end() )
    {
        cout << "File already exists." << endl;
        return -1; //Add an enum
    }
    string extensionType = fileName.substr(fileName.find('.') ); //Do I need to account for when non-file type is passed?

    if (extensionType == ".txt" )
    {
        AbstractFile * file = new TextFile(fileName);
        files.insert(std::pair<string, AbstractFile *>(fileName, file) );
    }
    else
    {
        AbstractFile * file = new ImageFile(fileName);
        files.insert(std::pair<string, AbstractFile *>(fileName, file) );
    }
    return 0; //Add an enum
}

AbstractFile * SimpleFileSystem::openFile(string fileName)
{
    if (files.find(fileName) != files.end() )
    {
       if (openFiles.find(files.at(fileName) ) == openFiles.end() ) //Check if the file is already open (look in openFiles)
       {
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
        return 0; //Add an enum
    }
    return -1; //Add an enum
}

int SimpleFileSystem::deleteFile(string fileName)
{
    if (files.find(fileName) != files.end() )
    {
        if (openFiles.find(files.at(fileName)) != openFiles.end() )
        {
            files.erase(fileName);
            delete &fileName;
        }
        else
        {
            return -1; //file is open error - Add an enum
        }
    }
    else
    {
        return -1; //File never existed error - Add an enum
    }
}

