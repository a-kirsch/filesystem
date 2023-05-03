#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/AbstractFile.h"



#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile * textFile) {
    string fileType = "text";
    int bufferspace1 = 20 - textFile->getName().length();
    int bufferspace2 = 20 - fileType.length();
    cout << textFile->getName() << setw(bufferspace1) << fileType << setw(bufferspace2) << textFile->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile * imageFile) {
    string fileType = "image";
    int bufferspace1 = 20 - imageFile->getName().length();
    int bufferspace2 = 20 - fileType.length();
    cout << imageFile->getName() << setw(bufferspace1) << fileType << setw(bufferspace2) << imageFile->getSize() << endl;
}

