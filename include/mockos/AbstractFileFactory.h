#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
    virtual AbstractFile * createFile(std::string filename) =0;
};