#include "../../include/mockos/BasicDisplayVisitor.h"

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile * textFile) {
    vector<char> copyContents = textFile->read();

    for(int i = 0; i < copyContents.size(); ++i)
    {
        cout << copyContents[i];
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile * imageFile) {
    vector<char> copyContents = imageFile->read();
    int size = sqrt(copyContents.size());
    for(int h = size - 1; h >= 0; --h)
    {
        for(int w = 0; w < size; ++w)
        {
            cout << copyContents[h*size + w];
        }
        cout << endl;
    }

    cout << endl;
}

