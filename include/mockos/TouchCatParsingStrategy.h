#pragma once
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include "AbstractCommand.h"
#include <vector>

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
    TouchCatParsingStrategy();
    virtual std::vector<std::string> parse(std::string);
};

