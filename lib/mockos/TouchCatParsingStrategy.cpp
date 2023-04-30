#include "../../include/mockos/TouchCatParsingStrategy.h"
#include <iostream>
#include <memory>

using namespace std;

TouchCatParsingStrategy::TouchCatParsingStrategy() {};

std::vector<std::string> TouchCatParsingStrategy::parse(std::string file)
{
    vector<string> commandList;
    int spaceIndex = file.find(' ');
    if (spaceIndex != string::npos) //There is no space, the input is a single word
    {
        cout << "Incorrect arguments passed in." << endl;
    }
    else
    {
        commandList.push_back(file);
        commandList.push_back(file);
    }
    return commandList;
}


