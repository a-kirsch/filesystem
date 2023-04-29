#pragma once
#include "AbstractFile.h"
#include <string>
#include <vector>

class TextFile: public AbstractFile{
public:
    TextFile(std::string);
    std::vector<char> read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
    void accept(AbstractFileVisitor *);
    virtual AbstractFile* clone(AbstractFile*, AbstractFileSystem*);
private:
    std::vector<char> contents;
    std::string name;
};