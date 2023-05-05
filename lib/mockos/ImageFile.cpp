#include "../../include/mockos/AbstractFileVisitor.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ImageFile::ImageFile(string named) : name(named),size(0) {}

std::vector<char> ImageFile::read() {
    return contents;
}

int ImageFile::write(vector<char> parameter) {
    contents.clear();
    size = parameter.back();
    int intSize = (int)(size-48);
    if(parameter.size() != intSize * intSize +1)
    {
        return size_mismatch;
    }
    for(int i = 0; i < intSize * intSize; i++)
    {
        if(parameter[i] != 'X' && parameter[i] != ' ')
        {
            contents.clear();
            size = 0;
            return bad_char_type;
        }
        contents.push_back(parameter[i]);
    }
    return pass;
    //    if (parameter.size() == 0)
//    {
//        return size_mismatch;
//    }
//    size = parameter[parameter.size() - 2]- '0'; // object
//    parameter.pop_back();
//    parameter.pop_back();
//    if ( parameter.size() -1 == size*size )
//    {
//        for(int i = 1; i < parameter.size(); ++i) {
//            if (i != parameter.size() - 1) {
//                if (parameter[i] != 'X' && parameter[i] != ' ') {
//                    contents.clear();
//                    size = 0;
//                    return bad_char_type; // nonzero return value for bad char, to be replaced w enums when we use them later
//                }
//            }
//        }
//        try{
//            contents = parameter;
//            return pass;
//        }
//        catch(...) {
//            cout<<"write failed" << endl;
//            return 6; // change
//        }
//    }
//    else{
//        return size_mismatch;
//    }
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

void ImageFile::accept(AbstractFileVisitor * abstractFileVisitor) {
    abstractFileVisitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string name)
{
    AbstractFile* copy = new ImageFile(name + ".img");
    vector<char> newContents = this->read();
    newContents.push_back(size); //Push back the size of each row
    copy->write(newContents);
    return copy;
}