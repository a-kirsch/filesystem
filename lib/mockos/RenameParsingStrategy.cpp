#include "../../include/mockos/RenameParsingStrategy.h"
#include <iostream>
#include <memory>

using namespace std;

std::vector<std::string> RenameParsingStrategy::parse(std::string fileAndName)
{
    vector<string> commandList;
    int spaceIndex = fileAndName.find(' ');
    if (spaceIndex == string::npos) //There is no space, the input is a single word
    {
        cout << "Incorrect arguments passed in." << endl;
    }
    else
    {
        string file = fileAndName.substr(0, spaceIndex);
        commandList.push_back(fileAndName);
        commandList.push_back(file);
    }
    return commandList;
}


