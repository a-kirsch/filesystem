#pragma once
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include "AbstractCommand.h"
#include <vector>

class RenameParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string);
};

enum parsing_return_vals {
    invalid_arguments = 1
};