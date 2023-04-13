#pragma once
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem
{
    std::map<std::string, AbstractFile *> files;
    std::set<AbstractFile *> openFiles;
public:
    virtual int addFile(std::string, AbstractFile *);
    virtual int deleteFile(std::string);
    // virtual int createFile(std::string);
    virtual AbstractFile * openFile(std::string);
    virtual int closeFile(AbstractFile *);
};

enum simple_file_system_return_values {
    nullptr_error = -1,
    file_open = 2,
    file_already_exists = 3,
    file_already_closed = 4,
    file_does_not_exist = 5
};






