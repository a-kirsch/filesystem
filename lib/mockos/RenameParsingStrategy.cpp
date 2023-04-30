#include "../../include/mockos/RenameParsingStrategy.h"
#include <iostream>
#include <memory>

using namespace std;

std::vector<std::string> RenameParsingStrategy::parse(std::string input)
{
    int spaceIndex = input.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {

    }
    else
    {
        string secondCommand = input.substr(spaceIndex + 1);
        if (secondCommand == "-d")
        {

        }
    }
}


