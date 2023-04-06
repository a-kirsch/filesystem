#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char * argv[] )
{
    string file = "dog.txt";
    string extensionType = file.substr(file.find('.') );
    cout << extensionType << endl;
}