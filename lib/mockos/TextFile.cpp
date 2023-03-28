#include "../../include/mockos/TextFile.h"

#include <string>
#include <iostream>

using namespace std;

TextFile::TextFile(std::string named): name(named) {};

unsigned int TextFile::getSize() {
    return contents.size();
}

std::string TextFile::getName() {
    return name;
}

int TextFile::write(std::vector<char> passedIn){
    contents = passedIn;
    return 0; // note: in the future we should be checking if the copy worked
}

int TextFile::append(std::vector<char> addition) {
    for(int i = 0; i < addition.size(); ++i)
    {
        contents.push_back(addition[i]);
    }
    return 0;
}

void TextFile::read() {
    for(int i = 0; i < contents.size(); ++i)
    {
        cout << contents[i] << endl; // note: never explicitly said to flush/print so maybe just cout and no endl?
    }
}

