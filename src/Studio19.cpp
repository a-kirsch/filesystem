#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main() {

    AbstractFile * fileT = new TextFile("test.txt");
    AbstractFile * fileI = new ImageFile("test.img");

    vector<char> words = fileT->read();
    vector<char> pictures = fileI->read();

    words.push_back('c');
    pictures.push_back('X');

    fileT->write(words);
    fileI->write(pictures);

    vector<char> new_words = fileT->read();
    vector<char> new_pictures = fileI->read();

    for (char c: new_words)
    {
        cout << c << endl;
    }

    for (char c: new_pictures)
    {
        cout << c << endl;
    }

    return 0;
}
