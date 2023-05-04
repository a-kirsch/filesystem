#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/AbstractFile.h"



#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile * textFile) {
    string fileType = "text";
    int bufferspace = 20;
    cout << left << setw(bufferspace) << textFile->getName() << left << setw(bufferspace) << fileType << left << setw(bufferspace) << textFile->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile * imageFile) {
    string fileType = "image";
    int bufferspace = 20;
    cout << left << setw(bufferspace) << imageFile->getName() << left << setw(bufferspace) << fileType << left << setw(bufferspace) << imageFile->getSize() << endl;
}

