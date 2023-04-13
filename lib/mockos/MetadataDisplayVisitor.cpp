#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/AbstractFile.h"


#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile * textFile) {
    cout << textFile->getName() << " " << textFile->getSize() << " text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile * imageFile) {
    cout << imageFile->getName() << " " << imageFile->getSize() << " image" << endl;
}

