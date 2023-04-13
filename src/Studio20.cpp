#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include "mockos/TextFile.h"
#include <iostream>

using namespace std;

int main()
{
    AbstractFile * fileT = new TextFile("test.txt");

    vector<char> characters;

    for (int i = 0; i < 26; ++i) {
        characters.push_back('a' + i); //Push the alphabet
    }

    PasswordProxy * proxy = new PasswordProxy(fileT, "testpassword");

    proxy->write(characters);

    vector<char> readContents = proxy->read();

    for (int i = 0; i < 26; ++i) { //Check if read and write are working properly
        cout << readContents[i];
    }

    cout << endl;

    cout << proxy->getName() << endl;

    BasicDisplayVisitor * visitor = new BasicDisplayVisitor();

    proxy->accept(visitor); //Check if the visitor/accept function is working

    return 0;
}