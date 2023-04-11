#include "../../include/mockos/ImageFile.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ImageFile::ImageFile(string named) : name(named),size(0) {}

void ImageFile::read() {
    for(int h = size - 1; h >= 0; --h)
    {
        for(int w = 0; w < size; ++w)
        {
            cout << contents[h*size + w];
        }
        cout << endl;
    }
}

int ImageFile::write(vector<char> parameter) {
    if (parameter.size() == 0)
    {
        return size_mismatch;
    }
    size = parameter[parameter.size() - 1]- '0'; // calling the .size member variable but we need to create an instance of the object
    if ( (parameter.size() - 1) / size != size )
    {
        return size_mismatch;
    }
    for(int i = 0; i < parameter.size(); ++i) {
        if (i != parameter.size() - 1) {
            if (parameter[i] != 'X' && parameter[i] != ' ') {
                contents.clear();
                size = 0;
                return bad_char_type; // nonzero return value for bad char, to be replaced w enums when we use them later
            }
            contents.push_back(parameter[i]);
        }
    }
    return pass;
}

int ImageFile::append(vector<char>) {
    return invalid_operation;
}

unsigned int ImageFile::getSize() {
    return contents.size();
}

string ImageFile::getName() {
    return name;
}