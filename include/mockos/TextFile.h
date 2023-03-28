#include "AbstractFile.h"
#include <string>
#include <vector>

class TextFile: public AbstractFile{
public:
    TextFile(std::string);
    void read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
private:
    std::vector<char> contents;
    std::string name;
};