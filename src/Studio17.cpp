#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char * argv[] )
{
    SimpleFileSystem sfs;

    AbstractFile * fileA = new TextFile("fileA");
    AbstractFile * fileB = new TextFile("fileB");

    sfs.addFile("fileA", fileA);
    sfs.addFile("fileB", fileB);

    sfs.createFile("fileA"); //Test if the file system recognizes that this file already exists in the system
    sfs.createFile("alphabet.txt"); //How do we access a file we created?, I'm trying to append and read to that file but can't because we don't have a pointer to it

    vector<char> characters;

    for (int i = 0; i < 26; ++i) {
        characters.push_back('a' + i); //Push the alphabet
    }

    sfs.openFile("fileA")->append(characters);
    fileA->read();


    sfs.deleteFile("test"); //Checks if the file system recognizes this file never existed
    sfs.deleteFile("fileA");//Checks if the delete function recognized the file is open

    sfs.closeFile(fileA);

    return sfs.deleteFile("fileA"); //Deletes fileA
}