#include "../../include/mockos/PasswordProxy.h"
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile * file, std::string pass): abstractFile(file),password(pass) {};

PasswordProxy::~PasswordProxy()
{
    delete abstractFile;
}

std::string PasswordProxy::passwordPrompt()
{
    string userPassword;
    cout << "Please input the password: ";
    cin >> userPassword;
    return userPassword;
}

bool PasswordProxy::checkPassword(std::string word)
{
    if (word == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<char> PasswordProxy::read()
{
    string userInput = passwordPrompt();
    if (checkPassword(userInput) )
    {
        return abstractFile->read();
    }
    else
    {
        std::vector<char> emptyVector;
        return emptyVector;
    }
}

int PasswordProxy::write(std::vector<char> passedIn)
{
    string userInput = passwordPrompt();
    if (checkPassword(userInput) )
    {
        return abstractFile->write(passedIn);
    }
    else
    {
        return incorrectPassword;
    }
}

int PasswordProxy::append(std::vector<char> addition)
{
    string userInput = passwordPrompt();
    if (checkPassword(userInput) )
    {
        return abstractFile->append(addition);
    }
    else
    {
        return incorrectPassword;
    }
}

unsigned int PasswordProxy::getSize()
{
    return abstractFile->getSize();
}

std::string PasswordProxy::getName()
{
    return abstractFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor * abstractFileVisitor)
{
    string userInput = passwordPrompt();
    if (checkPassword(userInput) )
    {
        abstractFile->accept(abstractFileVisitor);
    }
}











