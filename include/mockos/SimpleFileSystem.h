#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem
{
    std::map<std::string, AbstractFile *> files;
    std::set<AbstractFile *> openFiles;
    virtual int addFile(std::string, AbstractFile *);
    virtual int createFile(std::string);
    virtual int deleteFile(std::string);
    virtual AbstractFile * openFile(std::string);
    virtual int closeFile(AbstractFile *);
};





