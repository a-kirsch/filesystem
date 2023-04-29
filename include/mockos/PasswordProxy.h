#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>


class PasswordProxy : public AbstractFile {
    AbstractFile * abstractFile;
    std::string password;
public:
    PasswordProxy(AbstractFile *, std::string);
    ~PasswordProxy();
    std::vector<char> read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
    void accept(AbstractFileVisitor *);
    virtual AbstractFile* clone(AbstractFile*, AbstractFileSystem*);
protected:
    std::string passwordPrompt();
    bool checkPassword(std::string);
};

enum password_return_values
{
    incorrectPassword = 1
};

