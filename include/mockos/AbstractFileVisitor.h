#pragma once
#include <vector>
#include <string>
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor{
public:
     virtual void visit_TextFile(TextFile *) = 0;
     virtual void visit_ImageFile(ImageFile *) = 0;

};