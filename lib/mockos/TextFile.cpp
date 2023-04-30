#include "../../include/mockos/AbstractFileVisitor.h"
#include "../../include/mockos/SimpleFileSystem.h"
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
    return pass; // note: in the future we should be checking if the copy worked
}

int TextFile::append(std::vector<char> addition) {
    for(int i = 0; i < addition.size(); ++i)
    {
        contents.push_back(addition[i]);
    }
    return pass;
}

std::vector<char> TextFile::read() {
    return contents;
}

void TextFile::accept(AbstractFileVisitor * abstractFileVisitor) {
    abstractFileVisitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string name)
{
    AbstractFile * copy = new TextFile(name + ".txt");
    copy->write(this->read());
    return copy;
}