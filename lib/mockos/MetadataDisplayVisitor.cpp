#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/AbstractFile.h"



#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile * textFile) {
    string fileType = "text";
    int bufferspace = 20 - textFile->getName().length();
    cout << textFile->getName() << setw(bufferspace) << fileType << setw(bufferspace) << textFile->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile * imageFile) {
    string fileType = "image";
    int bufferspace = 20 - imageFile->getName().length();
    cout << imageFile->getName() << setw(bufferspace) << fileType << setw(bufferspace) << imageFile->getSize() << endl;
}

