#pragma once
#include "AbstractFile.h"
#include <string>
#include <vector>

class ImageFile: public AbstractFile{
public:
    ImageFile(std::string);
    std::vector<char> read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
    void accept(AbstractFileVisitor *);
private:
    std::string name;
    std::vector<char> contents;
    char size;
};
