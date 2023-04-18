#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

#include <map>
#include <string>
#pragma once

class CommandPrompt: public AbstractCommand {
public:
    std::map<std::string,AbstractCommand *>() map; // double check this syntax
    AbstractFileSystem * systemPtr;
    AbstractFileFactory * factoryPtr;

};