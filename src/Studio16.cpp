#include "mockos/TextFile.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<char> characters;

    for (int i = 0; i < 26; ++i) {
        characters.push_back('a' + i); //Push the alphabet
    }

    TextFile fileOne("testFile");

    cout << fileOne.getName() << endl; //File name is correctly working

    fileOne.write(characters);

    cout << fileOne.getSize() << endl; //Print the current size

    fileOne.read(); //Read out the alphabet

    fileOne.append(characters); //Add another alphabet

    cout << endl << fileOne.getSize() << endl; //Print the current size

    fileOne.read(); //Read out the alphabet

    char c = 'c';

    /*
     * Use an alias to the base class instead of declaring text Files
     */

    cout << endl << "Tests with an alias instead of an object: " << endl;

    AbstractFile * file;

    file = new TextFile("fileAlias");

    //Now call the function with a pointer instead of the object

    cout << file->getName() << endl;

    file->write(characters);

    cout << file->getSize() << endl; //Print the current size

    file->read(); //Read out the alphabet

    file->append(characters); //Add another alphabet

    cout << endl << file->getSize() << endl; //Print the current size

    file->read(); //Read out the alphabet

    return 0;
};