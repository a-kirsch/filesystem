#include <string>

#pragma once

class AbstractCommand {
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
    virtual ~AbstractCommand() = default;
};