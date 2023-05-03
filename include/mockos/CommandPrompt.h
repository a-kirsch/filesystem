#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


#include <map>
#include <string>
#pragma once

class CommandPrompt {
    std::map<std::string,AbstractCommand *> map;
    AbstractFileSystem * systemPtr;
    AbstractFileFactory * factoryPtr;
public:
    CommandPrompt();
    void setFileSystem( AbstractFileSystem *);
    void setFileFactory( AbstractFileFactory *);
    int addCommand(std::string, AbstractCommand *);
    int run();
    ~CommandPrompt(); //impliment with map
protected:
    void listCommands();
    std::string prompt();
};

enum command_return_values
{
    success_cp = 0,
    commandTaken = 1,
    quit = 2
};