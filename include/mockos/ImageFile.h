#include <string>
#include <vector>
#include "AbstractFile.h"


class ImageFile : public AbstractFile {
    std::string name;
    std::vector<char> contents;
    char size;
    ImageFile(std::string);
    void read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
};